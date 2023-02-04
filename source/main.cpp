#include <nds.h>
#include <filesystem.h>
#include <fat.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "tinyxml2.h"

#include "classes.h"
#include <vector>
#include <iostream>
#include <random>
#include <chrono>

Part part[8192];
int partCount;

int spawnLocation_X[255], spawnLocation_Y[255], spawnLocation_Z[255];
int spawnCount = 0;

void drawCylinder(float x, float y, float z, float radius, float height, float depth, int r, int g, int b, float alpha) {
	/*
	Renders a 7-sided cylinder that is scaled from the center outwards.
	*/
	
	const int NUM_SIDES = 7;
	const float angleStep = 2 * M_PI / NUM_SIDES;

	// Set up material properties
	int r31, g31, b31;
	int r31s, g31s, b31s;
	r31 = (r/16);
	g31 = (g/16);
	b31 = (b/16);
	
	r31s = (r/16)*0.5;
	g31s = (g/16)*0.5;
	b31s = (b/16)*0.5;
	
	glMaterialf(GL_AMBIENT, RGB15(r31s,g31s,b31s));
	glMaterialf(GL_DIFFUSE, RGB15(r31,g31,b31));
	
	glPolyFmt(POLY_ALPHA(31-int(alpha*31)) | POLY_CULL_BACK  | POLY_FORMAT_LIGHT0);

	// Draw the sides of the cylinder
	for (int i = 0; i < NUM_SIDES; ++i) {
		float angle1 = i * angleStep;
		float angle2 = (i + 1) * angleStep;
		float x1 = x + radius * cos(angle1);
		float z1 = z + radius * sin(angle1);
		float x2 = x + radius * cos(angle2);
		float z2 = z + radius * sin(angle2);
		
		glBegin(GL_QUAD);
			glNormal3f(cos(angle1), 0, sin(angle1));
			glVertex3f(x1, y - height, z1);
			glVertex3f(x2, y - height, z2);
			glVertex3f(x2, y + height, z2);
			glVertex3f(x1, y + height, z1);
		glEnd();
	}
	
	// Draw the top and bottom of the cylinder
	glPolyFmt(POLY_ALPHA(31-int(alpha*31)) | POLY_CULL_NONE  | POLY_FORMAT_LIGHT0);
	glBegin(GL_TRIANGLES);
		glNormal3f(0, 1, 0);
		for (int i = 0; i < NUM_SIDES; ++i) {
			float angle1 = i * angleStep;
			float angle2 = (i + 1) * angleStep;
			float x1 = x + radius * cos(angle1);
			float z1 = z + radius * sin(angle1);
			float x2 = x + radius * cos(angle2);
			float z2 = z + radius * sin(angle2);

			glVertex3f(x, y + height, z);
			glVertex3f(x1, y + height, z1);
			glVertex3f(x2, y + height, z2);
		}
	glEnd();
	glBegin(GL_TRIANGLES);
		glNormal3f(0, 1, 0);
		for (int i = 0; i < NUM_SIDES; ++i) {
			float angle1 = i * angleStep;
			float angle2 = (i + 1) * angleStep;
			float x1 = x + radius * cos(angle1);
			float z1 = z + radius * sin(angle1);
			float x2 = x + radius * cos(angle2);
			float z2 = z + radius * sin(angle2);

			glVertex3f(x, y - height, z);
			glVertex3f(x1, y - height, z1);
			glVertex3f(x2, y - height, z2);
		}
	glEnd();
}

//Map stuff
std::vector<Object> objects;
std::vector<Model> models;
std::vector<Part> parts;
std::vector<Humanoid> humanoids;
std::vector<Script> scripts;
int object[8192];

//Prototypes
void processWorkspace(tinyxml2::XMLElement *workspace);
void processItem(tinyxml2::XMLElement *item, int parent_id);
void processModel(tinyxml2::XMLElement *model);

//Non containers
void processPart(tinyxml2::XMLElement *part, int parent_id);
void processSpawn(tinyxml2::XMLElement *part, int parent_id);
void processHumanoid(tinyxml2::XMLElement *humanoid);
void processScript(tinyxml2::XMLElement *script);

