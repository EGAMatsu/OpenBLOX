/*
    OpenBlox Loader stuff
*/


void levelLoaderMenu(Node **dataModel, Node **character, int argc, char **argv) {
    /* Load Map */
    char filePath[1024];
    char *filePathToLoad = argv[1];

    if (argc < 2)
    {
        filePathToLoad = "./test.rbxl";
    }
    sprintf(filePath, "%s/%s", filePathForProgram, filePathToLoad);
    print_message("Loading map. (%s)\n", filePathToLoad);
    FILE *fp = fopen(filePath, "r");
    if (fp != nullptr) {
        print_message("Parsing XML Data.\n(File is %s.)\n", filePath);
        *dataModel = parseRBXL(fp);
                
        /* Load player model */
        print_message("Loading character.\n");
        char filePathChar[2048];
        sprintf(filePath, "%s/%s", filePathForProgram, "content/fonts/character.rbxm");
        printf(filePath);
        FILE *fpchar = fopen(filePath, "r");
        if (fp != nullptr) {
            print_message("Parsing XML Data.\n");
            *character = parseRBXM(fpchar);
        } else {
            print_message("CHARACTER DOESN'T EXIST.\n");
        }
    } else {
        print_message("MAP DOESN'T EXIST.\n");
    }
}
