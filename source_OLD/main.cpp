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

Part part[8192];
int partCount;

int spawnLocation_X, spawnLocation_Y, spawnLocation_Z;

void glVertex3(float x,float y,float z) {
	glVertex3f(x,y,z);
}

void drawBlock(float x, float y, float z, float width, float height, float depth, int r, int g, int b, float alpha, bool doCull) {
	width = abs(width);
	height = abs(height);
	depth = abs(depth);
	/*
	Renders a block that is scaled from the center outwards.
	*/
	
	/*
	glScalef32(scale_width[i], scale_height[i], scale_depth[i]);
	glTranslatef32(pos_x[i],pos_y[i],pos_z[i]);
	*/
	
	float xx1 = std::min(x - width, x + width);
	float xx2 = std::max(x - width, x + width);

	float yy1 = std::min(y - height, y + height);
	float yy2 = std::max(y - height, y + height);

	float zz1 = std::min(z - depth, z + depth);
	float zz2 = std::max(z - depth, z + depth);

/*
	if ((x + width < x - width) || (y + height < y - height) || (z + depth < z - depth)) {
		glPolyFmt(POLY_ALPHA(31 - int(alpha * 31)) | POLY_CULL_NONE | POLY_FORMAT_LIGHT0);
	} else {
		glPolyFmt(POLY_ALPHA(31 - int(alpha * 31)) | POLY_CULL_BACK | POLY_FORMAT_LIGHT0);
	}
*/
	if (doCull) {
		glPolyFmt(POLY_ALPHA(31 - int(alpha * 31)) | POLY_CULL_BACK | POLY_FORMAT_LIGHT0);
	}
	//need to set up some material properties since DS does not have them set by default
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
	
	//Front
	glBegin(GL_QUAD);
		glNormal3f(0,0,1);
		glVertex3(xx1, yy2, zz1);
		glVertex3(xx2, yy2, zz1);
		glVertex3(xx2, yy1, zz1);
		glVertex3(xx1, yy1, zz1);
	glEnd();

	//Back
	glBegin(GL_QUAD);
		glNormal3f(0,0,-1);
		glVertex3(xx1, yy1, zz2);
		glVertex3(xx2, yy1, zz2);
		glVertex3(xx2, yy2, zz2);
		glVertex3(xx1, yy2, zz2);
	glEnd();

	//Right
	glBegin(GL_QUAD);
		glNormal3f(1,0,0);
		glVertex3(xx1, yy1, zz1);
		glVertex3(xx1, yy1, zz2);
		glVertex3(xx1, yy2, zz2);
		glVertex3(xx1, yy2, zz1);
	glEnd();

	//Left
	glBegin(GL_QUAD);
		glNormal3f(-1,0,0);
		glVertex3(xx2, yy1, zz2);
		glVertex3(xx2, yy1, zz1);
		glVertex3(xx2, yy2, zz1);
		glVertex3(xx2, yy2, zz2);
	glEnd();

	glPolyFmt(POLY_ALPHA(31-int(alpha*31)) | POLY_CULL_NONE  | POLY_FORMAT_LIGHT0);
	
	if (((x+width >= 20) || (x-width <= -20)) || ((z+depth >= 20) || (z-depth <= -20))) {
		//glFrustum(0,0,255,191, 0.01, 8192);
	}
	
	glBegin(GL_QUAD);
	//Bottom
		glNormal3f(0,-1,0);
		glVertex3(xx1, yy1, zz1);
		glVertex3(xx2, yy1, zz1);
		glVertex3(xx2, yy1, zz2);
		glVertex3(xx1, yy1, zz2);
		
	//Top
		glNormal3f(0,1,0);
		glVertex3(xx1, yy2, zz2);
		glVertex3(xx2, yy2, zz2);
		glVertex3(xx2, yy2, zz1);
		glVertex3(xx1, yy2, zz1);
	glEnd();
}

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