void parseRBXL(FILE *filename) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename);
	fclose(filename);

    tinyxml2::XMLElement* ROBLOX = doc.FirstChildElement("roblox");
    tinyxml2::XMLElement* workspace = ROBLOX->FirstChildElement("Item");
    
    while (strcmp(workspace->Attribute("class"), "Workspace") != 0 && workspace != nullptr) {
        workspace = workspace->NextSiblingElement("Item");
    }
    if (workspace != nullptr && strcmp(workspace->Attribute("class"), "Workspace") == 0) {
        processWorkspace(workspace);
    }
}

void parseRBXM(FILE *filename) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename);

    tinyxml2::XMLElement* ROBLOX = doc.FirstChildElement("roblox");
    tinyxml2::XMLElement* workspace = ROBLOX->FirstChildElement("Item");
    
    while (strcmp(workspace->Attribute("class"), "Model") != 0 && workspace != nullptr) {
        workspace = workspace->NextSiblingElement("Item");
    }
    if (workspace != nullptr && strcmp(workspace->Attribute("class"), "Model") == 0) {
        processWorkspace(workspace);
    }
}

void processWorkspace(tinyxml2::XMLElement *workspace) {
    tinyxml2::XMLElement* child = workspace->FirstChildElement("Item");
    int parent_id = -1; // workspace has no parent
    while (child != nullptr) {
        processItem(child, parent_id);
        child = child->NextSiblingElement("Item");
    }
}

void processModel(tinyxml2::XMLElement *model, int parent_id) {
    printf("Found a Model!\n");
    Model m;
    m.id = objects.size();
    m.parent_id = parent_id;
    objects.push_back(m);
    models.push_back(m);
	
	tinyxml2::XMLElement* properties = model->FirstChildElement("Properties");
	
	/* Get the Models name */
		tinyxml2::XMLElement* nameString = properties->FirstChildElement("string");
		if ((strcmp(nameString->Attribute("name"), "Name") != 0) && nameString != nullptr) {
			nameString = nameString->NextSiblingElement("string");
		}
		m.name = nameString->GetText();
		printf("Model Name: %s\n", m.name);

	/* Get children */
		tinyxml2::XMLElement* child = model->FirstChildElement("Item");
		while (child != nullptr) {
			processItem(child, m.id);
			child = child->NextSiblingElement("Item");
		}
}

//This code sees what a class is and does shit.
void processItem(tinyxml2::XMLElement *item, int parent_id) {
	int max_id = 0;
	for (auto &object : objects) {
		if (object.id > max_id) {
			max_id = object.id;
		}
	}
	
	//This gets the classes instance name iirc
	tinyxml2::XMLElement* properties = item->FirstChildElement("Properties");
	tinyxml2::XMLElement* nameString = properties->FirstChildElement("string");
	if ((strcmp(nameString->Attribute("name"), "Name") != 0) && nameString != nullptr) {
		nameString = nameString->NextSiblingElement("string");
	}
	
	objects[max_id].name = nameString->GetText();
	//If the object is a part, then process it as a part
    if (strcmp(item->Attribute("class"), "Part") == 0) {
        processPart(item, parent_id);
		partCount++;
    }
	//If the object is a spawn location, then process it as a spawn location, though it uses modified part code.
	else if (strcmp(item->Attribute("class"), "SpawnLocation") == 0) {
        processSpawn(item, parent_id);
		partCount++;
    }
	//If the class is a script, then process the lua and such (Not implemented)
	else if (strcmp(item->Attribute("class"), "Script") == 0) {
        Script s;
        s.id = objects.size();
        s.parent_id = parent_id;
        objects.push_back(s);
        scripts.push_back(s);
    }
	//If the class is a model, then process the model and its children.
	else if (strcmp(item->Attribute("class"), "Model") == 0) {
        processModel(item, parent_id);
    }
}

