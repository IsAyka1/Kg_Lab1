

#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>


using std::vector;
using std::array;

void Figure()
{
	const int SIZE = 7;
	double Bot[][3] = {
		{ 0, 0, 0 }, //A
		{ 9, 1, 0 }, //B
		{ 3, 5, 0 }, //C
		{ 6, 10, 0 }, //D
		{ -4, 9, 0 }, //E
		{ -3, 5, 0 }, //F
		{ -9, 3, 0 }  //G
	};
	double Top[][3] = {
		{ 0, 0, 3 }, //A1
		{ 9, 1, 3 }, //B1
		{ 3, 5, 3 }, //C1
		{ 6, 10, 3 }, //D1
		{ -4, 9, 3 }, //E1
		{ -3, 5, 3 }, //F1
		{ -9, 3, 3 }  //G1
	};

	glBegin(GL_QUAD_STRIP);
	glColor3d(0, 0, 1);
	for (int i = 0; i < SIZE; i++) {
		glVertex3dv(Top[i]);
		glVertex3dv(Bot[i]);
	}
	glVertex3dv(Top[0]);
	glVertex3dv(Bot[0]);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(1, 0, 0);
	for (int i = 0; i < SIZE; i++) {
		glVertex3dv(Top[i]);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3d(0, 1, 0);
	for (int i = 0; i < SIZE; i++) {
		glVertex3dv(Bot[i]);
	}
	glEnd();
}

void Curcle(int z = 0) {
	double O[] = { 1, 9.5, z };
	//double D[] = { 6, 10, z };
	//double E[] = { -4, 9, z };

	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.75, 0.0, 0.25);
	glVertex3dv(O);
	//glVertex3dv(D);
		for (double i = 6, r = 5.025; i <= 186; i++) { // atan(0.1); 180 + atan(0.1)
			double x = r * cos(i * M_PI / 180) + O[0];
			double y = r * sin(i * M_PI / 180) + O[1];
			double New[] = { x, y, z };
			glVertex3dv(New);
			//glVertex3dv(E);
		}
	
	glEnd();
}

void CurcleRotate(int z, int f) {
	double O[] = { 1, 9.5, z };
	double x = O[0] * cos(f * M_PI / 180) - O[1] * sin(f * M_PI / 180);
	double y = O[0] * sin(f * M_PI / 180) + O[1] * cos(f * M_PI / 180);
	O[0] = x; O[1] = y;
	//double D[] = { 6, 10, z };
	//double E[] = { -4, 9, z };

	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.75, 0.0, 0.25);
	glVertex3dv(O);
	//glVertex3dv(D);
	
		for (double i = 6+f, r = 5.025; i <= 186+f; i++) { // atan(0.1); 180 + atan(0.1)
			double x = r * cos(i * M_PI / 180) + O[0];
			double y = r * sin(i * M_PI / 180) + O[1];
			//double newX = x * cos(f * M_PI / 180) - y * sin(f * M_PI / 180);
			//double newY = x * sin(f * M_PI / 180) + y * cos(f * M_PI / 180);
			glVertex3d(x, y, z);
			//glVertex3dv(E);
		}
	glEnd();
}

void CurcleBack() {
	glBegin(GL_QUAD_STRIP);
	glColor3d(0.5, 0.0, 0.5);
	for (double i = 6, r = 5.025; i <= 186; i++) { // atan(0.1); 180 + atan(0.1)
		double x = r * cos(i * M_PI / 180) + 1; 
		double y = r * sin(i * M_PI / 180) + 9.5; 
		double Top[] = { x, y, 3 };
		double Bot[] = { x, y, 0 };
		glVertex3dv(Top);
		glVertex3dv(Bot);
	}
	glEnd();
}

void CurcleBackRotate(int f) {
	glBegin(GL_QUAD_STRIP);
	glColor3d(0.5, 0.0, 0.5);
	bool fl = true;
	for (double i = 6, r = 5.025; i <= 186; i++) { // atan(0.1); 180 + atan(0.1)
		if (fl) { glColor3d(0.5, 0, 0.5); fl = false; }
		else { glColor3d(0.4, 0, 0.6); fl = true; }
		double x = r * cos(i * M_PI / 180) + 1;
		double y = r * sin(i * M_PI / 180) + 9.5;
		glVertex3d(x, y, 0);
		double newX = x * cos(f * M_PI / 180) - y * sin(f * M_PI / 180);
		double newY = x * sin(f * M_PI / 180) + y * cos(f * M_PI / 180);
		glVertex3d(newX, newY, 3);
	}
	glEnd();
}

