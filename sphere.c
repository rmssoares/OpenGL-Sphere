/*gcc -Wall -o sphere sphere.c -lglut32cu -lglu32 -lopengl32
* Author: Ricardo soares
* http://www.github.com/thyriki
*/
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159

//Variables of the fuction bounce
float step = 0.0025;
float time = 0.0;
float height = 0;
float h = 7500;
float d = 0.0;

//Fixed variables
GLfloat angle = -90;   
int radio=10;
int n=20;
float posX = 0, posY = 0, posZ = 0; //Modify glTranslate's position


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
}


void esfera(int radio){
	float px, py, pz;
	int i, j;
	float incO = 2 * PI / n;
	float incA = PI / n;
	glBegin(GL_TRIANGLE_STRIP);
	for (i = 0; i <= n; i++){
		for (j = 0; j <= n; j++) {
			pz = cos(PI - (incA*j))*radio;
			py = sin(PI - (incA*j))*sin(incO*i)*radio;
			px = sin(PI - (incA*j))*cos(incO*i)*radio;
			//printf("%lf%lf%lf\n", px, py, pz);
			glVertex3f(px, py, pz);
			pz = cos(PI - (incA*j))*radio;
			py = sin(PI - (incA*j))*sin(incO*(i + 1))*radio;
			px = sin(PI - (incA*j))*cos(incO*(i + 1))*radio;
			glVertex3f(px, py, pz);
		}
	}
	glEnd();
}

void display(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glLoadIdentity();
	glRotatef(angle, 1.0, 0.0, 0.0);
	glScalef(2.0, 2.0, 2.0);

	//Multiply current matrix
	glTranslatef(posX, posY, posZ);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor4f(0.0, 0.0, 0.75, 0.5);
	glLineWidth(2.0);
	esfera(5);
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -25.0, 75.0, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void bounce()
{
	double height = sin(step + time) - sin(time);
	posZ = fabs(height*h);
	time += step;
	//printf("%f\n", h);
	posX+=d;
	glutPostRedisplay();
}


void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(bounce);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}

void keyboard(unsigned char key, int a, int b)
{
    if(key == 'z') //Higher
    {
    	h+=50;
    }
    if(key == 'x') //Lower
    {
        h-=50;
    }
    if(key == 'a') //Faster
    {
    	step*=1.5;
    	h/=1.5;
    }
    if(key == 's') //Slower
    {
        step/=1.5;
        h*=1.5;
    }
        if(key == 'c') //Left
    {
    	d-=0.005;
    }
    	    if(key == 'v') //Right
    {
    	d+=0.005;
    }
    if (key == 'd') //Complex
    {
    	n++;
    }
    if (key == 'f') //Simple
    {
    	n--;
    }
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(400, 35);
	glutCreateWindow(argv[0]);
    printf("Click to jump. \n 'z' increases the jump height, 'x' decreaes. \n 'a' speeds it up, 's' slows it down. \n 'c' makes it go left, 'v' right. \n 'd' increases complexity, 'f' decreases.");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);	
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}