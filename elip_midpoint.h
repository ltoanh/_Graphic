#include <GL/freeglut.h>
#include "core.h"

void elipsMidpoint(int xc, int yc, int a, int b ){	 
   	int x = 0;
	int y = b; 
	int a2 = a*a;
	int b2 = b*b;
	int di= b2 + a2*(b - 1/2)*(b - 1/2) - a2*b2;
	
	putPixel(xc,yc,x,y); // (0, b) (0, -b)
	
	//Phan 1:
	while (x*b2/a2 <= y){
		if (di <0)	
        	di += b2*(2*x + 3);
		else{
        	di += b2*(2*x + 3) + 2*a2*(-y + 1);
		    y--;
		}
		x++;
        putPixel(xc,yc,x,y);
	}
	
	//Phan 2:
	int dj = b2*(x + 1/2)*(x + 1/2) + a2*(y - 1)*(y - 1) - a2*b2;
	while (y > 0){
		if (dj <0){
			dj += 2*b2*(x + 1) + a2*(-2*y + 3);
			x++;
		}
		else{	
            dj += a2*(-2*y + 3);
		}
		y--;
        putPixel(xc,yc,x,y);
	}
	putPixel(xc,yc,x,y);
}

void drawElipMidpoint(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); //Sets mau net ve - white
	elipsMidpoint(0, 0, 300, 200); //Tâm C(0,0) bán kính 200
	glViewport(0,0,640,480);
	glFlush();
}

void displayElipMidpoint(){
	
	int mode=GLUT_SINGLE | GLUT_RGB;

	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO BRESENHAM VE ELIP");
	initGL();
	glutDisplayFunc(drawElipMidpoint); 
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutMainLoop(); 
}


