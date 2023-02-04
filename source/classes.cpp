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
		/* Fallback/null color */
		default:
			color_r = 255;
			color_g = 0;
			color_b = 255;
		break;
		
		/* White */
		case(1):
			color_r = 242;
			color_g = 243;
			color_b = 242;
		break;
		
		/* Grey */
		case(2):
			color_r = 161;
			color_g = 165;
			color_b = 165;
		break;
		
		/* Light yellow */
		case(3):
			color_r = 249;
			color_g = 233;
			color_b = 233;
		break;
		
		/* Brick yellow */
		case(5):
			color_r = 215;
			color_g = 215;
			color_b = 153;
		break;
		
		/* Light green */
		case(6):
			color_r = 194;
			color_g = 194;
			color_b = 184;
		break;
		
		/* Light reddish violet */
		case(9):
			color_r = 232;
			color_g = 232;
			color_b = 232;
		break;
		
		/* Light orange brown */
		case(12):
			color_r = 203;
			color_g = 132;
			color_b = 66;
		break;
		
		/* Nougat */
		case(18):
			color_r = 204;
			color_g = 142;
			color_b = 104;
		break;
		
		/* Bright red */
		case(21):
			color_r = 196;
			color_g = 40;
			color_b = 27;
		break;
		
		/* Med. reddish violet */
		case(22):
			color_r = 196;
			color_g = 112;
			color_b = 160;
		break;
		
		/* Bright blue */
		case(23):
			color_r = 13;
			color_g = 105;
			color_b = 171;
		break;
		
		/* Bright yellow */
		case(24):
			color_r = 245;
			color_g = 205;
			color_b = 47;
		break;
		
		/* Earth orange */
		case(25):
			color_r = 98;
			color_g = 71;
			color_b = 50;
		break;
		
		/* Black */
		case(26):
			color_r = 27;
			color_g = 42;
			color_b = 52;
		break;
		
		/* Dark grey */
		case(27):
			color_r = 109;
			color_g = 110;
			color_b = 108;
		break;
		
		/* Dark green */
		case(28):
			color_r = 40;
			color_g = 127;
			color_b = 70;
		break;
		
		/* Medium green */
		case(29):
			color_r = 161;
			color_g = 196;
			color_b = 139;
		break;
		
		/* Lt. Yellowich orange */
		case(36):
			color_r = 243;
			color_g = 207;
			color_b = 155;
		break;
		
		/* Bright green */
		case(37):
			color_r = 75;
			color_g = 151;
			color_b = 74;
		break;
		
		/* Dark orange */
		case(38):
			color_r = 160;
			color_g = 95;
			color_b = 52;
		break;
		
		/* Light blueish violet */
		case(39):
			color_r = 193;
			color_g = 202;
			color_b = 222;
		break;
		
		/* Light blue */
		case(45):
			color_r = 180;
			color_g = 210;
			color_b = 227;
		break;
		
		/* Light red */
		case(100):
			color_r = 238;
			color_g = 196;
			color_b = 182;
		break;
		
		/* Medium red */
		case(101):
			color_r = 238;
			color_g = 196;
			color_b = 182;
		break;
		
		/* Medium blue */
		case(102):
			color_r = 40;
			color_g = 127;
			color_b = 70;
		break;
		
		/* Light gray */
		case(103):
			color_r = 40;
			color_g = 127;
			color_b = 70;
		break;
	}
}

