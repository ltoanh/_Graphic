#include<iostream>
#include<stdlib.h>
#include <GL/glut.h>
#include "line_bresenham.h"
#include "line_midpoint.h"
#include "circle_bersenham.h"
#include "circle_midpoint.h"
#include "elip_midpoint.h"
#include "elip_bersenham.h"
#include "core.h"
using namespace std;

int main(int argc, char** argv){
	int choose = 0;
	int algor = 0;
	do{
		system("cls");
		cout<<"Chon thuat toan:\n1.Doan thang\n2.Duong elip\n3.Duong tron\n4.Exit";
		cout<<endl;
		cout<<"Nhap lua chon:";
		cin>>choose;
		switch(choose){
			case 1:
				glutInit(&argc, argv);
				cout<<"Chon thuat toan ve doan thang: 1. Midpoint\t 2. Bresenham\nNhap lua chon: ";
				cin>> algor;
				if(algor == 1){
					displayLineMidpoint();
					
				} else if(algor == 2){
					displayLineBresenham();	
				}
				break;
			case 2: 
				glutInit(&argc, argv);
				cout<<"Chon thuat toan ve duong tron: 1. Midpoint\t 2. Bresenham\nNhap lua chon: ";
				cin>> algor;
				if(algor == 1){
					displayElipMidpoint();
					
				} else if(algor == 2){
					displayElipBresenham();	
				}
				break;
			case 3:
				glutInit(&argc, argv);
				cout<<"Chon thuat toan ve duong elip: 1. Midpoint\t 2. Bresenham\nNhap lua chon: ";
				cin>> algor;
				if(algor == 1){
					displayCircleMidpoint();
					
				} else if(algor == 2){
					displayCircleBresenham();	
				}
				break;
		}
	} while(choose != 4);
}
