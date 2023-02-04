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