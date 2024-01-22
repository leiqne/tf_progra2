#pragma once
#include<iostream>

using namespace std;
using namespace System::Drawing;
class Personaje
{
private:
	int x, y, dx, dy, W, H, indiceW, indiceH;
	char direccion;
	char dir;
	int contac = 1;
	int lim ;

public:
	Personaje(int w, int h) {
		this->W = w;
		this->H = h;
		this->lim = 1120;
		dx = 15;
		dy = 0;
		x = 70;
		y = 300;
		indiceW = indiceH = 0;
		direccion = 'N';
		dir = 'N';
	}
	~Personaje() {

	}
	void setLim(int l) {
		this->lim = l;	}
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
	int getindW()
	{
		return indiceW;
	}
	int getindH()
	{
		return indiceH;
	}
	int getdy()
	{
		return y;
	}

	void dibujar(Graphics^ g, Bitmap^ bmp) {

		System::Drawing::Rectangle sectionShow = System::Drawing::Rectangle(indiceW * W, indiceH * H, W, H);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W * 0.4, H * 0.4);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);

	}
	void move(Graphics^ g)
	{
		if (indiceW < 0)
		{
			indiceW = 0;
		}
		if (y + dy > 0)
		{
			y += dy;

		}

		//si es que hay salto, debe volver a la posicion inicial
		dy = dy + 2;
		if (y > 475)
		{
			y = 475; dy = 0;

		}
		indiceW++;
		if (direccion == 'D')
		{
			if (dir == 'S')
			{
				if (indiceW > 5)
				{
					indiceW = 0;
					indiceH = 3;
				}

				if (indiceH == 3 && indiceW == 2)
				{
					if (dy < 0)
					{
						indiceW--;
					}


				}
				if (y == 475)
				{
					indiceH = 0;
					indiceW = 0;
					direccion = 'N';
					dir = 'l';
				}
				if (dy > 0)
				{
					indiceH = 3;
					indiceW = 1;
					indiceW--;
				}

			}
			if (indiceW > 5 && indiceH == 1)
			{
				indiceW = 0;
				indiceH++;
			}
			if (indiceW == 3 && indiceH == 2)
			{
				indiceH = 1;
				indiceW = 4;
			}

			if (x + W < lim) {
				x += dx;
			}
		}
		if (direccion == 'A')
		{

			if (dir == 'S')
			{
				if (indiceW > 5)
				{
					indiceW = 0;
					indiceH = 3;
				}

				if (indiceH == 3 && indiceW == 2)
				{
					if (dy < 0)
					{
						indiceW--;

					}


				}
				if (y == 475)
				{
					indiceH = 0;
					indiceW = 0;
					direccion = 'N';
					dir = 'l';
				}
				if (dy > 0)
				{
					indiceH = 3;
					indiceW = 1;
					indiceW--;
				}
				if (indiceH < 0)
				{
					indiceH = 0;
				}
			}

			if (indiceW > 5 && indiceH == 0)
			{
				indiceW = 0;
				indiceH++;
			}
			if (indiceH == 1 && indiceW == 3)
			{
				indiceW = 4;
				indiceH = 0;
			}



			if (x > 0) {

				x -= dx;
			}
		}
		if (direccion == 'N')
		{
			if (dir == 'S')
			{
				if (indiceW > 5)
				{
					indiceW = 0;
					indiceH = 3;
				}

				if (indiceH == 3 && indiceW == 2)
				{
					if (dy < 0)
					{
						indiceW--;
					}


				}
				if (y == 475)
				{
					indiceH = 0;
					indiceW = 0;
					direccion = 'N';
					dir = 'l';
				}
				if (dy > 0)
				{
					indiceH = 3;
					indiceW = 1;
					indiceW--;
				}

			}
			if (indiceW > 3)
			{
				indiceW = 0;
			}


		}


	}
	void mover(Graphics^ g, char i) {
		//movement

		switch (i)
		{
		case 'A':

			if (x > 0) {

				indiceH = 0;
				indiceW = 4;

				direccion = 'A';
			}
			break;
		case 'D':
			if (x + W < g->VisibleClipBounds.Width) {

				indiceH = 1;
				indiceW = 4;
				direccion = 'D';



			}
			break;

		case 'N':
		{
			direccion = 'N';
			indiceH = 0;
			indiceW = 0;
		}

		default:
		{

		}
		break;
		}



	}
	char getDireccion() { return direccion; }
	void saltar() {
		indiceH = 2;
		indiceW = 5;
		dy = -20;
		dx = 13;
		dir = 'S';
	}
	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x - 10, y - 3, (W * 0.4) - 20, (H * 0.4) - 10);
	}


};

