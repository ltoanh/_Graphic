#include <GL/freeglut.h>
#include "core.h"

void circleBersenham(int xc,int yc, int r){	 
   	float p;
	int y = r; 
	int x = 0;
	p = -2*r + 3;
	putPixel(xc, yc, 0, r);
	while (x < y){
		if (p < 0){
			p += 4*x + 6;
        }
        else{	
            p += 4*(x - y) + 10;
            y--;
        }
		x++;
        putPixel(xc, yc, x, y);
        putPixel(xc, yc, y, x);
	}
	putPixel(xc, yc, x, x);
}

void drawCircleBresenham(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); //Sets mau net ve - white
	circleBersenham(0, 0, 200); //Tâm C(0,0) bán kính 200
	glViewport(0,0,640,480);
	glFlush();
}

void displayCircleBresenham(){
	
	int mode=GLUT_SINGLE | GLUT_RGB;

	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO MIDPOINT VE DUONG TRON");
	initGL();
	glutDisplayFunc(drawCircleBresenham); 
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutMainLoop(); 
}