void calculateBrickColor(float value) {
	int switchVal = int(value);
	printf("Current Value: %d\n", switchVal);
	switch(switchVal) {
		//White to black
		
		/*White*/
		case(1):
			part[partCount].color_r = 242;
			part[partCount].color_g = 243;
			part[partCount].color_b = 242;
		break;
		
		case(208):
			part[partCount].color_r = 229;
			part[partCount].color_g = 228;
			part[partCount].color_b = 222;
		break;
		
		case(194):
			part[partCount].color_r = 163;
			part[partCount].color_g = 162;
			part[partCount].color_b = 164;
		break;
		
		case(199):
			part[partCount].color_r = 99;
			part[partCount].color_g = 95;
			part[partCount].color_b = 97;
		break;
		
		case(26):
			part[partCount].color_r = 27;
			part[partCount].color_g = 42;
			part[partCount].color_b = 52;
		break;
		/*Black*/
		
		//Red to bright yellow
		
		/*Red*/
		case(21):
			part[partCount].color_r = 196;
			part[partCount].color_g = 40;
			part[partCount].color_b = 27;
		break;
		
		case(24):
			part[partCount].color_r = 245;
			part[partCount].color_g = 205;
			part[partCount].color_b = 47;
		break;
		
		case(226):
			part[partCount].color_r = 253;
			part[partCount].color_g = 234;
			part[partCount].color_b = 140;
		break;
		/*Bright Yellow*/
		
		//Blues
		case(23):
			part[partCount].color_r = 13;
			part[partCount].color_g = 105;
			part[partCount].color_b = 171;
		break;
		
		case(107):
			part[partCount].color_r = 0;
			part[partCount].color_g = 143;
			part[partCount].color_b = 155;
		break;
		
		case(102):
			part[partCount].color_r = 110;
			part[partCount].color_g = 153;
			part[partCount].color_b = 201;
		break;
		
		case(11):
			part[partCount].color_r = 128;
			part[partCount].color_g = 187;
			part[partCount].color_b = 219;
		break;
		
		case(45):
			part[partCount].color_r = 180;
			part[partCount].color_g = 210;
			part[partCount].color_b = 227;
		break;
		
		case(135):
			part[partCount].color_r = 116;
			part[partCount].color_g = 134;
			part[partCount].color_b = 156;
		break;
		//End of blues
		
		//Oranges
		case(106):
			part[partCount].color_r = 218;
			part[partCount].color_g = 133;
			part[partCount].color_b = 64;
		break;
		
		case(105):
			part[partCount].color_r = 226;
			part[partCount].color_g = 155;
			part[partCount].color_b = 105;
		break;
		//End of Oranges
		
		/* Half Way Mark */
		
		/*Greens*/
		case(141):
			part[partCount].color_r = 39;
			part[partCount].color_g = 70;
			part[partCount].color_b = 44;
		break;
		
		case(28):
			part[partCount].color_r = 40;
			part[partCount].color_g = 127;
			part[partCount].color_b = 70;
		break;
		
		case(37):
			part[partCount].color_r = 75;
			part[partCount].color_g = 151;
			part[partCount].color_b = 74;
		break;
		
		case(119):
			part[partCount].color_r = 164;
			part[partCount].color_g = 189;
			part[partCount].color_b = 70;
		break;
		
		case(29):
			part[partCount].color_r = 161;
			part[partCount].color_g = 196;
			part[partCount].color_b = 139;
		break;
	
		case(151):
			part[partCount].color_r = 120;
			part[partCount].color_g = 144;
			part[partCount].color_b = 129;
		break;
		/*End of greens*/
		
		/*First 2 shades of brown*/
		case(38):
			part[partCount].color_r = 160;
			part[partCount].color_g = 95;
			part[partCount].color_b = 52;
		break;
		
		case(192):
			part[partCount].color_r = 105;
			part[partCount].color_g = 64;
			part[partCount].color_b = 39;
		break;
		/*end of said shades*/
		
		/*Pastels to Brown*/
		case(104):
			part[partCount].color_r = 107;
			part[partCount].color_g = 50;
			part[partCount].color_b = 123;
		break;
		
		case(9):
			part[partCount].color_r = 232;
			part[partCount].color_g = 186;
			part[partCount].color_b = 199;
		break;
		
		case(101):
			part[partCount].color_r = 218;
			part[partCount].color_g = 134;
			part[partCount].color_b = 121;
		break;
		
		case(5):
			part[partCount].color_r = 215;
			part[partCount].color_g = 197;
			part[partCount].color_b = 153;
		break;
		
		case(153):
			part[partCount].color_r = 149;
			part[partCount].color_g = 121;
			part[partCount].color_b = 118;
		break;
	
		case(217):
			part[partCount].color_r = 124;
			part[partCount].color_g = 92;
			part[partCount].color_b = 69;
		break;
		
		case(18):
			part[partCount].color_r = 204;
			part[partCount].color_g = 142;
			part[partCount].color_b = 104;
		break;
		
		case(125):
			part[partCount].color_r = 234;
			part[partCount].color_g = 184;
			part[partCount].color_b = 145;
		break;
		/*end of said shades*/
		
		/*Unused*/
		case(39):
			part[partCount].color_r = 234;
			part[partCount].color_g = 184;
			part[partCount].color_b = 145;
		break;
		/*End of Unused*/
		
		default:
			part[partCount].color_r = 193;
			part[partCount].color_g = 202;
			part[partCount].color_b = 222;
		break;
	}
}