//The code that processes a spawn location, if someone wants to comment this, please go on ahead for me.
void processSpawn(tinyxml2::XMLElement *part, int parent_id) {
	printf("Found a Part!\n");
	Part newPart;
	newPart.id = objects.size();
	newPart.parent_id = parent_id;
	tinyxml2::XMLElement* properties = part->FirstChildElement("Properties");
	
	/* Get the parts name. */
		tinyxml2::XMLElement* nameString = properties->FirstChildElement("string");
		if ((strcmp(nameString->Attribute("name"), "Name") != 0) && nameString != nullptr) {
			nameString = nameString->NextSiblingElement("string");
		}
		newPart.name = nameString->GetText();
		printf("Part Name: %s\n", newPart.name);
		
	tinyxml2::XMLElement* coordinateFrame = properties->FirstChildElement("CoordinateFrame");
	while (strcmp(coordinateFrame->Attribute("name"), "CFrame") != 0 && coordinateFrame != nullptr) {
		coordinateFrame = coordinateFrame->NextSiblingElement("CoordinateFrame");
	}
	
	tinyxml2::XMLElement* size = properties->FirstChildElement("Vector3");
	while (strcmp(size->Attribute("name"), "size") != 0 && size != nullptr) {
		size = size->NextSiblingElement("Vector3");
	}
	
	if (coordinateFrame != nullptr && size != nullptr && nameString != nullptr) {
		//iprintf("Class Name: %s\n",name->GetText());
		float xScale, yScale, zScale, xPos, yPos, zPos;
		size->FirstChildElement("X")->QueryFloatText(&xScale);
		size->FirstChildElement("Y")->QueryFloatText(&yScale);
		size->FirstChildElement("Z")->QueryFloatText(&zScale);
		
		coordinateFrame->FirstChildElement("X")->QueryFloatText(&xPos);
		coordinateFrame->FirstChildElement("Y")->QueryFloatText(&yPos);
		coordinateFrame->FirstChildElement("Z")->QueryFloatText(&zPos);
		printf("Vec3Name: %s\nSize: (%f, %f, %f)\n", size->Attribute("name"), xScale, yScale, zScale);
		printf("CFrameName: %s\nPosition: (%f, %f, %f)\n", coordinateFrame->Attribute("name"), xPos, yPos, zPos);
		printf("Adding Part...\n");
		
		int scaleBy = 1024;
		int brickColorVal = 0;
		float transTemp;
		float transparencyVal = 0;
		int shapeID;
		
		if (true) {
			newPart.doCull = false;
		}
		
		/* Color */
		printf("Getting Part Color...\n");
		tinyxml2::XMLElement* brickColor = properties->FirstChildElement("int");
		while (strcmp(brickColor->Attribute("name"), "BrickColor") == 1 && brickColor != nullptr) {
			brickColor = brickColor->NextSiblingElement("int");
		}
		
		/* Alpha */
		printf("Getting Part Alpha...\n");
		tinyxml2::XMLElement* transparencyXML = properties->FirstChildElement("float");
		while (strcmp(transparencyXML->Attribute("name"), "Transparency") != 0 && transparencyXML != nullptr) {
			transparencyXML = transparencyXML->NextSiblingElement("float");
		}
		transparencyXML->QueryFloatText(&newPart.transparency);
		
		/* Shape */
		printf("Getting Part Shape...\n");
		tinyxml2::XMLElement* shapeXML = properties->FirstChildElement("token");
		while (strcmp(shapeXML->Attribute("name"), "shape") != 0 && shapeXML != nullptr) {
			shapeXML = shapeXML->NextSiblingElement("token");
		}
		shapeXML->QueryIntText(&shapeID);
		
		/* CanCollide */
		printf("Getting Part Collision...\n");
		tinyxml2::XMLElement* canCollideXML = properties->FirstChildElement("bool");
		while (strcmp(canCollideXML->Attribute("name"), "CanCollide") != 0 && canCollideXML != nullptr) {
			canCollideXML = canCollideXML->NextSiblingElement("bool");
		}
		printf("CollisName: %s\n", canCollideXML->Attribute("name"));
		
		/* Anchored */
		printf("Getting Part Anchored\nState...\n");
		tinyxml2::XMLElement* anchoredXML = properties->FirstChildElement("bool");
		while (strcmp(anchoredXML->Attribute("name"), "Anchored") != 0 && anchoredXML != nullptr) {
			anchoredXML = anchoredXML->NextSiblingElement("bool");
		}

		transparencyVal = abs(transTemp);
		printf("fltnm: %s\n", transparencyXML->Attribute("name"));
		
		brickColor->QueryIntText(&brickColorVal);
		printf("Brick Color: %d\n", brickColorVal);
		printf("ColorName Attr: %s\n", brickColor->Attribute("name"));
		printf("Brick Transparency: %f\n", transparencyVal);
		printf("Brick Shape: %d\n", shapeID);
		
		/*Other*/
		newPart.shape = shapeID;
		canCollideXML->QueryBoolText(&newPart.canCollide);
		anchoredXML->QueryBoolText(&newPart.isAnchored);

		/*Color and Alpha*/
		newPart.brickColor = brickColorVal;

		/*Position*/
		newPart.pos_x = xPos * scaleBy;
		newPart.pos_y = yPos * scaleBy;
		newPart.pos_z = zPos * scaleBy;

		/*Scale*/
		newPart.scale_width = (xScale/2) * scaleBy;
		newPart.scale_height = (yScale/2) * scaleBy;
		newPart.scale_depth = (zScale/2) * scaleBy;
		
		spawnLocation_X[spawnCount] = xPos * scaleBy;
		spawnLocation_Y[spawnCount] = (yPos * scaleBy) + ((yScale/2) * scaleBy);
		spawnLocation_Z[spawnCount] = zPos * scaleBy;
		spawnCount++;

		/*Rotation Matrix*/
		coordinateFrame->FirstChildElement("R00")->QueryFloatText(&newPart.r00);
		coordinateFrame->FirstChildElement("R01")->QueryFloatText(&newPart.r01);
		coordinateFrame->FirstChildElement("R02")->QueryFloatText(&newPart.r02);

		coordinateFrame->FirstChildElement("R10")->QueryFloatText(&newPart.r10);
		coordinateFrame->FirstChildElement("R11")->QueryFloatText(&newPart.r11);
		coordinateFrame->FirstChildElement("R12")->QueryFloatText(&newPart.r12);

		coordinateFrame->FirstChildElement("R20")->QueryFloatText(&newPart.r20);
		coordinateFrame->FirstChildElement("R21")->QueryFloatText(&newPart.r21);
		coordinateFrame->FirstChildElement("R22")->QueryFloatText(&newPart.r22);

		printf("Part added with these attr:\nPos: %f, %f, %f\nScale: %f, %f, %f\n", newPart.pos_x, newPart.pos_y, newPart.pos_z, newPart.scale_width, newPart.scale_height, newPart.scale_depth);
		//printf("Parent Name: %s\n", objects[newPart.parent_id].name);
	}
		
	objects.push_back(newPart);
	parts.push_back(newPart);
}

