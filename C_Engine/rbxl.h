
// XML file loader
// - Adapted from OpenRblx

Node *loadRBXLFile(const char *filename);
Node *loadRBXLFilef(FILE *f);
Node *loadRBXLFilex(struct xml_document *doc);

Node *loadRBXLFile(const char *filename)
{
    FILE *f = fopen(filename, "rb");

    if (!f)
    {
        char text[256];
        sprintf(text, "Unable to open file \"%s\".", filename);
        print_message(text);
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

