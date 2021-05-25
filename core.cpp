#include <GL/freeglut.h>

void putPixel(int xc, int yc, int x, int y){
	glBegin(GL_POINTS);
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc - x, yc + y);
	glEnd();
}

void initGL(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //mau nen
	glOrtho(-320,320,-240,240,-1,1); //khoi tao phep chieu ma tran LRBT
}
