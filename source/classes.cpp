#include "classes.h"
#include "mathHelper.h"

const float GRAVITY = 9.8f;  // acceleration due to gravity
const float TIME_STEP = 0.01f;  // time step for simulation

void glVertex3(float x,float y,float z) {
	glVertex3f(x,y,z);
}

void SpecialMesh::headMesh() {
	//glPolyFmt(POLY_ALPHA(31-int(alpha*31)) | POLY_CULL_BACK  | POLY_FORMAT_LIGHT0 | POLY_FOG);
	
	glBegin(GL_TRIANGLE);
		glVertex3f(-0.932322,0.596227,0.399221);
		glVertex3f(-0.640764,-0.680105,0.763315);
		glVertex3f(-0.480241,0.605489,0.898445);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.098312,0.604673,-0.999773);
		glVertex3f(0.150962,-0.650408,-0.990247);
		glVertex3f(-0.22392,-0.648345,-0.979736);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.996989,0.596266,0.186017);
		glVertex3f(0.980003,-0.64308,-0.214305);
		glVertex3f(0.891344,0.604282,-0.50115);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.46681,1.001006,0.438334);
		glVertex3f(0.692168,0.993242,-0.039351);
		glVertex3f(0.281587,0.989665,-0.627556);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.186015,0.596253,0.996994);
		glVertex3f(0.58222,-0.653549,0.816662);
		glVertex3f(0.714215,0.614959,0.71421);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.891344,0.604282,-0.50115);
		glVertex3f(0.853584,-0.654746,-0.521982);
		glVertex3f(0.547863,-0.663036,-0.837863);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.480241,0.605489,0.898445);
		glVertex3f(-0.640764,-0.680105,0.763315);
		glVertex3f(-0.18976,-0.646655,0.988061);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.098312,0.604673,-0.999773);
		glVertex3f(0.268884,0.808944,-0.88636);
		glVertex3f(0.386682,0.598722,-0.933498);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.298104,0.811837,-0.891479);
		glVertex3f(-0.098312,0.604673,-0.999773);
		glVertex3f(-0.473573,0.595546,-0.886123);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.631663,0.955669,0.440243);
		glVertex3f(0.816878,0.808942,0.43663);
		glVertex3f(0.927452,0.813011,-0.00863);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.186015,0.596253,0.996994);
		glVertex3f(-0.271929,0.811363,0.896421);
		glVertex3f(-0.480241,0.605489,0.898445);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.761151,0.809834,0.536443);
		glVertex3f(-0.300621,0.952344,0.694293);
		glVertex3f(-0.667179,0.954409,0.361812);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.547863,-0.663036,-0.837863);
		glVertex3f(0.318952,-0.885314,-0.78363);
		glVertex3f(0.150962,-0.650408,-0.990247);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.927452,0.813011,-0.00863);
		glVertex3f(0.996989,0.596266,0.186017);
		glVertex3f(0.891344,0.604282,-0.50115);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.18976,-0.646655,0.988061);
		glVertex3f(-0.400676,-0.891997,0.74961);
		glVertex3f(0.245288,-0.89031,0.808608);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.816878,0.808942,0.43663);
		glVertex3f(0.714215,0.614959,0.71421);
		glVertex3f(0.996989,0.596266,0.186017);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.98674,-0.651095,0.163856);
		glVertex3f(0.749797,-0.887712,0.407642);
		glVertex3f(0.776975,-0.906855,-0.321834);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.927452,0.813011,-0.00863);
		glVertex3f(0.692168,0.993242,-0.039351);
		glVertex3f(0.631663,0.955669,0.440243);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.714215,0.614959,0.71421);
		glVertex3f(0.816878,0.808942,0.43663);
		glVertex3f(0.419592,0.811837,0.841155);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.631663,0.955669,0.440243);
		glVertex3f(0.692168,0.993242,-0.039351);
		glVertex3f(0.144219,0.987834,0.677821);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.761151,0.809834,0.536443);
		glVertex3f(-0.932322,0.596227,0.399221);
		glVertex3f(-0.480241,0.605489,0.898445);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.268884,0.808944,-0.88636);
		glVertex3f(0.281587,0.989665,-0.627556);
		glVertex3f(0.740334,0.807581,-0.582152);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.745147,0.740689,-0.624636);
		glVertex3f(-0.298104,0.811837,-0.891479);
		glVertex3f(-0.473573,0.595546,-0.886123);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.776975,-0.906855,-0.321834);
		glVertex3f(0.068047,-1.001798,-0.690904);
		glVertex3f(0.318952,-0.885314,-0.78363);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.186015,0.596253,0.996994);
		glVertex3f(0.419592,0.811837,0.841155);
		glVertex3f(-0.271929,0.811363,0.896421);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.692168,0.993242,-0.039351);
		glVertex3f(0.927452,0.813011,-0.00863);
		glVertex3f(0.740334,0.807581,-0.582152);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.180128,-0.885217,-0.824201);
		glVertex3f(-0.576616,-0.666864,-0.813833);
		glVertex3f(-0.22392,-0.648345,-0.979736);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.776975,-0.906855,-0.321834);
		glVertex3f(0.577425,-1.0004,0.361353);
		glVertex3f(0.626238,-1.000449,-0.259399);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.58222,-0.653549,0.816662);
		glVertex3f(0.749797,-0.887712,0.407642);
		glVertex3f(0.853533,-0.658165,0.519577);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.180128,-0.885217,-0.824201);
		glVertex3f(-0.22392,-0.648345,-0.979736);
		glVertex3f(0.150962,-0.650408,-0.990247);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.150962,-0.650408,-0.990247);
		glVertex3f(0.318952,-0.885314,-0.78363);
		glVertex3f(-0.180128,-0.885217,-0.824201);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.386682,0.598722,-0.933498);
		glVertex3f(0.268884,0.808944,-0.88636);
		glVertex3f(0.740334,0.807581,-0.582152);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.714215,0.614959,0.71421);
		glVertex3f(0.419592,0.811837,0.841155);
		glVertex3f(0.186015,0.596253,0.996994);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.271929,0.811363,0.896421);
		glVertex3f(0.144219,0.987834,0.677821);
		glVertex3f(-0.300621,0.952344,0.694293);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.576616,-0.666864,-0.813833);
		glVertex3f(-0.661914,-0.895848,-0.523041);
		glVertex3f(-0.847554,-0.645006,-0.541366);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.980003,-0.64308,-0.214305);
		glVertex3f(0.776975,-0.906855,-0.321834);
		glVertex3f(0.853584,-0.654746,-0.521982);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.419592,0.811837,0.841155);
		glVertex3f(0.631663,0.955669,0.440243);
		glVertex3f(0.144219,0.987834,0.677821);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.853584,-0.654746,-0.521982);
		glVertex3f(0.776975,-0.906855,-0.321834);
		glVertex3f(0.547863,-0.663036,-0.837863);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.419592,0.811837,0.841155);
		glVertex3f(0.144219,0.987834,0.677821);
		glVertex3f(-0.271929,0.811363,0.896421);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.058913,0.98919,-0.68411);
		glVertex3f(0.268884,0.808944,-0.88636);
		glVertex3f(-0.298104,0.811837,-0.891479);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.46681,1.001006,0.438334);
		glVertex3f(-0.667179,0.954409,0.361812);
		glVertex3f(-0.300621,0.952344,0.694293);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.740334,0.807581,-0.582152);
		glVertex3f(0.553472,0.989602,-0.403198);
		glVertex3f(0.692168,0.993242,-0.039351);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.068047,-1.001798,-0.690904);
		glVertex3f(-0.661914,-0.895848,-0.523041);
		glVertex3f(-0.180128,-0.885217,-0.824201);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-1.003376,-0.662878,-0.012957);
		glVertex3f(-0.661914,-0.895848,-0.523041);
		glVertex3f(-0.834282,-0.895261,0.16595);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.318952,-0.885314,-0.78363);
		glVertex3f(0.068047,-1.001798,-0.690904);
		glVertex3f(-0.180128,-0.885217,-0.824201);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.400676,-0.891997,0.74961);
		glVertex3f(0.130127,-1.000219,0.654195);
		glVertex3f(0.245288,-0.89031,0.808608);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.934972,0.816881,-0.074925);
		glVertex3f(-0.677363,0.983464,-0.216399);
		glVertex3f(-0.745147,0.740689,-0.624636);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.853533,-0.658165,0.519577);
		glVertex3f(0.749797,-0.887712,0.407642);
		glVertex3f(0.98674,-0.651095,0.163856);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.244438,-0.658156,0.970726);
		glVertex3f(0.245288,-0.89031,0.808608);
		glVertex3f(0.58222,-0.653549,0.816662);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.245288,-0.89031,0.808608);
		glVertex3f(0.130127,-1.000219,0.654195);
		glVertex3f(0.577425,-1.0004,0.361353);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.407554,0.953185,-0.636153);
		glVertex3f(-0.298104,0.811837,-0.891479);
		glVertex3f(-0.745147,0.740689,-0.624636);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.661914,-0.895848,-0.523041);
		glVertex3f(-0.671198,-1.000598,0.133513);
		glVertex3f(-0.834282,-0.895261,0.16595);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.245288,-0.89031,0.808608);
		glVertex3f(0.244438,-0.658156,0.970726);
		glVertex3f(-0.18976,-0.646655,0.988061);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.912534,-0.652287,0.421588);
		glVertex3f(-0.400676,-0.891997,0.74961);
		glVertex3f(-0.640764,-0.680105,0.763315);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.816878,0.808942,0.43663);
		glVertex3f(0.631663,0.955669,0.440243);
		glVertex3f(0.419592,0.811837,0.841155);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.400676,-0.891997,0.74961);
		glVertex3f(-0.671198,-1.000598,0.133513);
		glVertex3f(-0.315652,-1.000255,0.590543);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.996989,0.596266,0.186017);
		glVertex3f(0.853533,-0.658165,0.519577);
		glVertex3f(0.98674,-0.651095,0.163856);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.098312,0.604673,-0.999773);
		glVertex3f(-0.298104,0.811837,-0.891479);
		glVertex3f(0.268884,0.808944,-0.88636);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.990832,0.615903,-0.195534);
		glVertex3f(-0.847554,-0.645006,-0.541366);
		glVertex3f(-1.003376,-0.662878,-0.012957);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.386682,0.598722,-0.933498);
		glVertex3f(0.891344,0.604282,-0.50115);
		glVertex3f(0.547863,-0.663036,-0.837863);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.186015,0.596253,0.996994);
		glVertex3f(0.244438,-0.658156,0.970726);
		glVertex3f(0.58222,-0.653549,0.816662);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.996989,0.596266,0.186017);
		glVertex3f(0.98674,-0.651095,0.163856);
		glVertex3f(0.980003,-0.64308,-0.214305);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.891344,0.604282,-0.50115);
		glVertex3f(0.980003,-0.64308,-0.214305);
		glVertex3f(0.853584,-0.654746,-0.521982);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.996989,0.596266,0.186017);
		glVertex3f(0.714215,0.614959,0.71421);
		glVertex3f(0.853533,-0.658165,0.519577);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.932322,0.596227,0.399221);
		glVertex3f(-1.003376,-0.662878,-0.012957);
		glVertex3f(-0.912534,-0.652287,0.421588);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.714215,0.614959,0.71421);
		glVertex3f(0.58222,-0.653549,0.816662);
		glVertex3f(0.853533,-0.658165,0.519577);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.186015,0.596253,0.996994);
		glVertex3f(-0.480241,0.605489,0.898445);
		glVertex3f(-0.18976,-0.646655,0.988061);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.386682,0.598722,-0.933498);
		glVertex3f(0.547863,-0.663036,-0.837863);
		glVertex3f(0.150962,-0.650408,-0.990247);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.745147,0.740689,-0.624636);
		glVertex3f(-0.576616,-0.666864,-0.813833);
		glVertex3f(-0.847554,-0.645006,-0.541366);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.932322,0.596227,0.399221);
		glVertex3f(-0.990832,0.615903,-0.195534);
		glVertex3f(-1.003376,-0.662878,-0.012957);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.098312,0.604673,-0.999773);
		glVertex3f(0.386682,0.598722,-0.933498);
		glVertex3f(0.150962,-0.650408,-0.990247);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.990832,0.615903,-0.195534);
		glVertex3f(-0.745147,0.740689,-0.624636);
		glVertex3f(-0.847554,-0.645006,-0.541366);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.745147,0.740689,-0.624636);
		glVertex3f(-0.473573,0.595546,-0.886123);
		glVertex3f(-0.576616,-0.666864,-0.813833);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.473573,0.595546,-0.886123);
		glVertex3f(-0.098312,0.604673,-0.999773);
		glVertex3f(-0.22392,-0.648345,-0.979736);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.400676,-0.891997,0.74961);
		glVertex3f(-0.315652,-1.000255,0.590543);
		glVertex3f(0.130127,-1.000219,0.654195);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.281587,0.989665,-0.627556);
		glVertex3f(0.553472,0.989602,-0.403198);
		glVertex3f(0.740334,0.807581,-0.582152);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.934972,0.816881,-0.074925);
		glVertex3f(-0.761151,0.809834,0.536443);
		glVertex3f(-0.667179,0.954409,0.361812);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.677363,0.983464,-0.216399);
		glVertex3f(-0.058913,0.98919,-0.68411);
		glVertex3f(-0.407554,0.953185,-0.636153);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.186015,0.596253,0.996994);
		glVertex3f(-0.18976,-0.646655,0.988061);
		glVertex3f(0.244438,-0.658156,0.970726);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.18976,-0.646655,0.988061);
		glVertex3f(-0.640764,-0.680105,0.763315);
		glVertex3f(-0.400676,-0.891997,0.74961);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.740334,0.807581,-0.582152);
		glVertex3f(0.927452,0.813011,-0.00863);
		glVertex3f(0.891344,0.604282,-0.50115);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.980003,-0.64308,-0.214305);
		glVertex3f(0.98674,-0.651095,0.163856);
		glVertex3f(0.776975,-0.906855,-0.321834);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.990832,0.615903,-0.195534);
		glVertex3f(-0.934972,0.816881,-0.074925);
		glVertex3f(-0.745147,0.740689,-0.624636);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.180128,-0.885217,-0.824201);
		glVertex3f(-0.661914,-0.895848,-0.523041);
		glVertex3f(-0.576616,-0.666864,-0.813833);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.749797,-0.887712,0.407642);
		glVertex3f(0.245288,-0.89031,0.808608);
		glVertex3f(0.577425,-1.0004,0.361353);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.661914,-0.895848,-0.523041);
		glVertex3f(-0.517694,-1.00019,-0.424859);
		glVertex3f(-0.671198,-1.000598,0.133513);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.776975,-0.906855,-0.321834);
		glVertex3f(0.749797,-0.887712,0.407642);
		glVertex3f(0.577425,-1.0004,0.361353);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.400676,-0.891997,0.74961);
		glVertex3f(-0.834282,-0.895261,0.16595);
		glVertex3f(-0.671198,-1.000598,0.133513);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-1.003376,-0.662878,-0.012957);
		glVertex3f(-0.847554,-0.645006,-0.541366);
		glVertex3f(-0.661914,-0.895848,-0.523041);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.407554,0.953185,-0.636153);
		glVertex3f(-0.058913,0.98919,-0.68411);
		glVertex3f(-0.298104,0.811837,-0.891479);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.547863,-0.663036,-0.837863);
		glVertex3f(0.776975,-0.906855,-0.321834);
		glVertex3f(0.318952,-0.885314,-0.78363);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.677363,0.983464,-0.216399);
		glVertex3f(-0.407554,0.953185,-0.636153);
		glVertex3f(-0.745147,0.740689,-0.624636);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.891344,0.604282,-0.50115);
		glVertex3f(0.386682,0.598722,-0.933498);
		glVertex3f(0.740334,0.807581,-0.582152);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.776975,-0.906855,-0.321834);
		glVertex3f(0.626238,-1.000449,-0.259399);
		glVertex3f(0.068047,-1.001798,-0.690904);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.912534,-0.652287,0.421588);
		glVertex3f(-0.834282,-0.895261,0.16595);
		glVertex3f(-0.400676,-0.891997,0.74961);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.144219,0.987834,0.677821);
		glVertex3f(-0.46681,1.001006,0.438334);
		glVertex3f(-0.300621,0.952344,0.694293);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.553472,0.989602,-0.403198);
		glVertex3f(0.281587,0.989665,-0.627556);
		glVertex3f(0.692168,0.993242,-0.039351);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.058913,0.98919,-0.68411);
		glVertex3f(-0.677363,0.983464,-0.216399);
		glVertex3f(0.281587,0.989665,-0.627556);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.46681,1.001006,0.438334);
		glVertex3f(0.144219,0.987834,0.677821);
		glVertex3f(0.692168,0.993242,-0.039351);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.677363,0.983464,-0.216399);
		glVertex3f(-0.46681,1.001006,0.438334);
		glVertex3f(0.281587,0.989665,-0.627556);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.473573,0.595546,-0.886123);
		glVertex3f(-0.22392,-0.648345,-0.979736);
		glVertex3f(-0.576616,-0.666864,-0.813833);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.480241,0.605489,0.898445);
		glVertex3f(-0.271929,0.811363,0.896421);
		glVertex3f(-0.761151,0.809834,0.536443);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.912534,-0.652287,0.421588);
		glVertex3f(-1.003376,-0.662878,-0.012957);
		glVertex3f(-0.834282,-0.895261,0.16595);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.577425,-1.0004,0.361353);
		glVertex3f(-0.671198,-1.000598,0.133513);
		glVertex3f(-0.517694,-1.00019,-0.424859);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.932322,0.596227,0.399221);
		glVertex3f(-0.761151,0.809834,0.536443);
		glVertex3f(-0.934972,0.816881,-0.074925);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.058913,0.98919,-0.68411);
		glVertex3f(0.281587,0.989665,-0.627556);
		glVertex3f(0.268884,0.808944,-0.88636);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.58222,-0.653549,0.816662);
		glVertex3f(0.245288,-0.89031,0.808608);
		glVertex3f(0.749797,-0.887712,0.407642);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.990832,0.615903,-0.195534);
		glVertex3f(-0.932322,0.596227,0.399221);
		glVertex3f(-0.934972,0.816881,-0.074925);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.677363,0.983464,-0.216399);
		glVertex3f(-0.667179,0.954409,0.361812);
		glVertex3f(-0.46681,1.001006,0.438334);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.934972,0.816881,-0.074925);
		glVertex3f(-0.667179,0.954409,0.361812);
		glVertex3f(-0.677363,0.983464,-0.216399);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.761151,0.809834,0.536443);
		glVertex3f(-0.271929,0.811363,0.896421);
		glVertex3f(-0.300621,0.952344,0.694293);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.068047,-1.001798,-0.690904);
		glVertex3f(-0.517694,-1.00019,-0.424859);
		glVertex3f(-0.661914,-0.895848,-0.523041);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.996989,0.596266,0.186017);
		glVertex3f(0.927452,0.813011,-0.00863);
		glVertex3f(0.816878,0.808942,0.43663);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.130127,-1.000219,0.654195);
		glVertex3f(-0.315652,-1.000255,0.590543);
		glVertex3f(0.577425,-1.0004,0.361353);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.517694,-1.00019,-0.424859);
		glVertex3f(0.068047,-1.001798,-0.690904);
		glVertex3f(0.626238,-1.000449,-0.259399);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.315652,-1.000255,0.590543);
		glVertex3f(-0.671198,-1.000598,0.133513);
		glVertex3f(0.577425,-1.0004,0.361353);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(0.626238,-1.000449,-0.259399);
		glVertex3f(0.577425,-1.0004,0.361353);
		glVertex3f(-0.517694,-1.00019,-0.424859);
		glEnd();
		glBegin(GL_TRIANGLE);
		glVertex3f(-0.932322,0.596227,0.399221);
		glVertex3f(-0.912534,-0.652287,0.421588);
		glVertex3f(-0.640764,-0.680105,0.763315);
	glEnd();
}

