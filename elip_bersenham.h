#include <GL/freeglut.h>
#include "core.h"

void elipBresenham(int xc, int yc, int a, int b ){	 
   	int x = 0;
	int y = b; 
	int a2 = a*a;
	int b2 = b*b;
	double pi = -2*b + 1 + 1.0*2*b2/a2;
	
	putPixel(xc,yc,x,y); // (0, b) (0, -b)
	
	//Phan 1:
	while (x*b2/a2 <= y){
		if (pi < 0){
        	pi += 1.0*b2*(4*x + 6)/a2;
    	}
		else{
        	pi += 1.0*b2*(4*x + 6)/a2 - 4*y + 4;
		    y--;
		}
		x++;
        putPixel(xc,yc,x,y);
	}
	
	//Phan 2:
	double pj = -2*a + 1 + 1.0*2*a2/b2;
	x = a; y = 0;
	putPixel(xc,yc,x,y);
	while (((double)a2/b2)*y <= x){
		if (pj <0){
			pj += ((double)a2/b2)*(4*y + 6);
		}
		else{	
            pj += ((double)a2/b2)*(4*y + 6) - 4*x + 4;
            x--;
		}
		y++;
        putPixel(xc,yc,x,y);
	}
}

void drawElipBresenham(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); //Sets mau net ve - white
	elipBresenham(0, 0, 300, 200); //Tâm C(0,0) bán kính 200
	glViewport(0,0,640,480);
	glFlush();
}

void displayElipBresenham(){
	int mode=GLUT_SINGLE | GLUT_RGB;
	
	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO BRESENHAM VE ELIP");
	initGL();
	glutDisplayFunc(drawElipBresenham); 
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutMainLoop(); 
}