//The code that processes a part, if someone wants to comment this, please go on ahead for me.
void processPart(tinyxml2::XMLElement *part, int parent_id) {
	printf("Found a Part!\n");
	Part newPart;
	newPart.id = objects.size();
	newPart.parent_id = parent_id;
	tinyxml2::XMLElement* properties = part->FirstChildElement("Properties");
	
	/* Get the parts name */
		tinyxml2::XMLElement* nameString = properties->FirstChildElement("string");
		if ((strcmp(nameString->Attribute("name"), "Name") != 0) && nameString != nullptr) {
			nameString = nameString->NextSiblingElement("string");
		}
		newPart.name = nameString->GetText();
		printf("Part Name: %s\n", newPart.name);
		
	tinyxml2::XMLElement* coordinateFrame = properties->FirstChildElement("CoordinateFrame");
	while (strcmp(coordinateFrame->Attribute("name"), "CFrame") != 0 && coordinateFrame != nullptr) {
		coordinateFrame = coordinateFrame->NextSiblingElement("CoordinateFrame");
	}
	
	tinyxml2::XMLElement* size = properties->FirstChildElement("Vector3");
	while (strcmp(size->Attribute("name"), "size") != 0 && size != nullptr) {
		size = size->NextSiblingElement("Vector3");
	}
	
	if (coordinateFrame != nullptr && size != nullptr && nameString != nullptr) {
		//iprintf("Class Name: %s\n",name->GetText());
		float xScale, yScale, zScale, xPos, yPos, zPos;
		size->FirstChildElement("X")->QueryFloatText(&xScale);
		size->FirstChildElement("Y")->QueryFloatText(&yScale);
		size->FirstChildElement("Z")->QueryFloatText(&zScale);
		
		coordinateFrame->FirstChildElement("X")->QueryFloatText(&xPos);
		coordinateFrame->FirstChildElement("Y")->QueryFloatText(&yPos);
		coordinateFrame->FirstChildElement("Z")->QueryFloatText(&zPos);
		printf("Vec3Name: %s\nSize: (%f, %f, %f)\n", size->Attribute("name"), xScale, yScale, zScale);
		printf("CFrameName: %s\nPosition: (%f, %f, %f)\n", coordinateFrame->Attribute("name"), xPos, yPos, zPos);
		printf("Adding Part...\n");
		
		int scaleBy = 1024;
		int brickColorVal = 0;
		float transTemp;
		float transparencyVal = 0;
		int shapeID;
		
		if (true) {
			newPart.doCull = false;
		}
		
		/* Color */
		printf("Getting Part Color...\n");
		tinyxml2::XMLElement* brickColor = properties->FirstChildElement("int");
		while (strcmp(brickColor->Attribute("name"), "BrickColor") == 1 && brickColor != nullptr) {
			brickColor = brickColor->NextSiblingElement("int");
		}
		
		/* Alpha */
		printf("Getting Part Alpha...\n");
		tinyxml2::XMLElement* transparencyXML = properties->FirstChildElement("float");
		while (strcmp(transparencyXML->Attribute("name"), "Transparency") != 0 && transparencyXML != nullptr) {
			transparencyXML = transparencyXML->NextSiblingElement("float");
		}
		transparencyXML->QueryFloatText(&newPart.transparency);
		
		/* Shape */
		printf("Getting Part Shape...\n");
		tinyxml2::XMLElement* shapeXML = properties->FirstChildElement("token");
		while (strcmp(shapeXML->Attribute("name"), "shape") != 0 && shapeXML != nullptr) {
			shapeXML = shapeXML->NextSiblingElement("token");
		}
		shapeXML->QueryIntText(&shapeID);
		
		/* CanCollide */
		printf("Getting Part Collision...\n");
		tinyxml2::XMLElement* canCollideXML = properties->FirstChildElement("bool");
		while (strcmp(canCollideXML->Attribute("name"), "CanCollide") != 0 && canCollideXML != nullptr) {
			canCollideXML = canCollideXML->NextSiblingElement("bool");
		}
		
		/* Anchored */
		printf("Getting Part Anchored\nState...\n");
		tinyxml2::XMLElement* anchoredXML = properties->FirstChildElement("bool");
		while (strcmp(anchoredXML->Attribute("name"), "Anchored") != 0 && anchoredXML != nullptr) {
			anchoredXML = anchoredXML->NextSiblingElement("bool");
		}

		transparencyVal = abs(transTemp);
		printf("fltnm: %s\n", transparencyXML->Attribute("name"));
		
		brickColor->QueryIntText(&brickColorVal);
		printf("Brick Color: %d\n", brickColorVal);
		printf("ColorName Attr: %s\n", brickColor->Attribute("name"));
		printf("Brick Transparency: %f\n", transparencyVal);
		printf("Brick Shape: %d\n", shapeID);
		
		/*Other*/
		newPart.shape = shapeID;
		canCollideXML->QueryBoolText(&newPart.canCollide);
		anchoredXML->QueryBoolText(&newPart.isAnchored);

		/*Color and Alpha*/
		newPart.brickColor = brickColorVal;

		/*Position*/
		newPart.pos_x = xPos * scaleBy;
		newPart.pos_y = yPos * scaleBy;
		newPart.pos_z = zPos * scaleBy;

		/*Scale*/
		newPart.scale_width = (xScale/2) * scaleBy;
		newPart.scale_height = (yScale/2) * scaleBy;
		newPart.scale_depth = (zScale/2) * scaleBy;

		/*Rotation Matrix*/
		coordinateFrame->FirstChildElement("R00")->QueryFloatText(&newPart.r00);
		coordinateFrame->FirstChildElement("R01")->QueryFloatText(&newPart.r01);
		coordinateFrame->FirstChildElement("R02")->QueryFloatText(&newPart.r02);

		coordinateFrame->FirstChildElement("R10")->QueryFloatText(&newPart.r10);
		coordinateFrame->FirstChildElement("R11")->QueryFloatText(&newPart.r11);
		coordinateFrame->FirstChildElement("R12")->QueryFloatText(&newPart.r12);

		coordinateFrame->FirstChildElement("R20")->QueryFloatText(&newPart.r20);
		coordinateFrame->FirstChildElement("R21")->QueryFloatText(&newPart.r21);
		coordinateFrame->FirstChildElement("R22")->QueryFloatText(&newPart.r22);

		printf("Part added with these attr:\nPos: %f, %f, %f\nScale: %f, %f, %f\nCan Collide With: ", newPart.pos_x, newPart.pos_y, newPart.pos_z, newPart.scale_width, newPart.scale_height, newPart.scale_depth);
		printf(newPart.canCollide ? "true\n" : "false\n");
		//printf("Parent Name: %s\n", objects[newPart.parent_id].name);
	}
		
	objects.push_back(newPart);
	parts.push_back(newPart);
}

