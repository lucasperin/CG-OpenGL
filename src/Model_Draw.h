#include "Definitions.h"

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void drawPaw(int side){
	if(WIRED)
		glutWireCylinder(PAW_WIDTH/2,PAW_LENGTH, 16, 16);
	else
		glutSolidCylinder(PAW_WIDTH/2,PAW_LENGTH, 16, 16);
}

void drawPawJoint(){
	if(WIRED)
		glutWireSphere(JOINT_WIDTH/2, 16, 16);
	else
		glutSolidSphere(JOINT_WIDTH/2, 16, 16);
}

void drawLowerLeg(){

	if(WIRED)
		glutWireCylinder(LOWER_LEG_WIDTH/2,LOWER_LEG_LENGTH, 16, 16);
	else
		glutSolidCylinder(LOWER_LEG_WIDTH/2,LOWER_LEG_LENGTH, 16, 16);

}


void drawLowerLegJoint(){
	if(WIRED)
		glutWireSphere(JOINT_WIDTH/2, 16, 16);
	else
		glutSolidSphere(JOINT_WIDTH/2, 16, 16);

}

void drawUpperLeg(){
	if(WIRED)
		glutWireCone(UPPER_LEG_WIDTH/2.0, UPPER_LEG_LENGTH, 16, 16);
	else
		glutSolidCone(UPPER_LEG_WIDTH/2.0, UPPER_LEG_LENGTH, 16, 16);

}

void drawUpperLegJoint(){
		if(WIRED)
			glutWireSphere(JOINT_WIDTH/2, 16, 16);
		else
			glutSolidSphere(JOINT_WIDTH/2, 16, 16);

}

void drawTail(){
		if(WIRED)
			glutWireCone(TAIL_WIDTH/2.0, TAIL_LENGTH, 16, 16);
		else
			glutSolidCone(TAIL_WIDTH/2.0, TAIL_LENGTH, 16, 16);
}

void drawTailBase(){
		if(WIRED)
			glutWireSphere(JOINT_WIDTH/2, 16, 16);
		else
			glutSolidSphere(JOINT_WIDTH/2, 16, 16);

}

void drawEars(){
	glPushMatrix();
		glRotatef(50, 0.0, 0.0, 1.0);
		glTranslatef(0.0, HEAD_WIDTH/2, 3*HEAD_LENGTH/4 );
		glRotatef(90, 1.0, 1.0, 0.0);
		if(WIRED)
			glutWireCone(JOINT_WIDTH/2.0, JOINT_WIDTH, 16, 16);
		else
			glutSolidCone(JOINT_WIDTH/2.0, JOINT_WIDTH, 16, 16);

	glPopMatrix();
	glPushMatrix();
		glRotatef(-50, 0.0, 0.0, 1.0);
		glTranslatef(0.0, HEAD_WIDTH/2, 3*HEAD_LENGTH/4 );
		glRotatef(90, -1.0, 1.0, 0.0);
		if(WIRED)
			glutWireCone(JOINT_WIDTH/2.0, JOINT_WIDTH, 16, 16);
		else
			glutSolidCone(JOINT_WIDTH/2.0, JOINT_WIDTH, 16, 16);

	glPopMatrix();
}

void drawHead(){
		if(WIRED)
			glutWireCylinder(HEAD_WIDTH/2.0, HEAD_LENGTH, 16, 16);
		else
			glutSolidCylinder(HEAD_WIDTH/2.0, HEAD_LENGTH, 16, 16);
}

void drawNeck(){
		if(WIRED)
			glutWireSphere(JOINT_WIDTH/2.0, 16, 16);
		else
			glutSolidSphere(JOINT_WIDTH/2.0, 16, 16);
}

void drawTrunk(){
		if(WIRED)
			glutWireCone(TRUNK_WIDTH/2.0, TRUNK_LENGTH, 16, 16);
		else
			glutSolidCone(TRUNK_WIDTH/2.0, TRUNK_LENGTH, 16, 16);
}
