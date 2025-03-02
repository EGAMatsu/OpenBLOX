
// XML file loader
// - Adapted from OpenRblx

// Limitations:
// - No refs (properties of type Instance will not be filled)
// - No support for "Complex" types (hopefully these are only present in '05 models)

#include <stdio.h>
#include "CoreEngine/Node/nodes.h"
#include "ThirdParty/xml/include/xml.h"
#include <dirent.h>

#include <vector>

#include "xml.h"

#define parseRBXL(f) parseRBXMf(f, true)
#define parseRBXM(f) parseRBXMf(f, false)
Node *parseRBXMf(FILE *f, bool place);
Node *parseRBXMx(struct xml_document *doc);

Node *parseRBXMf(FILE *f, bool place)
{
    print_message("STARTING TO PARSE.\n");
    // TODO switch to use some kind of streaming reader
    print_message("Building XML Tree.\n");
    struct xml_document *doc = xml_open_document(f);
    print_message("Done.\n");

    printf("Building datamodel...\n");
    Node *dataModel = parseRBXMx(doc);
    printf("done\n");

    xml_document_free(doc, true);

    return dataModel;
}

static char *xml_easy_string(struct xml_string *str)
{
    uint8_t *buf = (uint8_t*)malloc(xml_string_length(str) + 1);
    xml_string_copy(str, buf, xml_string_length(str));
    buf[xml_string_length(str)] = 0;
    return (char*)buf;
}

// Serialization:
// This is how we get the values from the file and into the values in the data model.
// Every class should have some serialization data associated with it.
// This is a listing of the properties of the class that can be saved/loaded and their types.
enum SerializationType {
    Serialize_bool,
    Serialize_float,
    Serialize_token,
    Serialize_int,
    Serialize_CoordinateFrame,
    Serialize_string,
    Serialize_Vector3,
    Serialize_Color3,
    Serialize_Ref,
    Serialize_double,
};

struct Serialization {
    SerializationType type;
    const char *name;
    void *val;
};

struct SerializeInstance {
    std::vector<Serialization> serializations;
};

static void xmlserialize_vector3_DS(Vector3 *v, struct xml_node *node)
{
    for (int i = 0; i < xml_node_children(node); i++)
    {
        struct xml_node *child = xml_node_child(node, i);
        char *propName = xml_easy_string(xml_node_name(child));
        char *prop = xml_easy_string(xml_node_content(child));
        float propI = atof(prop);

        switch (*propName)
        {
            case 'X': v->x = propI; break;
            case 'Y': v->y = propI; break;
            case 'Z': v->z = propI; break;
        }

        free(propName);
        free(prop);
    }
}

void xmlserialize_vector3_v3(void* val, struct xml_node *child)
{
    xmlserialize_vector3_DS((Vector3*)val, child);
}

// We don't have these classes yet, but they will be here eventually...
static void xmlserialize_coordinateframe(CoordinateFrame *cf, struct xml_node *node)
{
    for (int i = 0; i < xml_node_children(node); i++)
    {
        struct xml_node *child = xml_node_child(node, i);
        char *propName = xml_easy_string(xml_node_name(child));
        char *prop = xml_easy_string(xml_node_content(child));
        float propI = atof(prop);

        switch (*propName)
        {
            case 'X': cf->X = propI; break;
            case 'Y': cf->Y = propI; break;
            case 'Z': cf->Z = propI; break;
            case 'R':
            {
                int next = atoi(propName + 1);
                switch (next)
                {
                    case 0: cf->R00 = propI; break;
                    case 1: cf->R01 = propI; break;
                    case 2: cf->R02 = propI; break;
                    case 10: cf->R10 = propI; break;
                    case 11: cf->R11 = propI; break;
                    case 12: cf->R12 = propI; break;
                    case 20: cf->R20 = propI; break;
                    case 21: cf->R21 = propI; break;
                    case 22: cf->R22 = propI; break;
                }
            }
        }

        free(propName);
        free(prop);
    }
}
/*
static void xmlserialize_color3(Color3 *c, struct xml_node *node)
{
    for (int i = 0; i < xml_node_children(node); i++)
    {
        struct xml_node *child = xml_node_child(node, i);
        char *propName = xml_easy_string(xml_node_name(child));
        char *prop = xml_easy_string(xml_node_content(child));
        float propI = atof(prop);

        switch (*propName)
        {
            case 'R': c->R = propI; break;
            case 'G': c->G = propI; break;
            case 'B': c->B = propI; break;
        }

        free(propName);
        free(prop);
    }
}*/

