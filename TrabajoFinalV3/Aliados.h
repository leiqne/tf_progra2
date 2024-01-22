#pragma once
#include<iostream>
using namespace std;
using namespace System::Drawing;
class Aliados
{
protected:
	int x, y, dx, dy, W, H, indiceW, indiceH;
	char direccion;

public:
	Aliados(int width, int height) {
		W = width;
		H = height;
		dy = 15;
		dx = 25;
		x = x;
		y = y;
		indiceW = indiceH = 0;
		direccion = 'S';
	}
	~Aliados() {

	}
	void setX(int x) {
		this->x = x;
	}
	void sety(int y) {
		this->y = y;
	}
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
	virtual void dibujar(Graphics^ g, Bitmap^ bmp) {}
	virtual void mover(Graphics^ g, char i) {}
	char getDireccion() { return direccion; }


};
