#pragma once
#include<iostream>
using namespace std;
using namespace System::Drawing;

class Virus
{
protected:
	int x, y, W, H, indiceW, indiceH;
public:
	Virus(int width, int height) {
		W = width;
		H = height;
		x = x;
		y = y;
		indiceW = indiceH = 0;
	}
	~Virus() {}
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}

	virtual void dibujar(Graphics^ g, Bitmap^ bmp) {}
	virtual void mover(Graphics^ g, char i) {}

};
