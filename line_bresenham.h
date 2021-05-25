#include <GL/freeglut.h>
#include "core.h"
void LineBresenham(int x1,int y1, int x2, int y2){	 
   	int x, y, dx, dy, p;
	x = x1; 
	y = y1;
	dx = x2-x1;
	dy = y2-y1;
	p = 2*dy - dx;
	int i = 1,  j = 1;
	if(x2 - x1 < 0) i = -i;
	if(y2 - y1 < 0) j = -j;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	if(x1 == x2){
		while(y != y2+1){
			glVertex2i(x, y);
			y += j;
		}
	}
	else if(y1 == y2){
		while(x != x2 +1){
			glVertex2i(x, y);
			x += i;
		}
	}
	else{
		while (x < x2){
			if (p <= 0){
				p += 2*dy;
	        }
	        else{	
	            p += 2*dy - 2*dx;
	            y+=j;
	        }
			x += i;
	        glVertex2i(x, y);
		}
	}
	
	glEnd();
}

void lineBresenham(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); //Sets mau net ve - white
	LineBresenham(10, 10, 200, 200); 
	LineBresenham(10, 15, 10, 200);
	LineBresenham(10, 200, 150, 200);
	glViewport(0,0,640,480);
	glFlush();
}

void displayLineBresenham(){
	
	int mode=GLUT_SINGLE | GLUT_RGB;

	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO BRESENHAM VE DUONG THANG");
	initGL();
	glutDisplayFunc(lineBresenham); 
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutMainLoop(); 
	//glutMainLoopEvent();
}