void processHumanoid(tinyxml2::XMLElement *humanoid) {
    // ...
	printf("Found a Humanoid!\n");
}

void processScript(tinyxml2::XMLElement *script) {
    // ...
	printf("Found a Script!\n");
}

//const char *characterFile = "content/fonts/character.rbxm";

/* Scuffed non-functional delta time func */
float GetDeltaTime() {
    static std::chrono::time_point<std::chrono::high_resolution_clock> prevTimePoint = std::chrono::high_resolution_clock::now();
    auto currentTimePoint = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTimePoint - prevTimePoint).count();
    prevTimePoint = currentTimePoint;
    return deltaTime;
}

//Supported formats
std::vector<std::string_view> extensions = { ".rbxl" };

//Sorts files by extension and if so, then use this to add them to the list
bool extension(const std::string_view filename, const std::vector<std::string_view> extensions) {
    for (std::string_view extension : extensions) {
        if (strcasecmp(filename.substr(filename.size() - extension.size()).data(), extension.data()) == 0) {
            return true;
        }
    }

    return false;
}

int main(int argc, char **argv)
{
	consoleDemoInit();
	
	const char *mapFile[256];
	int mapLength = 0;

	/* Start up fs */
	if (fatInitDefault()) {
		DIR *pdir;
		struct dirent *pent;

		pdir=opendir(isDSiMode() ? "sd:/OpenBLOX" : "fat:/OpenBLOX");

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
						mapLength+=1;
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
			
			bool fileIsSelected = false;
			int fSelectNumb = 0;
			
			/* Primitive file select */
			while (!fileIsSelected) {
				scanKeys();
				pressed = keysDownRepeat();
				held = keysHeld();
				
				//Print filelist
				if (j == 0) {
					printf("-= Map Select =-\n");
				}
				for (int i = 0; i < mapLength; i++) {
					if (j <= mapLength) {
						if (j == fSelectNumb) {
							printf("-> ");
						}
						printf("%s\n", mapFile[i]);
						j += 1;
					}
				}
				
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
					fSelectNumb = mapLength;
				}
				if (fSelectNumb > mapLength) {
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
			sprintf(filePath, "%s/%s", isDSiMode() ? "sd:/OpenBLOX" : "fat:/OpenBLOX", mapFile[fSelectNumb]);
			FILE *fp = fopen(filePath, "r");
			parseRBXL(fp);
			
			/* Load player model */
			char filePathChar[256];
			sprintf(filePath, "%s/%s", isDSiMode() ? "sd:/OpenBLOX" : "fat:/OpenBLOX", "content/fonts/character.rbxm");
			FILE *fpchar = fopen(filePath, "r");
			parseRBXM(fpchar);
			
			closedir(pdir);
		} else {
			iprintf ("opendir() failure; terminating\n");
		}
		
	} else {
		iprintf("fatInit failure\n");
	}
	

	//set mode 0, enable BG0 and set it to 3D
	videoSetMode(MODE_0_3D);

	// initialize gl
	glInit();
	int cullDist = 64; //this is the part cull distance, different than the actual DS cull distance.
	
	// enable antialiasing
	glEnable(GL_ANTIALIAS);
	glEnable(GL_BLEND);
	glEnable(GL_FOG);
	glEnable(POLY_TOON_HIGHLIGHT);
	glEnable(POLY_DECAL);
	glEnable(POLY_SHADOW);
	glEnable(GL_POLY_OVERFLOW);
	
	//Set up the background color
	int bgr, bgg, bgb;
	bgr = 161;
	bgg = 190;
	bgb = 230;
	
	// setup the rear plane
	glClearColor(bgr/31,bgg/31,bgb/31,31); // BG must be opaque for AA to work
	glClearPolyID(63); // BG must have a unique polygon ID for AA to work
	glClearDepth(0x7FFF);

	//this should work the same as the normal gl call
	glViewport(0,0,255,191);

	//any floating point gl call is being converted to fixed prior to being implemented
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 256.0 / 192.0, 0.1, cullDist*8);
	
	gluLookAt(	0.0, 1.25, -2.5,		//camera possition
				0.0, 1.25, 0.0,		//look at
				0.0, 1.0, 0.0);		//up
	
	//Create player
	Player player;
	
	std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, spawnCount-1); // define the range
	int spawnID = distr(gen);
	
	//Spawn player @ random spawn
	player.pos_x = -spawnLocation_X[spawnID];
	player.pos_y = -spawnLocation_Y[spawnID] - (8192/2);
	player.pos_z = -spawnLocation_Z[spawnID];
	
	auto now = std::chrono::steady_clock::now();
	auto lastUpdate = now;
	float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastUpdate).count() / 1000000.0f;
	
	while(1)
	{
		glPushMatrix();
		
		auto now = std::chrono::steady_clock::now();
		float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastUpdate).count() / 1000000.0f;
		auto lastUpdate = now;
		
		int deltaScale = 1024*10;
		float gameDelta = abs(deltaScale/(deltaTime/1000000));

		//Camera Rotation and position
		glRotateX(player.directionFacing_x);
		glRotateY(player.walkDirection_y);
		glTranslatef32(player.pos_x, player.pos_y, player.pos_z);

		glMatrixMode(GL_MODELVIEW);
		
		//set up a directional ligth arguments are light number (0-3), light color, 
		//and an x,y,z vector that points in the direction of the light
		glLight(0, RGB15(31,31,31), floattov10(-0.25), floattov10(-1.0), floattov10(-0.5));
		glColor3f(1,1,1);
		
		/* Player Logic V */
		
		//Spawn
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, spawnCount-1); // define the range
		int spawnID = distr(gen);
	
		//Player API
		player.Render();
		player.Input();
		player.Update(parts, partCount, 1);
		
		//Respawn player if below map.
		if (player.pos_y > (256*1024)) {
			player.pos_x = -spawnLocation_X[spawnID];
			player.pos_y = -spawnLocation_Y[spawnID] - (8192/2);
			player.pos_z = -spawnLocation_Z[spawnID];
			player.walkVelocityRelative_y = 0;
		}
		
		/* End of Player logic ^ */
	
		//The slow as fuck renderer code
		int divDistance = 0;
		for (auto i = 0; i < parts.size(); ++i) {
			if (i < parts.size() - 6){
				if (parts[i].getDistanceFromPlayer(-player.pos_x, -player.pos_y, -player.pos_z) < cullDist * 1024 ||
				parts[i].scale_width >= (cullDist/2) * 1024 ||
				parts[i].scale_depth >= (cullDist/2) * 1024)
				{
					//Unused attempt at fading parts.
					/*
					if (parts[i].getDistanceFromPlayer(-player.pos_x, -player.pos_y, -player.pos_z) < (cullDist * (512)) ||
					parts[i].scale_width >= (cullDist/2) * 1024 ||
					parts[i].scale_depth >= (cullDist/2) * 1024)
					{
						divDistance = 0;
					} else {
						divDistance = 0;
					}*/
					
					//Draw each part.
					glPushMatrix();
					parts[i].draw(divDistance);
					glPopMatrix(1);
				}
			} else { //IF else, then it is the players part-list.
				//Render player model!
				glPushMatrix();
					glTranslatef32(-player.pos_x, -player.pos_y-1024-512, -player.pos_z);
					glRotateY(player.facingDirection_y);
					glTranslatef32(0,0, -(8192*3.2125));
					parts[i].draw(divDistance);
				glPopMatrix(1);
			}
		}

		glEnd();

		glPopMatrix(1);

		glFlush(0);

		swiWaitForVBlank();
	}

	return 0;
}//end main
