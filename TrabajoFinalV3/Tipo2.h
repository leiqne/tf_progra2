#pragma once
#include"Virus.h"
#include <time.h>
using namespace System;
class Tipo2 :public Virus
{
private:
	int dx;
	int dy;
	bool visibility;
public:
	Tipo2(int W, int H) :Virus(W, H)
	{
		srand(time(0));
		x = rand() % 300 + 250;
		y = rand() % 200 + 50;
		dx = 15;
		dy = 15;
		visibility = true;
	}
	Tipo2(int W, int H, int id) :Virus(W, H)
	{
		Random r;
		x = 720;
		this->y = r.Next(101,490);
		dx = -28;
		dy = 15;
		visibility = true;
	}

	~Tipo2()
	{

	}
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		System::Drawing::Rectangle sectionShow = System::Drawing::Rectangle(indiceW * W, indiceH * H, W, H);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W * 0.15, H * 0.15);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g) {
		if (x + W * 0.15 > g->VisibleClipBounds.Width || x < 0)	dx *= -1;
		if (y + H * 0.15 > g->VisibleClipBounds.Height || y < 0)	dy *= -1;
		x +=dx;
		y += dy;

		indiceW++;
		if (indiceW > 3) {
			indiceW = 0;
		}
	}
	void mover(Graphics^ g, int id) {
		x += dx;

		indiceW++;
		if (indiceW > 3) {
			indiceW = 0;
		}
	}
	int getXWidth() { return x + W * 0.15; }
	void setVisibility(bool v) { visibility = v; }
	bool getVisibility() { return visibility; }
	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x, y, (W * 0.15) - 5, (H * 0.15) - 10);
	}


};
