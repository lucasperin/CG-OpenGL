#include "Model_Draw.h"

double getAngle(int bodyPart){

	int NormFrame = frame % (framesperstep * maxStep);
	int currentStep = (NormFrame / framesperstep) % maxStep;
	int previousStep = currentStep -1;
	if(previousStep < 0)
		previousStep += maxStep;

   double fractionStep = (NormFrame - currentStep * framesperstep) / (1.0 * framesperstep);

   double angle;
   double previousAngle;

   if(WALKING){
	   angle = walk_angles[bodyPart][currentStep];
	   previousAngle = walk_angles[bodyPart][previousStep];
   }else{
	   angle = sprint_angles[bodyPart][currentStep];
	   previousAngle = sprint_angles[bodyPart][previousStep];
   }
	return angle  * fractionStep + previousAngle * (1.0 - fractionStep);
}

void paw(int side){
	glPushMatrix();
		drawPaw(side);
	glPopMatrix();
}

void pawJoint(int side){
	glPushMatrix();
		glTranslatef(0.0, 0.0, LOWER_LEG_LENGTH);

		if(side == LEFT_FRONT ){
			glRotatef(getAngle(LEFT_FRONT_PAW_JOINT), 1.0, 0.0, 0.0);
		}else if( side == RIGHT_FRONT){
			glRotatef(getAngle(RIGHT_FRONT_PAW_JOINT), 1.0, 0.0, 0.0);
		}else if( side == LEFT_BACK){
			glRotatef(getAngle(LEFT_BACK_PAW_JOINT), 1.0, 0.0, 0.0);
		}else{
			glRotatef(getAngle(RIGHT_BACK_PAW_JOINT), 1.0, 0.0, 0.0);
		}


		drawPawJoint();
		paw(side);
	glPopMatrix();
}


void lowerLeg(int side){
	glPushMatrix();
		drawLowerLeg();
		pawJoint(side);
	glPopMatrix();
}


void lowerLegJoint(int side){
	glPushMatrix();
		glTranslatef(0.0, 0.0, UPPER_LEG_LENGTH);


		if(side == LEFT_FRONT ){
			glRotatef(getAngle(LEFT_FRONT_LOWER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else if( side == RIGHT_FRONT){
			glRotatef(getAngle(RIGHT_FRONT_LOWER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else if( side == LEFT_BACK){
			glRotatef(getAngle(LEFT_BACK_LOWER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else{
			glRotatef(getAngle(RIGHT_BACK_LOWER_LEG_JOINT), 1.0, 0.0, 0.0);
		}

		drawLowerLegJoint();
		lowerLeg(side);
	glPopMatrix();
}


void upperLeg(int side){
	glPushMatrix();
		if(side == LEFT_FRONT  || side == LEFT_BACK){
			glTranslatef(JOINT_WIDTH, 0.0, -JOINT_WIDTH);
		}else{
			glTranslatef(-JOINT_WIDTH, 0.0, -JOINT_WIDTH);
		}

		drawUpperLeg();
		lowerLegJoint(side);
	glPopMatrix();
}

void upperLegJoint(int side){
	glPushMatrix();
		if(side == LEFT_FRONT ){
			glTranslatef(TRUNK_WIDTH/2.0, JOINT_WIDTH/2, TRUNK_LENGTH/8.0);
			glRotatef(getAngle(LEFT_FRONT_UPPER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else if( side == RIGHT_FRONT){
			glTranslatef(-TRUNK_WIDTH/2.0, JOINT_WIDTH/2, TRUNK_LENGTH/8.0);
			glRotatef(getAngle(RIGHT_FRONT_UPPER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else if( side == LEFT_BACK){
			glTranslatef(TRUNK_WIDTH/2.0, 0.0, 7*TRUNK_LENGTH/9.0);
			glRotatef(getAngle(LEFT_BACK_UPPER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else{
			glTranslatef(-TRUNK_WIDTH/2.0, 0.0, 7*TRUNK_LENGTH/9.0);
			glRotatef(getAngle(RIGHT_BACK_UPPER_LEG_JOINT), 1.0, 0.0, 0.0);
		}

		drawUpperLegJoint();
		upperLeg(side);
	glPopMatrix();
}

void tail(){
	glPushMatrix();
		glTranslatef(0.0, 0.0, TAIL_LENGTH);
		glRotatef(180, 0.0, 1.0, 0.0);
		drawTail();
	glPopMatrix();
}

void tailBase(){
	glPushMatrix();
		glTranslatef(0.0, 0.0, TRUNK_LENGTH );
		glRotatef(getAngle(TAIL_JOINT), 1.0, 0.0, 0.0);
		drawTailBase();
		tail();
	glPopMatrix();
}

void head(){
	glPushMatrix();
		glTranslatef(0.0, 0.0, -HEAD_LENGTH -JOINT_WIDTH/2.0 );
		drawHead();
		//drawEars();
	glPopMatrix();
}

void neck(){
	glPushMatrix();
		glTranslatef(0.0, TRUNK_WIDTH/2.0 - JOINT_WIDTH/2.0, -JOINT_WIDTH/2.0);
		glRotatef(getAngle(HEAD), 1.0, 0.0, 0.0);
		drawNeck();
		head();
	glPopMatrix();
}

void trunk(){
	glPushMatrix();
		glRotatef(rotateAngle, 0.0, 1.0, 0.0);
		glRotatef(getAngle(TRUNK), 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, -TRUNK_LENGTH/2.0 );
		glColor3f(1.0, 1.0, 1.0);
		drawTrunk();
		neck();
		upperLegJoint(LEFT_BACK);
		upperLegJoint(RIGHT_BACK);
		upperLegJoint(LEFT_FRONT);
		upperLegJoint(RIGHT_FRONT);
		tailBase();
	glPopMatrix();
}

void Cheetah(){
	trunk();
}















