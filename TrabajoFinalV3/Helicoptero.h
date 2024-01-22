#pragma once
#include"Aliados.h"
class Helicoptero : public Aliados
{
private:
	bool HeliFinal = false;
public:
	Helicoptero(int W, int H) :Aliados(W, H) {
		x = 80;
		y = 100;
		dy = 0;
	}
	~Helicoptero() {}

	bool getHelicoptero()
	{
		return HeliFinal;
	}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		System::Drawing::Rectangle sectionShow = System::Drawing::Rectangle(indiceW * W, indiceH * H, W, H);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W * 1.0, H * 1.0);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g) {
		if (dx > 0) {
			indiceH = 2;
		}
		if (x + W * 1.0 > g->VisibleClipBounds.Width) {
			indiceH = 1;
			dx = 0;
			dy = 5;
		}
		if (y + H * 1.0 > g->VisibleClipBounds.Height - 40)
		{
			dy = 0;
			indiceH = 0;
			HeliFinal = true;

		}
		x += dx;
		y += dy;
		/*	if (y > 0) {
				indiceH = 3;
			}
			y -= dy;
			if (y + H * 1.0 < g->VisibleClipBounds.Height) {
				indiceH = 0;
			}
			y += dy;*/
		indiceW++;
		if (indiceW > 2) indiceW = 0;
	}
	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x, y, W, H);
	}
};