void drawBlock(float x, float y, float z, float width, float height, float depth, int r, int g, int b, float alpha, bool doCull) {
	// Set the scale
	width = abs(width);
	height = abs(height);
	depth = abs(depth);
	
	// Set the positions used for making the model.
	float xx1 = std::min(x - width, x + width);
	float xx2 = std::max(x - width, x + width);

	float yy1 = std::min(y - height, y + height);
	float yy2 = std::max(y - height, y + height);

	float zz1 = std::min(z - depth, z + depth);
	float zz2 = std::max(z - depth, z + depth);

	glPolyFmt(POLY_ALPHA(31 - int(alpha * 31)) | POLY_CULL_NONE | POLY_FORMAT_LIGHT0 | POLY_FOG);
	
	// Configure the colors to work in the 0 - 31 format instead of 0 - 255, aka 15-bit color mode.
	int r31, g31, b31;
	int r31s, g31s, b31s;
	r31 = (r/16);
	g31 = (g/16);
	b31 = (b/16);
	
	r31s = (r/16)*0.5;
	g31s = (g/16)*0.5;
	b31s = (b/16)*0.5;
	
	// Set the material properties
	glMaterialf(GL_AMBIENT, RGB15(r31s,g31s,b31s));
	glMaterialf(GL_DIFFUSE, RGB15(r31,g31,b31));
	
	//Back
	if (zz2 - zz1 > 0) {
		glBegin(GL_QUAD);
			glNormal3f(0,0,zz2);
			glVertex3f(xx1, yy2, zz2);
			glVertex3f(xx2, yy2, zz2);
			glVertex3f(xx2, yy1, zz2);
			glVertex3f(xx1, yy1, zz2);
		glEnd();
	} else {
		glBegin(GL_QUAD);
			glNormal3f(0,0,zz2);
			glVertex3f(xx1, yy1, zz2);
			glVertex3f(xx2, yy1, zz2);
			glVertex3f(xx2, yy2, zz2);
			glVertex3f(xx1, yy2, zz2);
		glEnd();
	}

	//Front
	if (zz1 - zz2 < 0) {
		glBegin(GL_QUAD);
			glNormal3f(0,0,zz1);
			glVertex3f(xx1, yy1, zz1);
			glVertex3f(xx2, yy1, zz1);
			glVertex3f(xx2, yy2, zz1);
			glVertex3f(xx1, yy2, zz1);
		glEnd();
	} else {
		glBegin(GL_QUAD);
			glNormal3f(0,0,zz1);
			glVertex3f(xx1, yy2, zz1);
			glVertex3f(xx2, yy2, zz1);
			glVertex3f(xx2, yy1, zz1);
			glVertex3f(xx1, yy1, zz1);
		glEnd();
	}

	//Right
	if (xx1 - xx2 < 0) {
		glBegin(GL_QUAD);
			glNormal3f(xx1,0,0);
			glVertex3f(xx1, yy2, zz1);
			glVertex3f(xx1, yy2, zz2);
			glVertex3f(xx1, yy1, zz2);
			glVertex3f(xx1, yy1, zz1);
		glEnd();
	} else {
		glBegin(GL_QUAD);
			glNormal3f(xx1,0,0);
			glVertex3f(xx1, yy1, zz1);
			glVertex3f(xx1, yy1, zz2);
			glVertex3f(xx1, yy2, zz2);
			glVertex3f(xx1, yy2, zz1);
		glEnd();
	}

	//Left
	if (xx2 - xx1 < 0) {
		glBegin(GL_QUAD);
			glNormal3f(xx2,0,0);
			glVertex3f(xx2, yy1, zz2);
			glVertex3f(xx2, yy1, zz1);
			glVertex3f(xx2, yy2, zz1);
			glVertex3f(xx2, yy2, zz2);
		glEnd();
	} else {
		glBegin(GL_QUAD);
			glNormal3f(xx2,0,0);
			glVertex3f(xx2, yy1, zz1);
			glVertex3f(xx2, yy1, zz2);
			glVertex3f(xx2, yy2, zz2);
			glVertex3f(xx2, yy2, zz1);
		glEnd();
	}
	
	
	//Top
	if (yy1 - yy2 < 0) {
		glBegin(GL_QUAD);
			glNormal3f(0,yy2,0);
			glVertex3f(xx1, yy2, zz1);
			glVertex3f(xx2, yy2, zz1);
			glVertex3f(xx2, yy2, zz2);
			glVertex3f(xx1, yy2, zz2);
		glEnd();
	} else {
		glBegin(GL_QUAD);
			glNormal3f(0,yy2,0);
			glVertex3f(xx1, yy2, zz2);
			glVertex3f(xx2, yy2, zz2);
			glVertex3f(xx2, yy2, zz1);
			glVertex3f(xx1, yy2, zz1);
		glEnd();
	}
		
	//Bottom
	if (yy2 - yy1 < 0) {
		glBegin(GL_QUAD);
			glNormal3f(0,yy1,0);
			glVertex3f(xx1, yy1, zz1);
			glVertex3f(xx2, yy1, zz1);
			glVertex3f(xx2, yy1, zz2);
			glVertex3f(xx1, yy1, zz2);
		glEnd();
	} else {
		glBegin(GL_QUAD);
			glNormal3f(0,yy1,0);
			glVertex3f(xx1, yy1, zz2);
			glVertex3f(xx2, yy1, zz2);
			glVertex3f(xx2, yy1, zz1);
			glVertex3f(xx1, yy1, zz1);
		glEnd();
	}
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
		
		float scale_width_abs = abs(scale_width);
		float scale_height_abs = abs(scale_height);
		float scale_depth_abs = abs(scale_depth);
		
		glScalef32(scale_width_abs, scale_height_abs, scale_depth_abs);
		
		if (scale_width < 0) {
			glScalef(1, 1, -1);
		}
		if (scale_height < 0) {
			glScalef(1, -1, 1);
		}
		if (scale_depth < 0) {
			glScalef(1, 1, -1);
		}
		
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
		  
		float closest_x = std::fmax(-half_width, std::fmin(transformed_x, half_width));
		float closest_y = std::fmax(-half_height, std::fmin(transformed_y, half_height));
		float closest_z = std::fmax(-half_depth, std::fmin(transformed_z, half_depth));
		  
		float distance = sqrtf(powf(transformed_x - closest_x, 2) + powf(transformed_y - closest_y, 2) + powf(transformed_z - closest_z, 2));
		  
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
	bool canMovePosY = true;
	bool canMoveNegY = true;
	lastGoodX = pos_x;
	lastGoodZ = pos_z;
	
	// Call draw function for every part
	for (int i = 0; i < partCount - 5; i++) {
		int sphereSize = 8;
		int footSize = 90;
		
		int bodySize = (footSize * sphereSize) * 2.5;
		
		float torsoPosY = (pos_y - (2048));
		float feetPosY = (pos_y + ((1024 + 512) + walkVelocityRelative_y));
		float headPosY = (pos_y - ((1024 + 1024 + 512) + walkVelocityRelative_y));
		
		bool obstructX = parts[i].isObstructed(-(pos_x + (_xx * 4)), -torsoPosY, -pos_z, bodySize);
		bool obstructZ = parts[i].isObstructed(-pos_x, -torsoPosY, -(pos_z + (_zz * 4)), bodySize);
		
		bool obstructX_FineTuneUp = parts[i].isObstructed(-(pos_x + (_xx * 4)), -(torsoPosY + 1024), -pos_z, bodySize);
		bool obstructZ_FineTuneUp = parts[i].isObstructed(-pos_x, -(torsoPosY + 1024 + 1024), -(pos_z + (_zz * 4)), bodySize);
		
		bool obstructX_FineTuneDown = parts[i].isObstructed(-(pos_x + (_xx * 4)), -(torsoPosY - 1024), -pos_z, bodySize);
		bool obstructZ_FineTuneDown = parts[i].isObstructed(-pos_x, -(torsoPosY - 1024 - 1024), -(pos_z + (_zz * 4)), bodySize);
		
		bool obstructPosY = parts[i].isObstructed(-pos_x, -feetPosY, -pos_z, footSize * sphereSize);
		bool obstructPosY_FineTune = parts[i].isObstructed(-pos_x, -feetPosY, -pos_z, (footSize/2) * sphereSize);
		bool obstructNegY = parts[i].isObstructed(-pos_x, -headPosY, -pos_z, footSize * sphereSize);

		canMoveX = !obstructX || !obstructX_FineTuneUp || !obstructX_FineTuneDown;
		canMoveZ = !obstructZ || !obstructZ_FineTuneUp || !obstructZ_FineTuneDown;
		canMovePosY = !obstructPosY || !obstructPosY_FineTune;
		canMoveNegY = !obstructNegY;

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
		
		if (!canMoveNegY) {
			walkVelocityRelative_y = -walkVelocityRelative_y;
			pos_y = -(parts[i].pos_y - parts[i].scale_height) + (1024 + 1024 + 512 + 256) + (footSize * sphereSize);
		}
		
		float newPosY;

		if (canMovePosY) {
		  walkVelocityRelative_y += gravity * 0.002;
		  
		  walkVelocityRelative_y = clamp(walkVelocityRelative_y,-8,6);
		  isOnGround = false;
		  jump = false;
		  newPosY = pos_y + walkVelocityRelative_y * 4;
		} else {
		  walkVelocityRelative_y = -0.05 - (walkVelocityRelative_y * 0.3);
		  isOnGround = true;
		  newPosY = -(parts[i].pos_y + 1024 + 512 + parts[i].scale_height);
		  if (keys & KEY_B) {
			isOnGround = false;
			jump = true;
			walkVelocityRelative_y = -jumpForce * 0.2;
			newPosY -= (walkVelocityRelative_y * 4) + (footSize * sphereSize);
		  }
		}

		pos_y = newPosY;

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