// Token (enum) system
// TODO make enums not hardcoded(how?)
static const char *tokenPropNames[] = {
    "shape",
    "Controller",
    "Type",
    "Constraint",
    "SurfaceInput",
    "PostureXML",
};

static const char *tokenTables[][50] = {
    { "Ball", "Block", "Cylinder", "Wedge", "CornerWedge", NULL }, // shape
    { "None", "Player", "KeyboardLeft", "KeyboardRight", "Joypad1", "Joypad2", "Chase", "Flee", NULL }, //Controller
    { "Smooth", "Glue", "Weld", "Studs", "Inlet", "Universal", "Hinge", "Motor", "SteppingMotor", "Unjoinable", "SmoothNoOutlines", "Bumps", "Spawn", NULL }, // Type
    { "None", "Hinge", "Motor", "SteppingMotor", NULL }, //Constraint
    { "NoInput", "LeftTread", "RightTread", "Steer", "Throttle", "Updown", "Action1", "Action2", "Action3", "Action4", "Action5", "Sin", "Constant", NULL }, // SurfaceInput
    { "Stand", NULL } // PostureXML
};

static void xmlserialize_token(int *val, char *prop, char *propName)
{
    int size = sizeof(tokenPropNames) / sizeof(char *);

    char *endptr;
    unsigned long asNumber = strtoul(prop, &endptr, 10);

    if (endptr != prop)
    {
        *val = asNumber;
        return;
    }

    printf("serialize_token: prop %s, propName %s, asNumber %ld.\n", prop, propName, asNumber);

    if (strstr(propName, "SurfaceInput"))
    {
        propName = "SurfaceInput";
    }
    else if (strstr(propName, "Surface"))
    {
        propName = "Type";
    }
    else if (strstr(propName, "Constraint"))
    {
        propName = "Constraint";
    }

    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(propName, tokenPropNames[i])) index = i;
    }

    for (int i = 0; ; i++)
    {
        if (tokenTables[index][i] == NULL) break;
        if (!strcmp(tokenTables[index][i], prop)) *val = i;
    }

    if (*val == 0 && index == -1 && strlen(prop) > 1)
    {
        print_message("token not serialized: %s (propname %s)\n", prop, propName);
    }
}

// Load a property of an instance from the xml data using the serialize instance
static void serialize(SerializeInstance *inst, char *prop, char *propName, struct xml_node *child, Node *ret)
{
    char *type = xml_easy_string(xml_node_name(child));
    bool done = false;

    if (!strcmp(type, "Complex"))
    {
        print_message("TODO complex\n");
        // TODO complex
    }

    for (int j = 0; j < inst->serializations.size(); j++)
    {
        if (!strcmp(inst->serializations[j].name, propName) ||

             // Aliases for property names
            (!strcmp(inst->serializations[j].name, "CFrame") && !strcmp(propName, "CoordinateFrame")) ||
            (!strcmp(inst->serializations[j].name, "RotVelocity") && !strcmp(propName, "RotVel")) ||
            (!strcmp(inst->serializations[j].name, "Locked") && !strcmp(propName, "CanSelect")) ||
            (!strcmp(inst->serializations[j].name, "ClassName") && !strcmp(propName, "Keywords")))
        {
            done = true;
            void *val = inst->serializations[j].val;
            switch (inst->serializations[j].type)
            {
                case Serialize_bool:
                {
                    *(bool*)val = !strcmp(prop, "true");
                } break;
                case Serialize_float:
                {
                    *(float*)val = atof(prop);
                } break;
                case Serialize_token:
                {
                    xmlserialize_token((int*)val, prop, propName);
                } break;
                case Serialize_int:
                {
                    *(int*)val = atoi(prop);
                } break;
                case Serialize_string:
                {
                    char *str = (char*)malloc(strlen(prop) + 1);
                    memcpy(str, prop, strlen(prop));
                    str[strlen(prop)] = 0;
                    *(char**)val = str;
                } break;
                case Serialize_Vector3:
                {
                    xmlserialize_vector3_v3(val, child);
                } break;
                case Serialize_CoordinateFrame:
                {
                    xmlserialize_coordinateframe((CFrame*)val, child);
                } break;
                /*case Serialize_Color3:
                {
                    xmlserialize_color3(val, child);
                } break;
                case Serialize_Vector3:
                {
                    xmlserialize_vector3(val, child);
                } break;*/
                case Serialize_double:
                {
                    *(double*)val = atof(prop);
                } break;
                //case Serialize_Ref:
                //{
                //    refsInst->refCount++;
                //    refsInst->refs = realloc(refsInst->refs, refsInst->refCount * sizeof(XMLRef));
                //    refsInst->refs[refsInst->refCount - 1] = (XMLRef){prop, val};
                //} break;
                default:
                {
                    print_message("serialization type %d not implemented.\n", inst->serializations[j].type);
                } break;
            }
            break;
        }
    }

    if (!done)
    {
        print_message("ns: %s %s\n", propName, prop);
    }

}

