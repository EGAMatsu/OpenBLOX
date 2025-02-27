
// XML file loader
// - Adapted from OpenRblx

#include <stdio.h>
#include "CoreEngine/Node/nodes.h"
#include "ThirdParty/xml/include/xml.h"
#include <dirent.h>

#include <nds.h>
#include <filesystem.h>
#include <fat.h>

#define parseRBXL(f) parseRBXMf(f, true)
#define parseRBXM(f) parseRBXMf(f, false)
Node *parseRBXMf(FILE *f, bool place);
Node *parseRBXMx(struct xml_document *doc);

Node *parseRBXMf(FILE *f, bool place)
{
    // TODO switch to use some kind of streaming reader
    struct xml_document *doc = xml_open_document(f);

    Node *dataModel = parseRBXMx(doc);

    xml_document_free(doc, true);

    return dataModel;
}

Node *parseRBXMx(struct xml_document *doc)
{
    Node *dataModel = new Node;

    //print_message("TODO: parse xml");

    return dataModel;
}

static int crop, cropCurrent;
static bool fileIsSelected;

void loadFiles(Node **dataModel, Node **character)
{
    const char *mapFile[256];
    int mapLength = 0;

    /* Start up fs */
	//if (fatInitDefault()) {
		DIR *pdir;
		struct dirent *pent;

		//Try this again.
		pdir=opendir("/OpenBLOX");

		if (pdir){

			while ((pent=readdir(pdir))!=NULL) {
	    		if( !(strcmp(".", pent->d_name) == 0 || strcmp("..", pent->d_name) == 0) )
	        	{
					if(pent->d_type == DT_DIR) {
						iprintf("Dir: [%s]\n", pent->d_name);
					}
					else {
						iprintf("%s\n", pent->d_name);
						mapFile[mapLength] = strdup(pent->d_name);
						mapLength++;
					}
				}
			}
			printf("\e[1;1H\e[2J"); 
			
			/* Manager variables */
			int pressed = 0;
			int held = 0;
			bool update = true;
			int j = 0;
			bool isUpPressed = false;
			bool isDownPressed = false;
			bool isRightPressed = false;
			
			int fSelectNumb = 0;
			
			/* Primitive file select */
			while (!fileIsSelected) {
				scanKeys();
				pressed = keysDownRepeat();
				held = keysHeld();
				
				//Print filelist
				if (j == 0) {
					printf("-= Map Select =- Crop is %d\n", crop);
				}
				int lowerMapLen = 1;
				for (int i = 0; i <= mapLength; i++) {
					if (j <= mapLength-lowerMapLen) {
						if (j == fSelectNumb) {
							printf("-> ");
						}
						printf("%s\n", mapFile[i]);
						j += 1;
					}
				}
				//Is r down?
				if ( (held & KEY_R) && (isRightPressed == false) ) {
					printf("\e[1;1H\e[2J"); 
					j = 0;
					isRightPressed = true;
					cropCurrent++;
				}
				if ( !(held & KEY_R) && (isRightPressed == true) ) {
					isRightPressed = false;
				}

				if (cropCurrent > 8) {
					cropCurrent = 0;
				}
				crop = cropCurrent*8;

				//Is cursor going up?
				if ( (held & KEY_UP) && (isUpPressed == false) ) {
					printf("\e[1;1H\e[2J"); 
					j = 0;
					isUpPressed = true;
					fSelectNumb--;
				}
				if ( !(held & KEY_UP) && (isUpPressed == true) ) {
					isUpPressed = false;
				}
				
				//Is cursor going down?
				if ( (held & KEY_DOWN) && (isDownPressed == false) ) {
					printf("\e[1;1H\e[2J"); 
					j = 0;
					isDownPressed = true;
					fSelectNumb++;
				}
				if ( !(held & KEY_DOWN) && (isDownPressed == true) ) {
					isDownPressed = false;
				}
				
				//Wrap the selection Number.
				if (fSelectNumb < 0) {
					fSelectNumb = mapLength-lowerMapLen;
				}
				if (fSelectNumb > mapLength-lowerMapLen) {
					fSelectNumb = 0;
				}
				
				//Is cursor going down?
				if ( (held & KEY_A) ) {
					printf("\e[1;1H\e[2J"); 
					fileIsSelected = true;
				}
			}
			/* Load Map */
			char filePath[256];
			sprintf(filePath, "%s/%s", "/OpenBLOX", mapFile[fSelectNumb]);
			FILE *fp = fopen(filePath, "r");
			*dataModel = parseRBXL(fp);
			
			/* Load player model */
			char filePathChar[256];
			sprintf(filePath, "%s/%s", "/OpenBLOX", "content/fonts/character.rbxm");
			FILE *fpchar = fopen(filePath, "r");
			*character = parseRBXM(fpchar);
			
			closedir(pdir);
		} else {
			iprintf ("opendir() failure; terminating\n");
		}
		
//	} else {
//		iprintf("fatInit failure\n");
//	}

}

