
// XML file loader
// - Adapted from OpenRblx

#include <stdio.h>
#include "CoreEngine/Node/nodes.h"
#include "ThirdParty/xml/include/xml.h"

Node *loadRBXLFile(const char *filename);
Node *loadRBXLFilef(FILE *f);
Node *loadRBXLFilex(struct xml_document *doc);

Node *loadRBXLFile(const char *filename)
{
    FILE *f = fopen(filename, "rb");

    if (!f)
    {
        //print_message("Unable to open file \"");
        //print_message(filename);
        //print_message("\"\n");
        return NULL;
    }

    Node *dataModel = loadRBXLFilef(f);

    //fclose(f); xml.c closes the file automatically

    return dataModel;
}

Node *loadRBXLFilef(FILE *f)
{
    struct xml_document *doc = xml_open_document(f);

    Node *dataModel = loadRBXLFilex(doc);

    xml_document_free(doc, true);

    return dataModel;
}

Node *loadRBXLFilex(struct xml_document *doc)
{
    Node *dataModel = new Node;

    //print_message("TODO: parse xml");

    return dataModel;
}