static int loadCount = 0;
static int loadedCount = 0;

// pName: property name - the name in the roblox engine
// sName: struct name - the name of the class member that corresponds to the value
// cName: class name - the name of the class
#define serialize_atomic(type, pName, obj, sName) inst.serializations.push_back((Serialization){Serialize_##type, pName, &obj->sName})

// Load a model or part from XML
static Node *loadModelPartXML(struct xml_node *node)
{
    Node *newNode;
    char *className = xml_easy_string(xml_node_attribute_content(node, 0));
    struct xml_node *propertyNode = xml_node_child(node, 0);
    SerializeInstance inst;

    if (!strcmp(className, "Part"))
    {
        Part *newPart = new Part;

        serialize_atomic(Vector3, "size", newPart, scale);
        serialize_atomic(int, "BrickColor", newPart, color);
        serialize_atomic(token, "Shape", newPart, shape);
        serialize_atomic(CoordinateFrame, "CFrame", newPart, cf);

        newNode = newPart;
    }
    else if (!strcmp(className, "SpawnLocation"))
    {
        SpawnLocation *newSL = new SpawnLocation;
    
        serialize_atomic(Vector3, "size", newSL, scale);
        serialize_atomic(int, "BrickColor", newSL, color);
        serialize_atomic(token, "Shape", newSL, shape);
        serialize_atomic(CoordinateFrame, "CFrame", newSL, cf);

        newNode = newSL;
    }
    else
    {
        newNode = new Node;
        //print_message("Create placeholder for %s\n", className);
    }

    for (int i = 0; i < xml_node_children(propertyNode); i++)
    {
        struct xml_node *child = xml_node_child(propertyNode, i);

        char *type = xml_easy_string(xml_node_name(child));
        if (!strcmp(type, "Feature"))
        {
            char *pName = xml_easy_string(xml_node_attribute_content(child, 0));
            if (!strcmp(pName, "Card"))
            {
                //print_message("No support for %s Feature\n", "Card");
                free(pName);
                free(type);
                continue;
            }
            free(pName);
            for (int j = 0; j < xml_node_children(child); j++)
            {
                struct xml_node *child2 = xml_node_child(child, j);
                char *propName = xml_easy_string(xml_node_attribute_content(child2, 0));
                char *prop = xml_easy_string(xml_node_content(child2));
                serialize(&inst, prop, propName, child2, newNode);//, refsInst);
                free(propName);
                free(prop);
            }
        }
        else
        {
            char *propName = xml_easy_string(xml_node_attribute_content(child, 0));
            char *prop = xml_easy_string(xml_node_content(child));
            serialize(&inst, prop, propName, child, newNode);//, refsInst);
            free(propName);
            free(prop);
        }
        free(type);
    }

    loadCount += xml_node_children(node);

    for (int i = 0; i < xml_node_children(node); i++)
    {
        loadedCount++;
        //printf("Loading %d/%d\n", loadedCount, loadCount);
        struct xml_node *child = xml_node_child(node, i);
        char *type = xml_easy_string(xml_node_name(child));
        if (!strcmp(type, "Item"))
        {
            Node *childNode = loadModelPartXML(child);
            if (childNode) childNode->SetParent(newNode); 
        }
        free(type);
    }

    return newNode;
}

Node *parseRBXMx(struct xml_document *doc)
{
    Node *dataModel = new Node;

    struct xml_node *root = xml_document_root(doc);

    loadedCount = 0;
    loadCount = xml_node_children(root);
    for (size_t i = 0; i < xml_node_children(root); i++)
    {
        loadedCount++;
        //printf("Loading %d/%d\n", loadedCount, loadCount);
        struct xml_node *child = xml_node_child(root, i);
        char *name = (char *)xml_easy_name(child);
        if (!strcmp(name, "Item")) {
            Node *newNode = loadModelPartXML(child);//, &refsInst);
            if (newNode) newNode->SetParent(dataModel);
        }
        free(name);
    }
    

    return dataModel;
}

static int crop, cropCurrent;
static bool fileIsSelected;

void levelLoaderMenu(Node **dataModel, Node **character);
void loadFiles(Node **dataModel, Node **character)  {
    levelLoaderMenu(dataModel, character);
}