void createPart_fromData(tinyxml2::XMLElement* modelChild, int isModel, bool isSpawn) {
	iprintf("Part found!\n");
	tinyxml2::XMLElement* properties = modelChild->FirstChildElement("Properties");
	
	tinyxml2::XMLElement* coordinateFrame = properties->FirstChildElement("CoordinateFrame");
	while (strcmp(coordinateFrame->Attribute("name"), "CFrame") != 0 && coordinateFrame != nullptr) {
		coordinateFrame = coordinateFrame->NextSiblingElement("CoordinateFrame");
	}
	
	tinyxml2::XMLElement* size = properties->FirstChildElement("Vector3");
	while (strcmp(size->Attribute("name"), "size") != 0 && size != nullptr) {
		size = size->NextSiblingElement("Vector3");
	}
	
	tinyxml2::XMLElement* name = properties->FirstChildElement("string");

	if (coordinateFrame != nullptr && size != nullptr && name != nullptr) {
		iprintf("Class Name: %s\n",name->GetText());
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
		float brickColorVal = 0;
		float transTemp;
		float transparencyVal = 0;
		int shapeID;
		
		if (isSpawn) {
			part[partCount].doCull = false;
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
		transparencyXML->QueryFloatText(&transTemp);
		
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
		
		brickColor->QueryFloatText(&brickColorVal);
		printf("Brick Color: %f\n", brickColorVal);
		printf("Brick Transparency: %f\n", transparencyVal);
		printf("Brick Shape: %d\n", shapeID);
		
		/*Other*/
		part[partCount].shape = shapeID;
		canCollideXML->QueryBoolText(&part[partCount].canCollide);
		anchoredXML->QueryBoolText(&part[partCount].isAnchored);

		/*Color and Alpha*/
		calculateBrickColor(brickColorVal);
		part[partCount].transparency = transparencyVal;

		/*Position*/
		part[partCount].pos_x = xPos * scaleBy;
		part[partCount].pos_y = yPos * scaleBy;
		part[partCount].pos_z = zPos * scaleBy;

		/*Scale*/
		part[partCount].scale_width = (xScale/2) * scaleBy;
		part[partCount].scale_height = (yScale/2) * scaleBy;
		part[partCount].scale_depth = (zScale/2) * scaleBy;

		/*Rotation Matrix*/
		coordinateFrame->FirstChildElement("R00")->QueryFloatText(&part[partCount].r00);
		coordinateFrame->FirstChildElement("R01")->QueryFloatText(&part[partCount].r01);
		coordinateFrame->FirstChildElement("R02")->QueryFloatText(&part[partCount].r02);

		coordinateFrame->FirstChildElement("R10")->QueryFloatText(&part[partCount].r10);
		coordinateFrame->FirstChildElement("R11")->QueryFloatText(&part[partCount].r11);
		coordinateFrame->FirstChildElement("R12")->QueryFloatText(&part[partCount].r12);

		coordinateFrame->FirstChildElement("R20")->QueryFloatText(&part[partCount].r20);
		coordinateFrame->FirstChildElement("R21")->QueryFloatText(&part[partCount].r21);
		coordinateFrame->FirstChildElement("R22")->QueryFloatText(&part[partCount].r22);

		printf("Part added with these attr:\nPos: %f, %f, %f\nScale: %f, %f, %f\nPart ID: %d\n", part[partCount].pos_x, part[partCount].pos_y, part[partCount].pos_z, part[partCount].scale_width, part[partCount].scale_height, part[partCount].scale_depth, partCount);
		partCount++;
	}
}

void processItem(tinyxml2::XMLElement *item, int level)
{
    if (item == nullptr)
        return;

    if (strcmp(item->Attribute("class"), "Part") == 0 || strcmp(item->Attribute("class"), "SpawnLocation") == 0)
    {
        createPart_fromData(item, level, (strcmp(item->Attribute("class"), "SpawnLocation") == 0));
		if (strcmp(item->Attribute("class"), "SpawnLocation") == 0) {
			spawnLocation_X = part[partCount].pos_x;
			spawnLocation_Y = part[partCount].pos_y;
			spawnLocation_Z = part[partCount].pos_z;
		}
        /* VVVVVV */
    }
    else if (strcmp(item->Attribute("class"), "Model") == 0)
    {
        tinyxml2::XMLElement *modelChild = item->FirstChildElement("Item");
        while (modelChild != nullptr)
        {
            processItem(modelChild, level + 1);
            modelChild = modelChild->NextSiblingElement("Item");
        }
    }
}

void parseRBXL(FILE* filename) {
    iprintf("Begining to parse.\n");
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError error = doc.LoadFile(filename);
    if (error != tinyxml2::XML_SUCCESS) {
        iprintf("Cant find XML.\n");
        return;
    }
	
	tinyxml2::XMLElement* ROBLOX = doc.FirstChildElement("roblox");
    tinyxml2::XMLElement* workspace = ROBLOX->FirstChildElement("Item");
    tinyxml2::XMLElement* child = workspace->FirstChildElement("Item");
	
	if (workspace != nullptr)
	{
		while (strcmp(workspace->Attribute("class"), "Workspace") != 0 && workspace != nullptr) {
			workspace = workspace->NextSiblingElement("Item");
			iprintf("Trying class: %s\n", workspace->Attribute("class"));
		}
		if (workspace != nullptr && strcmp(workspace->Attribute("class"), "Workspace") == 0) {
			iprintf("Workspace found!\n\nType: %s\n", workspace->Attribute("class"));
			
			child = workspace->FirstChildElement("Item");
		}
	} else {
		iprintf("Workspace not found.\n");
	}
	
	while (child != nullptr)
	{
		processItem(child, 0);
		child = child->NextSiblingElement("Item");
	}

}

void parseRBXM(FILE* filename) {
    iprintf("Begining to parse.\n");
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError error = doc.LoadFile(filename);
    if (error != tinyxml2::XML_SUCCESS) {
        iprintf("Cant find XML.\n");
        return;
    }
	
	tinyxml2::XMLElement* ROBLOX = doc.FirstChildElement("roblox");
    tinyxml2::XMLElement* workspace = ROBLOX->FirstChildElement("Item");
    tinyxml2::XMLElement* child = workspace->FirstChildElement("Item");
	
	if (workspace != nullptr)
	{
		while (strcmp(workspace->Attribute("class"), "Model") != 0 && workspace != nullptr) {
			workspace = workspace->NextSiblingElement("Item");
			iprintf("Trying class: %s\n", workspace->Attribute("class"));
		}
		if (workspace != nullptr && strcmp(workspace->Attribute("class"), "Workspace") == 0) {
			iprintf("Workspace found!\n\nType: %s\n", workspace->Attribute("class"));
			
			child = workspace->FirstChildElement("Item");
		}
	} else {
		iprintf("Workspace not found.\n");
	}
	
	while (child != nullptr)
	{
		processItem(child, 0);
		child = child->NextSiblingElement("Item");
	}

}

const char *characterFile = "character.rbxm";

int main(int argc, char **argv)
{
	// Initialise the console, required for printf
	consoleDemoInit();

	float rotateX = 0.0;
	float rotateY = 0.0;
	//const char *mapName = "June06.rbxl";
	//const char *mapName = "2007 - extreme four corners.rbxl";
	//const char *mapName = "2008 - Grow a Brick.rbxl";
	//const char *mapName = "PartColor.rbxl";
	const char *mapName = "map.rbxl";

	if (fatInitDefault()) {
		FILE* chracterModel = fopen (characterFile, "rb");
		FILE* test = fopen (mapName, "rb");
		tinyxml2::XMLDocument doc;
		if (test != NULL) {
			iprintf("%s has been loaded into mem.\n",mapName);
			parseRBXL(test);
		} else {
			iprintf("%s has failed to load.\nEnsure your device/emu supports fat.\n",mapName);
		}
		
		if (chracterModel != NULL) {
			iprintf("%s has been loaded into mem.\n",characterFile);
			parseRBXM(chracterModel);
		} else {
			iprintf("%s has failed to load.\n",characterFile);
		}
	} else {
		iprintf("fatInit failure\n");
	}

	//set mode 0, enable BG0 and set it to 3D
	videoSetMode(MODE_0_3D);

	// initialize gl
	glInit();
	
	// enable antialiasing
	glEnable(GL_ANTIALIAS);
	glEnable(GL_BLEND);
	glEnable(GL_FOG);
	glEnable(POLY_TOON_HIGHLIGHT);
	glEnable(POLY_DECAL);
	glEnable(POLY_SHADOW);
	glEnable(GL_POLY_OVERFLOW);
	glFogColor(24,24,31,31);
	glFogDensity(0,127);
	glFogOffset(64);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
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
	gluPerspective(90, 256.0 / 192.0, 0.1, 512);
	
	gluLookAt(	0.0, 0.0, 8.0,		//camera possition
				0.0, 0.0, 0.0,		//look at
				0.0, 1.0, 0.0);		//up
				

	float zoom = 0.0;

	while(1)
	{
		glPushMatrix();

		//move it away from the camera
		glTranslatef32(0, 0, floattof32(-1 + zoom));

		glRotateX(rotateX);
		glRotateY(rotateY);


		glMatrixMode(GL_PROJECTION);

		//not a real gl function and will likely change
		//glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);
		
		glMatrixMode(GL_MODELVIEW);

		scanKeys();

		u16 keys = keysHeld();

		if((keys & KEY_UP)) rotateX += 3;
		if((keys & KEY_DOWN)) rotateX -= 3;
		if((keys & KEY_LEFT)) rotateY += 3;
		if((keys & KEY_RIGHT)) rotateY -= 3;
		
		if((keys & KEY_R)) zoom += 0.1;
		if((keys & KEY_L)) zoom -= 0.1;

		//drawBlock(0,0,0,1,1,1);
		
		//set up a directional ligth arguments are light number (0-3), light color, 
		//and an x,y,z vector that points in the direction of the light
		glLight(0, RGB15(31,31,31), floattov10(-0.25), floattov10(-1.0), floattov10(-0.5));

		glColor3f(1,1,1);
		
		float time = 0;
		drawBlock(spawnLocation_X,spawnLocation_Y,spawnLocation_Z, 0.1, 2, 0.1, 0,0,0,0,false);
		
		//Draw parts
		for (int i = 0; i < partCount; i++) {
			glMatrixMode(GL_MODELVIEW);
			
			time += 1;
			part[i].update(5);
			
			if (part[i].transparency != 1) {
				glPushMatrix();
				
				// Compute the angle of rotation
				float angle = acos((part[i].r00 + part[i].r11 + part[i].r22 - 1) / 2);

				// Compute the axis of rotation
				float x = (part[i].r21 - part[i].r12) / (2 * sin(angle));
				float y = (part[i].r02 - part[i].r20) / (2 * sin(angle));
				float z = (part[i].r10 - part[i].r01) / (2 * sin(angle));
				
				glTranslatef32(part[i].pos_x, part[i].pos_y, part[i].pos_z);
				// Use the glRotatef function with the angle and axis
				glRotatef(angle * 180 / M_PI, x, y, z);
				glScalef32(part[i].scale_width, part[i].scale_height, part[i].scale_depth);

				switch(part[i].shape){
					default:
					case(1):
						drawBlock(0,0,0,1,1,1,part[i].color_r,part[i].color_g,part[i].color_b,part[i].transparency, part[i].doCull);
					break;
					
					case(2):
						drawCylinder(0,0,0,1,1,1,part[i].color_r,part[i].color_g,part[i].color_b,part[i].transparency);
					break;
				}
				glPopMatrix(1);
			}
        }

		glEnd();

		glPopMatrix(1);

		glFlush(0);

		swiWaitForVBlank();

		if(keys & KEY_START) break;
	}

	return 0;
}//end main
