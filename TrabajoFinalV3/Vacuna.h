#pragma once
#include"Aliados.h"
#include <iostream>



class Vacuna : public Aliados {
private:
	bool visibility;
public:
	Vacuna(int X, int Y, int W, int H) : Aliados(W, H) {
		x = X;
		y = Y;
		visibility = true;
	}
	~Vacuna() {}
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		System::Drawing::Rectangle sectionShow = System::Drawing::Rectangle(indiceW * W, indiceH * H, W, H);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W * 0.3, H * 0.3);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}

	void mover(Graphics^ g)
	{
		y += dy;

	}

	void mover(Graphics^ g, int id)
	{
		x += dx;
	}

	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x, y, (W * 0.3), H * 0.3);
	}
	int getXWidth() { return x + W * 0.3; }
	int getYHeight() { return y + H * 0.3; }
	void setVisibility(bool v) { visibility = v; }
	bool getVisibility() { return visibility; }

};