void HoleBack() {
	double O[] = { -7.8, -8.5};
	double A1[] = { 0, 0, 3 };
	double A[] = { 0, 0, 0 };
	glBegin(GL_QUAD_STRIP);
	glColor3d(0.5, 0.5, 0);
	glVertex3dv(A1);
	glVertex3dv(A);
	for (double i = 48, r = 11.55; i <= 96; i++) { 
		double x = r * cos(i * M_PI / 180) + O[0];
		double y = r * sin(i * M_PI / 180) + O[1];
		double Top[] = { x, y, 3 };
		double Bot[] = { x, y, 0 };
		glVertex3dv(Top);
		glVertex3dv(Bot);
	}
	glEnd();
}

void HoleBackRotate(int f) {
	double O[] = { -7.8, -8.5 };
	double A1[] = { 0, 0, 3 };
	double x = A1[0] * cos(f * M_PI / 180) - A1[1] * sin(f * M_PI / 180);
	double y = A1[0] * sin(f * M_PI / 180) + A1[1] * cos(f * M_PI / 180);
	A1[0] = x; A1[1] = y;
	double A[] = { 0, 0, 0 };
	glBegin(GL_QUAD_STRIP);
	glColor3d(0.5, 0.5, 0);
	glVertex3dv(A1);
	glVertex3dv(A);
	for (double i = 48, r = 11.55; i <= 96; i++) {
		double x = r * cos(i * M_PI / 180) + O[0];
		double y = r * sin(i * M_PI / 180) + O[1];
		double newX = x * cos(f * M_PI / 180) - y * sin(f * M_PI / 180);
		double newY = x * sin(f * M_PI / 180) + y * cos(f * M_PI / 180);
		double Top[] = { newX, newY, 3 };
		double Bot[] = { x, y, 0 };
		glVertex3dv(Top);
		glVertex3dv(Bot);
	}
	glEnd();
}

void Hole(int z) {
	double F[] = { -3, 5, z };
	double A[] = { 0, 0, z };
	double G[] = { -9, 3, z };
	double M[] = { -3, 2, z };
	double O[] = { -7.8, -8.5, z };

	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.75, 0.25, 0);
	glVertex3dv(F);
	glVertex3dv(A);
	for (double i = 48, r = 11.55; i <= 96; i++) {
		double x = r * cos(i * M_PI / 180) + O[0];
		double y = r * sin(i * M_PI / 180) + O[1];
		double New[] = { x, y, z };
		glVertex3dv(New);
	}
	glVertex3dv(G);
	glEnd();
}

void HoleRotate(int z, int f) {
	double F[] = { -3, 5, z };
	double x = F[0] * cos(f * M_PI / 180) - F[1] * sin(f * M_PI / 180);
	double y = F[0] * sin(f * M_PI / 180) + F[1] * cos(f * M_PI / 180);
	F[0] = x; F[1] = y;
	double A[] = { 0, 0, z };
	x = A[0] * cos(f * M_PI / 180) - A[1] * sin(f * M_PI / 180);
	y = A[0] * sin(f * M_PI / 180) + A[1] * cos(f * M_PI / 180);
	A[0] = x; A[1] = y;
	double G[] = { -9, 3, z };
	x = G[0] * cos(f * M_PI / 180) - G[1] * sin(f * M_PI / 180);
	y = G[0] * sin(f * M_PI / 180) + G[1] * cos(f * M_PI / 180);
	G[0] = x; G[1] = y;
	double M[] = { -3, 2, z };
	double O[] = { -7.8, -8.5, z };
	//x = O[0] * cos(f * M_PI / 180) - O[1] * sin(f * M_PI / 180);
	//y = O[0] * sin(f * M_PI / 180) + O[1] * cos(f * M_PI / 180);
	//O[0] = x; O[1] = y;

	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.75, 0.25, 0);
	glVertex3dv(F);
	glVertex3dv(A);
	for (double i = 48, r = 11.55; i <= 96; i++) {
		double x = r * cos(i * M_PI / 180) + O[0];
		double y = r * sin(i * M_PI / 180) + O[1];
		double newX = x * cos(f * M_PI / 180) - y * sin(f * M_PI / 180);
		double newY = x * sin(f * M_PI / 180) + y * cos(f * M_PI / 180);
		glVertex3d(newX, newY, z);
	}
	glVertex3dv(G);
	glEnd();
}

