/*
    OpenBLOX Color
*/

// Giant-ass copy-paste from the original code because i have no real reason to redo it all from scratch.
int colorGrab(int value, unsigned char returnType) {
    unsigned char color_r = 255;
    unsigned char color_g = 0;
    unsigned char color_b = 255;
    switch (value) {
    case (1):
        color_r = 242;
        color_g = 243;
        color_b = 243;
        break;
    case (2):
        color_r = 161;
        color_g = 165;
        color_b = 162;
        break;
    case (3):
        color_r = 249;
        color_g = 233;
        color_b = 153;
        break;
    case (5):
        color_r = 215;
        color_g = 197;
        color_b = 154;
        break;
    case (6):
        color_r = 194;
        color_g = 218;
        color_b = 184;
        break;
    case (9):
        color_r = 232;
        color_g = 186;
        color_b = 200;
        break;
    case (11):
        color_r = 128;
        color_g = 187;
        color_b = 219;
        break;
    case (12):
        color_r = 203;
        color_g = 132;
        color_b = 66;
        break;
    case (18):
        color_r = 204;
        color_g = 142;
        color_b = 105;
        break;
    case (21):
        color_r = 196;
        color_g = 40;
        color_b = 28;
        break;
    case (22):
        color_r = 196;
        color_g = 112;
        color_b = 160;
        break;
    case (23):
        color_r = 13;
        color_g = 105;
        color_b = 172;
        break;
    case (24):
        color_r = 245;
        color_g = 205;
        color_b = 48;
        break;
    case (25):
        color_r = 98;
        color_g = 71;
        color_b = 50;
        break;
    case (26):
        color_r = 27;
        color_g = 42;
        color_b = 53;
        break;
    case (27):
        color_r = 109;
        color_g = 110;
        color_b = 108;
        break;
    case (28):
        color_r = 40;
        color_g = 127;
        color_b = 71;
        break;
    case (29):
        color_r = 161;
        color_g = 196;
        color_b = 140;
        break;
    case (36):
        color_r = 243;
        color_g = 207;
        color_b = 155;
        break;
    case (37):
        color_r = 75;
        color_g = 151;
        color_b = 75;
        break;
    case (38):
        color_r = 160;
        color_g = 95;
        color_b = 53;
        break;
    case (39):
        color_r = 193;
        color_g = 202;
        color_b = 222;
        break;
    case (40):
        color_r = 236;
        color_g = 236;
        color_b = 236;
        break;
    case (41):
        color_r = 205;
        color_g = 84;
        color_b = 75;
        break;
    case (42):
        color_r = 193;
        color_g = 223;
        color_b = 240;
        break;
    case (43):
        color_r = 123;
        color_g = 182;
        color_b = 232;
        break;
    case (44):
        color_r = 247;
        color_g = 241;
        color_b = 141;
        break;
    case (45):
        color_r = 180;
        color_g = 210;
        color_b = 228;
        break;
    case (47):
        color_r = 217;
        color_g = 133;
        color_b = 108;
        break;
    case (48):
        color_r = 132;
        color_g = 182;
        color_b = 141;
        break;
    case (49):
        color_r = 248;
        color_g = 241;
        color_b = 132;
        break;
    case (50):
        color_r = 236;
        color_g = 232;
        color_b = 222;
        break;
    case (100):
        color_r = 238;
        color_g = 196;
        color_b = 182;
        break;
    case (101):
        color_r = 218;
        color_g = 134;
        color_b = 122;
        break;
    case (102):
        color_r = 110;
        color_g = 153;
        color_b = 202;
        break;
    case (103):
        color_r = 199;
        color_g = 193;
        color_b = 183;
        break;
    case (104):
        color_r = 107;
        color_g = 50;
        color_b = 124;
        break;
    case (105):
        color_r = 226;
        color_g = 155;
        color_b = 64;
        break;
    case (106):
        color_r = 218;
        color_g = 133;
        color_b = 65;
        break;
    case (107):
        color_r = 0;
        color_g = 143;
        color_b = 156;
        break;
    case (108):
        color_r = 104;
        color_g = 92;
        color_b = 67;
        break;
    case (110):
        color_r = 67;
        color_g = 84;
        color_b = 147;
        break;
    case (111):
        color_r = 191;
        color_g = 183;
        color_b = 177;
        break;
    case (112):
        color_r = 104;
        color_g = 116;
        color_b = 172;
        break;
    case (113):
        color_r = 228;
        color_g = 173;
        color_b = 200;
        break;
    case (115):
        color_r = 199;
        color_g = 210;
        color_b = 60;
        break;
    case (116):
        color_r = 85;
        color_g = 165;
        color_b = 175;
        break;
    case (118):
        color_r = 183;
        color_g = 215;
        color_b = 213;
        break;
    case (119):
        color_r = 164;
        color_g = 189;
        color_b = 71;
        break;
    case (120):
        color_r = 217;
        color_g = 228;
        color_b = 167;
        break;
    case (121):
        color_r = 231;
        color_g = 172;
        color_b = 88;
        break;
    case (123):
        color_r = 211;
        color_g = 111;
        color_b = 76;
        break;
    case (124):
        color_r = 146;
        color_g = 57;
        color_b = 120;
        break;
    case (125):
        color_r = 234;
        color_g = 184;
        color_b = 146;
        break;
    case (126):
        color_r = 165;
        color_g = 165;
        color_b = 203;
        break;
    case (127):
        color_r = 220;
        color_g = 188;
        color_b = 129;
        break;
    case (128):
        color_r = 174;
        color_g = 122;
        color_b = 89;
        break;
    case (131):
        color_r = 156;
        color_g = 163;
        color_b = 168;
        break;
    case (133):
        color_r = 213;
        color_g = 115;
        color_b = 61;
        break;
    case (134):
        color_r = 216;
        color_g = 221;
        color_b = 86;
        break;
    case (135):
        color_r = 116;
        color_g = 134;
        color_b = 157;
        break;
    case (136):
        color_r = 135;
        color_g = 124;
        color_b = 144;
        break;
    case (137):
        color_r = 224;
        color_g = 152;
        color_b = 100;
        break;
    case (138):
        color_r = 149;
        color_g = 138;
        color_b = 115;
        break;
    case (140):
        color_r = 32;
        color_g = 58;
        color_b = 86;
        break;
    case (141):
        color_r = 39;
        color_g = 70;
        color_b = 45;
        break;
    case (143):
        color_r = 207;
        color_g = 226;
        color_b = 247;
        break;
    case (145):
        color_r = 121;
        color_g = 136;
        color_b = 161;
        break;
    case (146):
        color_r = 149;
        color_g = 142;
        color_b = 163;
        break;
    case (147):
        color_r = 147;
        color_g = 135;
        color_b = 103;
        break;
    case (148):
        color_r = 87;
        color_g = 88;
        color_b = 87;
        break;
    case (149):
        color_r = 22;
        color_g = 29;
        color_b = 50;
        break;
    case (150):
        color_r = 171;
        color_g = 173;
        color_b = 172;
        break;
    case (151):
        color_r = 120;
        color_g = 144;
        color_b = 130;
        break;
    case (153):
        color_r = 149;
        color_g = 121;
        color_b = 119;
        break;
    case (154):
        color_r = 123;
        color_g = 46;
        color_b = 47;
        break;
    case (157):
        color_r = 255;
        color_g = 246;
        color_b = 123;
        break;
    case (158):
        color_r = 225;
        color_g = 164;
        color_b = 194;
        break;
    case (168):
        color_r = 117;
        color_g = 108;
        color_b = 98;
        break;
    case (176):
        color_r = 151;
        color_g = 105;
        color_b = 91;
        break;
    case (178):
        color_r = 180;
        color_g = 132;
        color_b = 85;
        break;
    case (179):
        color_r = 137;
        color_g = 135;
        color_b = 136;
        break;
    case (180):
        color_r = 215;
        color_g = 169;
        color_b = 75;
        break;
    case (190):
        color_r = 249;
        color_g = 214;
        color_b = 46;
        break;
    case (191):
        color_r = 232;
        color_g = 171;
        color_b = 45;
        break;
    case (192):
        color_r = 105;
        color_g = 64;
        color_b = 40;
        break;
    case (193):
        color_r = 207;
        color_g = 96;
        color_b = 36;
        break;
    case (194):
        color_r = 163;
        color_g = 162;
        color_b = 165;
        break;
    case (195):
        color_r = 70;
        color_g = 103;
        color_b = 164;
        break;
    case (196):
        color_r = 35;
        color_g = 71;
        color_b = 139;
        break;
    case (198):
        color_r = 142;
        color_g = 66;
        color_b = 133;
        break;
    case (199):
        color_r = 99;
        color_g = 95;
        color_b = 98;
        break;
    case (200):
        color_r = 130;
        color_g = 138;
        color_b = 93;
        break;
    case (208):
        color_r = 229;
        color_g = 228;
        color_b = 223;
        break;
    case (209):
        color_r = 176;
        color_g = 142;
        color_b = 68;
        break;
    case (210):
        color_r = 112;
        color_g = 149;
        color_b = 120;
        break;
    case (211):
        color_r = 121;
        color_g = 181;
        color_b = 181;
        break;
    case (212):
        color_r = 159;
        color_g = 195;
        color_b = 233;
        break;
    case (213):
        color_r = 108;
        color_g = 129;
        color_b = 183;
        break;
    case (216):
        color_r = 143;
        color_g = 76;
        color_b = 42;
        break;
    case (217):
        color_r = 124;
        color_g = 92;
        color_b = 70;
        break;
    case (218):
        color_r = 150;
        color_g = 112;
        color_b = 159;
        break;
    case (219):
        color_r = 107;
        color_g = 98;
        color_b = 155;
        break;
    case (220):
        color_r = 167;
        color_g = 169;
        color_b = 206;
        break;
    case (221):
        color_r = 205;
        color_g = 98;
        color_b = 152;
        break;
    case (222):
        color_r = 228;
        color_g = 173;
        color_b = 200;
        break;
    case (223):
        color_r = 220;
        color_g = 144;
        color_b = 149;
        break;
    case (224):
        color_r = 240;
        color_g = 213;
        color_b = 160;
        break;
    case (225):
        color_r = 235;
        color_g = 184;
        color_b = 127;
        break;
    case (226):
        color_r = 253;
        color_g = 234;
        color_b = 141;
        break;
    case (232):
        color_r = 125;
        color_g = 187;
        color_b = 221;
        break;
    case (268):
        color_r = 52;
        color_g = 43;
        color_b = 117;
        break;
    case (301):
        color_r = 80;
        color_g = 109;
        color_b = 84;
        break;
    case (302):
        color_r = 91;
        color_g = 93;
        color_b = 105;
        break;
    case (303):
        color_r = 0;
        color_g = 16;
        color_b = 176;
        break;
    case (304):
        color_r = 44;
        color_g = 101;
        color_b = 29;
        break;
    case (305):
        color_r = 82;
        color_g = 124;
        color_b = 174;
        break;
    case (306):
        color_r = 51;
        color_g = 88;
        color_b = 130;
        break;
    case (307):
        color_r = 16;
        color_g = 42;
        color_b = 220;
        break;
    case (308):
        color_r = 61;
        color_g = 21;
        color_b = 133;
        break;
    case (309):
        color_r = 52;
        color_g = 142;
        color_b = 64;
        break;
    case (310):
        color_r = 91;
        color_g = 154;
        color_b = 76;
        break;
    case (311):
        color_r = 159;
        color_g = 161;
        color_b = 172;
        break;
    case (312):
        color_r = 89;
        color_g = 34;
        color_b = 89;
        break;
    case (313):
        color_r = 31;
        color_g = 128;
        color_b = 29;
        break;
    case (314):
        color_r = 159;
        color_g = 173;
        color_b = 192;
        break;
    case (315):
        color_r = 9;
        color_g = 137;
        color_b = 207;
        break;
    case (316):
        color_r = 123;
        color_g = 0;
        color_b = 123;
        break;
    case (317):
        color_r = 124;
        color_g = 156;
        color_b = 107;
        break;
    case (318):
        color_r = 138;
        color_g = 171;
        color_b = 133;
        break;
    case (319):
        color_r = 185;
        color_g = 196;
        color_b = 177;
        break;
    case (320):
        color_r = 202;
        color_g = 203;
        color_b = 209;
        break;
    case (321):
        color_r = 167;
        color_g = 94;
        color_b = 155;
        break;
    case (322):
        color_r = 123;
        color_g = 47;
        color_b = 123;
        break;
    case (323):
        color_r = 148;
        color_g = 190;
        color_b = 129;
        break;
    case (324):
        color_r = 168;
        color_g = 189;
        color_b = 153;
        break;
    case (325):
        color_r = 223;
        color_g = 223;
        color_b = 222;
        break;
    case (326):
        color_r = 218;
        color_g = 220;
        color_b = 225;
        break;
    case (327):
        color_r = 151;
        color_g = 0;
        color_b = 0;
        break;
    case (328):
        color_r = 177;
        color_g = 229;
        color_b = 166;
        break;
    case (329):
        color_r = 152;
        color_g = 194;
        color_b = 219;
        break;
    case (330):
        color_r = 255;
        color_g = 152;
        color_b = 220;
        break;
    case (331):
        color_r = 255;
        color_g = 89;
        color_b = 89;
        break;
    case (332):
        color_r = 117;
        color_g = 0;
        color_b = 0;
        break;
    case (333):
        color_r = 239;
        color_g = 184;
        color_b = 56;
        break;
    case (334):
        color_r = 248;
        color_g = 217;
        color_b = 109;
        break;
    case (335):
        color_r = 231;
        color_g = 231;
        color_b = 236;
        break;
    case (336):
        color_r = 199;
        color_g = 212;
        color_b = 228;
        break;
    case (337):
        color_r = 255;
        color_g = 148;
        color_b = 148;
        break;
    case (338):
        color_r = 190;
        color_g = 104;
        color_b = 98;
        break;
    case (339):
        color_r = 86;
        color_g = 36;
        color_b = 36;
        break;
    case (340):
        color_r = 241;
        color_g = 231;
        color_b = 199;
        break;
    case (341):
        color_r = 254;
        color_g = 243;
        color_b = 187;
        break;
    case (342):
        color_r = 224;
        color_g = 178;
        color_b = 208;
        break;
    case (343):
        color_r = 212;
        color_g = 144;
        color_b = 189;
        break;
    case (344):
        color_r = 150;
        color_g = 85;
        color_b = 85;
        break;
    case (345):
        color_r = 143;
        color_g = 76;
        color_b = 42;
        break;
    case (346):
        color_r = 211;
        color_g = 190;
        color_b = 150;
        break;
    case (347):
        color_r = 226;
        color_g = 220;
        color_b = 188;
        break;
    case (348):
        color_r = 237;
        color_g = 234;
        color_b = 234;
        break;
    case (349):
        color_r = 233;
        color_g = 218;
        color_b = 218;
        break;
    case (350):
        color_r = 136;
        color_g = 62;
        color_b = 62;
        break;
    case (351):
        color_r = 188;
        color_g = 155;
        color_b = 93;
        break;
    case (352):
        color_r = 199;
        color_g = 172;
        color_b = 120;
        break;
    case (353):
        color_r = 202;
        color_g = 191;
        color_b = 163;
        break;
    case (354):
        color_r = 187;
        color_g = 179;
        color_b = 178;
        break;
    case (355):
        color_r = 108;
        color_g = 88;
        color_b = 75;
        break;
    case (356):
        color_r = 160;
        color_g = 132;
        color_b = 79;
        break;
    case (357):
        color_r = 149;
        color_g = 137;
        color_b = 136;
        break;
    case (358):
        color_r = 171;
        color_g = 168;
        color_b = 158;
        break;
    case (359):
        color_r = 175;
        color_g = 148;
        color_b = 131;
        break;
    case (360):
        color_r = 150;
        color_g = 103;
        color_b = 102;
        break;
    case (361):
        color_r = 86;
        color_g = 66;
        color_b = 54;
        break;
    case (362):
        color_r = 126;
        color_g = 104;
        color_b = 63;
        break;
    case (363):
        color_r = 105;
        color_g = 102;
        color_b = 92;
        break;
    case (364):
        color_r = 90;
        color_g = 76;
        color_b = 66;
        break;
    case (365):
        color_r = 106;
        color_g = 57;
        color_b = 9;
        break;
    case (1001):
        color_r = 248;
        color_g = 248;
        color_b = 248;
        break;
    case (1002):
        color_r = 205;
        color_g = 205;
        color_b = 205;
        break;
    case (1003):
        color_r = 17;
        color_g = 17;
        color_b = 17;
        break;
    case (1004):
        color_r = 255;
        color_g = 0;
        color_b = 0;
        break;
    case (1005):
        color_r = 255;
        color_g = 175;
        color_b = 0;
        break;
    case (1006):
        color_r = 180;
        color_g = 128;
        color_b = 255;
        break;
    case (1007):
        color_r = 163;
        color_g = 75;
        color_b = 75;
        break;
    case (1008):
        color_r = 193;
        color_g = 190;
        color_b = 66;
        break;
    case (1009):
        color_r = 255;
        color_g = 255;
        color_b = 0;
        break;
    case (1010):
        color_r = 0;
        color_g = 0;
        color_b = 255;
        break;
    case (1011):
        color_r = 0;
        color_g = 32;
        color_b = 96;
        break;
    case (1012):
        color_r = 33;
        color_g = 84;
        color_b = 185;
        break;
    case (1013):
        color_r = 4;
        color_g = 175;
        color_b = 236;
        break;
    case (1014):
        color_r = 170;
        color_g = 85;
        color_b = 0;
        break;
    case (1015):
        color_r = 170;
        color_g = 0;
        color_b = 170;
        break;
    case (1016):
        color_r = 255;
        color_g = 102;
        color_b = 204;
        break;
    case (1017):
        color_r = 255;
        color_g = 175;
        color_b = 0;
        break;
    case (1018):
        color_r = 18;
        color_g = 238;
        color_b = 212;
        break;
    case (1019):
        color_r = 0;
        color_g = 255;
        color_b = 255;
        break;
    case (1020):
        color_r = 0;
        color_g = 255;
        color_b = 0;
        break;
    case (1021):
        color_r = 58;
        color_g = 125;
        color_b = 21;
        break;
    case (1022):
        color_r = 127;
        color_g = 142;
        color_b = 100;
        break;
    case (1023):
        color_r = 140;
        color_g = 91;
        color_b = 159;
        break;
    case (1024):
        color_r = 175;
        color_g = 221;
        color_b = 255;
        break;
    case (1025):
        color_r = 255;
        color_g = 201;
        color_b = 201;
        break;
    case (1026):
        color_r = 177;
        color_g = 167;
        color_b = 255;
        break;
    case (1027):
        color_r = 159;
        color_g = 243;
        color_b = 233;
        break;
    case (1028):
        color_r = 204;
        color_g = 255;
        color_b = 204;
        break;
    case (1029):
        color_r = 255;
        color_g = 255;
        color_b = 204;
        break;
    case (1030):
        color_r = 255;
        color_g = 204;
        color_b = 153;
        break;
    case (1031):
        color_r = 98;
        color_g = 37;
        color_b = 209;
        break;
    case (1032):
        color_r = 255;
        color_g = 0;
        color_b = 191;
        break;
	}
    
    // User should ALWAYS do 0 for fastest speed, but for testing, eg just wanting to get something working, doing 1, 2, or 3 is validish.
    switch(returnType){
        default:
        case(0):
            return ((color_r << 16) | (color_g << 8) | color_b);
        case(1):
            return color_r;
        case(2):
            return color_g;
        case(3):
            return color_b;
    }

    // Too all professional programmers, I'm sorry about THIS BIG ASS ROUTINE.
    // I plan to eventually make it 3 large arrays that get accessed instead of this switch bullshit.
    // Not like it matters really, since it wont be called too many times per frame, if at all.
}

// Get the color I want
int getHex_value(unsigned int hexColor, unsigned char component) {
    unsigned char colorValue = -69; // Invalid number.

    switch (component) {
        case 0: // r
            colorValue = (hexColor >> 16) & 0xFF;
            break;
        case 1: // g
            colorValue = (hexColor >> 8) & 0xFF;
            break;
        case 2: // b
            colorValue = hexColor & 0xFF;
            break;
    }

    return colorValue;
}