
/* Scale */
#define SCALE 1.3
int rotateAngle = 90;
int maxStep = 8;
int frame = 0;
int framesperstep = 10;

/* Movement */
double movement  = 0;

/* Wire/Solid */
int WIRED = 1;
int SMOOTH = 1;

/* Walking/Running */

int WALKING = 1;

/*defs*/
#define LEFT_FRONT_UPPER_LEG_JOINT 0
#define RIGHT_FRONT_UPPER_LEG_JOINT 1

#define LEFT_BACK_UPPER_LEG_JOINT 2
#define RIGHT_BACK_UPPER_LEG_JOINT 3

#define LEFT_FRONT_LOWER_LEG_JOINT 4
#define RIGHT_FRONT_LOWER_LEG_JOINT 5

#define LEFT_BACK_LOWER_LEG_JOINT 6
#define RIGHT_BACK_LOWER_LEG_JOINT 7

#define LEFT_FRONT_PAW_JOINT 8
#define RIGHT_FRONT_PAW_JOINT 9

#define LEFT_BACK_PAW_JOINT 10
#define RIGHT_BACK_PAW_JOINT 11

#define TAIL_JOINT 12
#define TRUNK 13
#define HEAD 14

/* Leg Sides */
#define LEFT_FRONT 0
#define RIGHT_FRONT 1
#define LEFT_BACK 2
#define RIGHT_BACK 3

/* Trunk */
#define TRUNK_HEIGHT 0.4 / SCALE
#define TRUNK_WIDTH 0.4 / SCALE
#define TRUNK_LENGTH 1.3 / SCALE


/* Tail */
#define TAIL_HEIGHT 0.1 / SCALE
#define TAIL_WIDTH 0.1 / SCALE
#define TAIL_LENGTH 0.6 / SCALE


/* Head */
#define HEAD_HEIGHT 0.2 / SCALE
#define HEAD_WIDTH 0.2 / SCALE
#define HEAD_LENGTH 0.3 / SCALE

/* Upper Leg */
#define UPPER_LEG_HEIGHT 0.4 / SCALE
#define UPPER_LEG_WIDTH 0.2 / SCALE
#define UPPER_LEG_LENGTH 0.4 / SCALE

/* Lower Leg */
#define LOWER_LEG_HEIGHT 0.4 / SCALE
#define LOWER_LEG_WIDTH 0.05 / SCALE
#define LOWER_LEG_LENGTH 0.3 / SCALE

/* Paw */
#define PAW_HEIGHT 0.2 / SCALE
#define PAW_WIDTH 0.05 / SCALE
#define PAW_LENGTH 0.2/ SCALE

/* Joints */
#define JOINT_HEIGHT 0.1 / SCALE
#define JOINT_WIDTH 0.1 / SCALE
#define JOINT_LENGTH 0.1 / SCALE


double sprint_angles[15][8] = {
		/* LEFT FRONT UPPER LEG JOINT 	*/{ 10, 20, 45, 90, 120, 110, 90, 45 },
		/* RIGHT FRONT UPPER LEG JOINT 	*/{ 20, 10, 20, 45, 90, 135, 135, 70 },
		/* LEFT BACK UPPER LEG JOINT 	*/{ 150, 135, 90, 50, 80, 110, 130, 180 },
		/* RIGHT BACK UPPER LEG JOINT 	*/{ 145, 90, 45, 45, 90, 100, 135, 170 },

		/* LEFT FRONT LOWER LEG JOINT 	*/{ 90, 135, 90, 90, 45, 30, 0, 30 },
		/* RIGHT FRONT LOWER LEG JOINT 	*/{ 45, 90, 110, 135, 90, 45, 10, 20 },
		/* LEFT BACK LOWER LEG JOINT 	*/{ -90, -45, -40, 0, -90, -90, -130,-45 },
		/* RIGHT BACK LOWER LEG JOINT 	*/{ -45, -45, 0, -40, -90, -90, -135, -90 },

		/* LEFT FRONT PAW JOINT 	*/{ -90, -135, -90, -15, 0, 0, 0, -90 },
		/* RIGHT FRONT PAW JOINT 	*/{ -90, -115, -90, -45, 0, 0, 0, 0 },
		/* LEFT BACK PAW JOINT 		*/{ 90, 45, 40, 0, 0, 90, 90, 45 },
		/* RIGHT BACK PAW JOINT 	*/{ 45, 45, 0, 0, 65, 90, 90, 90 },

		/* TAIL				*/{ 35, 30, 20, 40, 45, 55, 45, 40 },
		/* TRUNK 			*/{ 0,5,10,5,0,-5,-10,-5 },
		/* HEAD 			*/{ -10,-20,-30,-20,-10,-15,-20,-15 }
};

double walk_angles[15][8] = {
		/* LEFT FRONT UPPER LEG JOINT 	*/{ 90,105,90,65,60,45,50,70 },
		/* RIGHT FRONT UPPER LEG JOINT 	*/{ 65,60,55,70,110,95,80,70 },
		/* LEFT BACK UPPER LEG JOINT 	*/{ 90,80,70,60,50,70,120,110 },
		/* RIGHT BACK UPPER LEG JOINT 	*/{ 55,100,135,110,110,95,90,70 },

		/* LEFT FRONT LOWER LEG JOINT 	*/{ 45,30,20,25,35,30,45,90 },
		/* RIGHT FRONT LOWER LEG JOINT 	*/{ 10,30,40,80,40,20,10,10 },
		/* LEFT BACK LOWER LEG JOINT 	*/{ -45,-45,-45,-30,-50,-90,-75,-45 },
		/* RIGHT BACK LOWER LEG JOINT 	*/{ -45,-100,-90,-30,-45,-55,-70,-60 },

		/* LEFT FRONT PAW JOINT 	*/{ 0,0,-10,0,0,-50,0,-60},
		/* RIGHT FRONT PAW JOINT 	*/{ 0,0,-45,-70,-5,0,0,0 },
		/* LEFT BACK PAW JOINT 		*/{ 60,55,45,45,45,80,30,55 },
		/* RIGHT BACK PAW JOINT 	*/{ 45,85,90,45,50,45,45,45 },

		/* TAIL				*/{ 55,65,65,65,55,65,65,65 },
		/* TRUNK 			*/{ 0,0,0,0,0,0,0,0 },
		/* HEAD 			*/{ 0,0,0,0,0,0,0,0 }
};