void Figure50(int f = 0) {
	const int SIZE = 7;
	double O[] = {0, 5, 0};
	double Bot[][3] = {
		{ 0, 0, 0 }, //A
		{ 9, 1, 0 }, //B
		{ 3, 5, 0 }, //C
		{ 6, 10, 0 }, //D
		{ -4, 9, 0 }, //E
		{ -3, 5, 0 }, //F
		{ -9, 3, 0 }  //G
	};
	double Top[][3] = {
		{ 0, 0, 3 }, //A1
		{ 9, 1, 3 }, //B1
		{ 3, 5, 3 }, //C1
		{ 6, 10, 3 }, //D1
		{ -4, 9, 3 }, //E1
		{ -3, 5, 3 }, //F1
		{ -9, 3, 3 }  //G1
	};
	
	glBegin(GL_QUAD_STRIP);
	glColor3d(0, 0, 1);
	for (int i = 0; i < SIZE; i++) {
			glVertex3dv(Top[i]);
			glVertex3dv(Bot[i]);
	}
	glEnd();
	HoleBack();
	glBegin(GL_POLYGON);
	glColor3d(1, 0, 0);
	for (int i = 0; i < SIZE - 1; i++) {
			glVertex3dv(Top[i]);
	}
	glEnd();
	Hole(3);
	glBegin(GL_POLYGON);
	glColor3d(0, 1, 0);
	for (int i = 0; i < SIZE - 1; i++) {
		glVertex3dv(Bot[i]);
	}
	glEnd();
	Hole(0);
	Curcle(0);
	Curcle(3);
	CurcleBack();
}

void Figure70(int f) {
	const int SIZE = 7;
	double Bot[][3] = {
		{ 0, 0, 0 }, //A
		{ 9, 1, 0 }, //B
		{ 3, 5, 0 }, //C
		{ 6, 10, 0 }, //D
		{ -4, 9, 0 }, //E
		{ -3, 5, 0 }, //F
		{ -9, 3, 0 }  //G
	};
	double Top[][3] = {
		{ 0, 0, 3 }, //A1
		{ 9, 1, 3 }, //B1
		{ 3, 5, 3 }, //C1
		{ 6, 10, 3 }, //D1
		{ -4, 9, 3 }, //E1
		{ -3, 5, 3 }, //F1
		{ -9, 3, 3 }  //G1
	};

	glBegin(GL_QUAD_STRIP);
	bool fl = true;
	for (int i = 0; i < SIZE; i++) {
		double x = Top[i][0] * cos(f * M_PI / 180) - Top[i][1] * sin(f * M_PI / 180);
		double y = Top[i][0] * sin(f * M_PI / 180) + Top[i][1] * cos(f * M_PI / 180);
		if (fl) { glColor3d(0, 0, 1); fl = false; }
		else { glColor3d(0.4, 0, 0.6); fl = true; }
		glVertex3d(x, y, Top[i][2]);
		glVertex3dv(Bot[i]);
	}
	glEnd();
	HoleBackRotate(f);
	glBegin(GL_POLYGON);
	glColor3d(1, 0, 0);
	for (int i = 0; i < SIZE - 1; i++) {
		double x = Top[i][0] * cos(f * M_PI / 180) - Top[i][1] * sin(f * M_PI / 180);
		double y = Top[i][0] * sin(f * M_PI / 180) + Top[i][1] * cos(f * M_PI / 180);
		glVertex3d(x, y, Top[i][2]);
	}
	glEnd();
	HoleRotate(3, f);
	glBegin(GL_POLYGON);
	glColor3d(0, 1, 0);
	for (int i = 0; i < SIZE - 1; i++) {
		glVertex3dv(Bot[i]);
	}
	glEnd();
	Hole(0);
	Curcle(0);
	CurcleRotate(3, f);
	CurcleBackRotate(f);
}

void Render(double delta_time)
{    
	//Figure();
	//Figure50(5);
	Figure70(0);
#pragma region pointM
	double M[] = { -3, 2, -1 };
	double M1[] = { -3, 2, 4 };
	glBegin(GL_LINES);
	glVertex3dv(M);
	glVertex3dv(M1);
	glEnd();
#pragma endregion
	//Curcle(0);
	//Curcle(3);
	//CurcleBack();
	//Hole();
}   