void SpecialMesh::renderMesh(int meshType) {
	
}

void Object::calculateBrickColor(int value) {
	//printf("Current Value: %d\n", value);
	switch(value) {
		//White to black
		
		/*White*/
		case(1):
			color_r = 242;
			color_g = 243;
			color_b = 242;
		break;
		
		case(208):
			color_r = 229;
			color_g = 228;
			color_b = 222;
		break;
		
		case(194):
			color_r = 163;
			color_g = 162;
			color_b = 164;
		break;
		
		case(199):
			color_r = 99;
			color_g = 95;
			color_b = 97;
		break;
		
		case(26):
			color_r = 27;
			color_g = 42;
			color_b = 52;
		break;
		/*Black*/
		
		//Red to bright yellow
		
		/*Red*/
		case(21):
			color_r = 196;
			color_g = 40;
			color_b = 27;
		break;
		
		case(24):
			color_r = 245;
			color_g = 205;
			color_b = 47;
		break;
		
		case(226):
			color_r = 253;
			color_g = 234;
			color_b = 140;
		break;
		/*Bright Yellow*/
		
		//Blues
		case(23):
			color_r = 13;
			color_g = 105;
			color_b = 171;
		break;
		
		case(107):
			color_r = 0;
			color_g = 143;
			color_b = 155;
		break;
		
		case(102):
			color_r = 110;
			color_g = 153;
			color_b = 201;
		break;
		
		case(11):
			color_r = 128;
			color_g = 187;
			color_b = 219;
		break;
		
		case(45):
			color_r = 180;
			color_g = 210;
			color_b = 227;
		break;
		
		case(135):
			color_r = 116;
			color_g = 134;
			color_b = 156;
		break;
		//End of blues
		
		//Oranges
		case(106):
			color_r = 218;
			color_g = 133;
			color_b = 64;
		break;
		
		case(105):
			color_r = 226;
			color_g = 155;
			color_b = 105;
		break;
		//End of Oranges
		
		/* Half Way Mark */
		
		/*Greens*/
		case(141):
			color_r = 39;
			color_g = 70;
			color_b = 44;
		break;
		
		case(28):
			color_r = 40;
			color_g = 127;
			color_b = 70;
		break;
		
		case(37):
			color_r = 75;
			color_g = 151;
			color_b = 74;
		break;
		
		case(119):
			color_r = 164;
			color_g = 189;
			color_b = 70;
		break;
		
		case(29):
			color_r = 161;
			color_g = 196;
			color_b = 139;
		break;
	
		case(151):
			color_r = 120;
			color_g = 144;
			color_b = 129;
		break;
		/*End of greens*/
		
		/*First 2 shades of brown*/
		case(38):
			color_r = 160;
			color_g = 95;
			color_b = 52;
		break;
		
		case(192):
			color_r = 105;
			color_g = 64;
			color_b = 39;
		break;
		/*end of said shades*/
		
		/*Pastels to Brown*/
		case(104):
			color_r = 107;
			color_g = 50;
			color_b = 123;
		break;
		
		case(9):
			color_r = 232;
			color_g = 186;
			color_b = 199;
		break;
		
		case(101):
			color_r = 218;
			color_g = 134;
			color_b = 121;
		break;
		
		case(5):
			color_r = 215;
			color_g = 197;
			color_b = 153;
		break;
		
		case(153):
			color_r = 149;
			color_g = 121;
			color_b = 118;
		break;
	
		case(217):
			color_r = 124;
			color_g = 92;
			color_b = 69;
		break;
		
		case(18):
			color_r = 204;
			color_g = 142;
			color_b = 104;
		break;
		
		case(125):
			color_r = 234;
			color_g = 184;
			color_b = 145;
		break;
		/*end of said shades*/
		
		/*Extra*/
		case(39):
			color_r = 234;
			color_g = 184;
			color_b = 145;
		break;
		
		case(12):
			color_r = 203;
			color_g = 132;
			color_b = 66;
		break;
		/*End of Extra*/
		
		default:
			color_r = 193;
			color_g = 202;
			color_b = 222;
		break;
	}
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
		glPolyFmt(POLY_ALPHA(31 - int(alpha * 31)) | POLY_CULL_BACK | POLY_FORMAT_LIGHT0 | POLY_FOG );
	} else {
		glPolyFmt(POLY_ALPHA(31 - int(alpha * 31)) | POLY_CULL_NONE | POLY_FORMAT_LIGHT0 | POLY_FOG);
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

	glPolyFmt(POLY_ALPHA(31-int(alpha*31)) | POLY_CULL_NONE  | POLY_FORMAT_LIGHT0 | POLY_FOG);
	
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

//Update world physics
void Part::update(float time) {
  if (isAnchored) {
    // Anchored parts don't move
    return;
  }

  // Apply gravity
  if (!isAnchored) {
    //TODO: Implement physics API
  }

  // Check for collisions with other parts
  if (canCollide) {
    // TODO: implement collision detection and resolution here
  }

  // Update position and velocity based on forces
  pos_x += velocity_x * time;
  pos_y += velocity_y * time;
  pos_z += velocity_z * time;
  velocity_x += forces_x * time;
  velocity_y += forces_y * time;
  velocity_z += forces_z * time;
}

//Render a part
void Part::draw(float renderTransparency) {
	if (transparency != 1) {
		glPushMatrix();
					
		// Compute the angle of rotation
		float angle = acos((r00 + r11 + r22 - 1) / 2);

		// Compute the axis of rotation
		float x = (r21 - r12) / (2 * sin(angle));
		float y = (r02 - r20) / (2 * sin(angle));
		float z = (r10 - r01) / (2 * sin(angle));
					
		glTranslatef32(pos_x, pos_y, pos_z);
		// Use the glRotatef function with the angle and axis
		glRotatef(angle * 180 / M_PI, x, y, z);
		glScalef32(scale_width, scale_height, scale_depth);
		
		calculateBrickColor(brickColor);

		//Render
		drawBlock(0,0,0,1,1,1,color_r,color_g,color_b,transparency+renderTransparency,doCull);
		
		glPopMatrix(1);
	}
}

bool Part::isObstructed(float x, float y, float z, float radius) {
	if (canCollide == true) {
		// Transform the player position into the local space of the part
		float transformed_x = r00 * (x - pos_x) + r01 * (y - pos_y) + r02 * (z - pos_z);
		float transformed_y = r10 * (x - pos_x) + r11 * (y - pos_y) + r12 * (z - pos_z);
		float transformed_z = r20 * (x - pos_x) + r21 * (y - pos_y) + r22 * (z - pos_z);
		float half_width = scale_width;
		float half_height = scale_height;
		float half_depth = scale_depth;
		  
		float closest_x = fmaxf(0.0f - half_width, fminf(transformed_x, half_width));
		float closest_y = fmaxf(0.0f - half_height, fminf(transformed_y, half_height));
		float closest_z = fmaxf(0.0f - half_depth, fminf(transformed_z, half_depth));
		  
		float distance = sqrt(pow(transformed_x - closest_x, 2) + pow(transformed_y - closest_y, 2) + pow(transformed_z - closest_z, 2));
		  
		if (distance <= radius)
		{
			return true;
		}
	}
	return false;
}

float Part::getDistanceFromPlayer(float player_x, float player_y, float player_z) {
	float delta_x = player_x - pos_x;
	float delta_y = player_y - pos_y;
	float delta_z = player_z - pos_z;

	return sqrt(delta_x * delta_x + delta_y * delta_y + delta_z * delta_z);
}

/* PLAYER */
touchPosition	thisXY;
touchPosition	lastXY = { 0,0,0,0 };	
int heading;	

void Player::Input() {
	
	//Scan gamepad
	scanKeys();
	u16 keys = keysHeld();
	
	// Camera rotation by touch screen

	if (keys & KEY_TOUCH)
	{
		touchRead(&thisXY);

		int dx = thisXY.px - lastXY.px;
		int dy = thisXY.py - lastXY.py;

		// filtering measurement errors
		if (dx<20 && dx>-20 && dy<20 && dy>-20)
		{
			directionFacing_x -= dy*2;
			walkDirection_y += dx*2;
		}

		lastXY = thisXY;
	}
	
	/* Clamp directionFacing_x */
	if (directionFacing_x > 65) {
		directionFacing_x = 65;
	}
	if (directionFacing_x < -65) {
		directionFacing_x = -65;
	}
	
	/* Dum Gamepad */
	float walkSpeed = 2.5;
	if((keys & KEY_LEFT)) walkVelocityRelative_x = -walkSpeed;
	if((keys & KEY_RIGHT)) walkVelocityRelative_x = walkSpeed;
	
	if((keys & KEY_UP)) walkVelocityRelative_z = walkSpeed;
	if((keys & KEY_DOWN)) walkVelocityRelative_z = -walkSpeed;
	
	walkDirection_y += walkVelocityRelative_x * 0.12125;
	
	if (!(keys & KEY_DOWN) && !(keys & KEY_UP)) {
		walkVelocityRelative_z = 0;
	}
	
	if (!(keys & KEY_LEFT) && !(keys & KEY_RIGHT)) {
		walkVelocityRelative_x = 0;
	}
}

int desiredPointDir = 0;
float _xx = 0;
float _zz = 0;
int scaleMult = 80;

float lastGoodX = 0;
float lastGoodZ = 0;

u8 secs=0;
float fps=0;

void Player::Update(std::vector<Part> parts, int partCount, float deltaTime) {
	//Scan gamepad
	scanKeys();
	u16 keys = keysHeld();
	
	float multDelta = deltaTime * 60;
	//printf("Deltatime = %f\n", deltaTime);
	
	//Update the target direction vars
	_xx = lengthdir_x((walkVelocityRelative_z*scaleMult), walkDirection_y-90) + lengthdir_x(walkVelocityRelative_x*scaleMult, walkDirection_y);
	_zz = lengthdir_y((walkVelocityRelative_z*scaleMult), walkDirection_y-90) + lengthdir_y(walkVelocityRelative_x*scaleMult, walkDirection_y);
	
	//printf("Player Position:\nX: %f\nY: %f\nZ: %f\n",pos_x, pos_y, pos_z);
	
	targetPoint_x = (pos_x + _xx);
	targetPoint_z = (pos_z + _zz);
		
	if (((keys & KEY_UP) || (keys & KEY_DOWN)) ||
		((keys & KEY_LEFT) || (keys & KEY_RIGHT))
	) {
		desiredPointDir = rad2deg(atan2(pos_x - targetPoint_x, pos_z - targetPoint_z));
		facingDirection_y = lerpAngle(facingDirection_y, desiredPointDir, 0.1);
	}
	
	bool canMoveX = true;
	bool canMoveZ = true;
	lastGoodX = pos_x;
	lastGoodZ = pos_z;
	
	// Call draw function for every part
	for (int i = 0; i < partCount - 5; i++) {
		int sphereSize = 8;
		float torsoPosY = (pos_y - (2048));
		float feetPosY = (pos_y + 1024 + 512 + walkVelocityRelative_y);
		canMoveX = !parts[i].isObstructed(-(pos_x + (_xx*8)), -torsoPosY, -pos_z, 80*sphereSize);
		canMoveZ = !parts[i].isObstructed(-pos_x, -torsoPosY, -(pos_z + (_zz*8)),80*sphereSize);
		bool canMovePosY = !parts[i].isObstructed(-pos_x, -feetPosY, -pos_z, abs(walkVelocityRelative_y * 5)*sphereSize);
		//bool canMoveNegY = parts[i].isObstructed(-pos_x, -headPosY, -pos_z, abs(walkVelocityRelative_y * 4)*(sphereSize*2.5));

		if (canMoveX) {
			
			pos_x = targetPoint_x;
		} else {
			//printf("Player should stop: %d\n",i);
			targetPoint_x = lastGoodX;
		}
		if (canMoveZ) {
			pos_z = targetPoint_z;
		} else {
			//printf("Player should stop: %d\n",i);
			targetPoint_z = lastGoodZ;
		}
		
		if (canMovePosY) {
			walkVelocityRelative_y += gravity * 0.009;
			isOnGround = false;
			jump = false;
		} else {
			walkVelocityRelative_y = -0.05 - int(walkVelocityRelative_y*0.3);
			isOnGround = true;
			pos_y = -(parts[i].pos_y + 1024 + 512 + parts[i].scale_height);
			if (keys & KEY_B) {
				isOnGround = false;
				jump = true;
				walkVelocityRelative_y = -jumpForce * 0.8;
				pos_y -= walkVelocityRelative_y * 4;
			}
		}

	if (!isOnGround) pos_y += walkVelocityRelative_y;
	}
}

void Player::Render() {
	/* Unusued Renderer
	glPushMatrix();
	//printf("Direction: %f\n", facingDirection_y);
	
	glTranslatef32(-pos_x,-pos_y+1024,-pos_z);
	glRotatef(facingDirection_y, 0, 1, 0);
	
	//drawBlock(0,(0.25+0.125),0, 0.5, 1, 0.5, 0,0,0,0.5,false);
			
	glPopMatrix(1);
	
	
	glPushMatrix();
	
	glTranslatef32(-(pos_x + (_xx*8)),-pos_y,-(pos_z + (_zz*8)));
	glRotatef(facingDirection_y, 0, 1, 0);
	
	drawBlock(0,0,0, 0.25, 0.25, 0.25, 0,0,0,0.5,false);
			
	glPopMatrix(1);
	*/
}