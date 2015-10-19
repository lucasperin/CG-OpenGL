
#include "model.h"

GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat ambient[] = {1.0, 1.0, 1.0, 0.1};
GLfloat position[] = {0.0, 2.0, 0.0, 0.0};

void repaint(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
	frame++;
	Cheetah();
	glutSwapBuffers() ;
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{
		case '1' :
			if(SMOOTH == 1){
				SMOOTH = 0;
				glShadeModel(GL_FLAT) ;
			}else{
				SMOOTH = 1;
				glShadeModel(GL_SMOOTH) ;
			}
			break ;
		case '2':
			if(WIRED == 1)
				WIRED = 0;
			else
				WIRED = 1;
			break;
		case 'w':
				SCALE = SCALE + 0.1;
			break;
		case 's':
				SCALE = SCALE - 0.1;
			break;
		case 'a':
				rotateAngle += 10;
			break;
		case 'd':
				rotateAngle -=10;
			break;
		case ' ':
				WALKING = !WALKING;
				break;
		default :
			break ;
	}
	glutPostRedisplay() ;
}

void init()
{

	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB) ;
	glutInitWindowSize (800, 800) ;
	glutInitWindowPosition (800, 400) ;
	glutCreateWindow ("OpenGL - Modelos Hierarquicos - CHEETAH!") ;
	glClearColor( 0.0, 0.0, 0.0, 0.0) ;

    glViewport(0, 0, (GLsizei) 800, (GLsizei) 800);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();

    gluPerspective((GLdouble)40.0, (GLdouble) 1.0, (GLdouble)1.0, (GLdouble)100.0);

    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0, 0., -3.0);

    glShadeModel(GL_SMOOTH);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(&repaint);
	glutIdleFunc(&repaint);
	glutKeyboardFunc(&keyboard);
	glutMainLoop () ;
}


int main(int argc, char** argv)
{
	glutInit (&argc, argv) ;
	init() ;
	return 0 ;
}
