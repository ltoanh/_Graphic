#include <GL/freeglut.h>
#include "core.h"

void circleMidpoint(int xc,int yc, int r){	 
   	float d;
	int y = r; 
	int x = 0;
	d = 5/4 - r;
	putPixel(xc, yc, 0, r);
	while (x < y){
		if (d <0){
			d += 2*x + 3;
        }
        else{	
            d += 2*(x - y) + 5;
            y--;
        }
   
		x++;
        putPixel(xc, yc, x, y);
        putPixel(xc, yc, y, x);
	}
	putPixel(xc, yc, x, x);
}

void drawCircleMidpoint(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); //Sets mau net ve - white
	circleMidpoint(0, 0, 200); //Tâm C(0,0) bán kính 200
	glViewport(0,0,640,480);
	glFlush();
}

void displayCircleMidpoint(){
	
	int mode=GLUT_SINGLE | GLUT_RGB;

	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO MIDPOINT VE DUONG TRON");
	initGL();
	glutDisplayFunc(drawCircleMidpoint); 
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutMainLoop(); 
}

