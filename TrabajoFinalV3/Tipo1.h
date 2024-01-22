#pragma once
#include"Virus.h"
class Tipo1 :public Virus
{
private:
	int dx;
	bool visibility;

public:
	Tipo1(int W, int H) :Virus(W, H)
	{
		srand(time(0));
		x = (rand()%200)+600;
		y = 470;
		dx = 10;
		visibility = true;
		this->W = W;
		this->H = H;
	}

	~Tipo1()
	{

	}



	void dibujar(Graphics^ g, Bitmap^ bmp) {

		System::Drawing::Rectangle sectionShow = System::Drawing::Rectangle(indiceW * W + 10, indiceH * H, W, H);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W * 0.08, H * 0.08);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g) {
		if (x + W * 0.08 > g->VisibleClipBounds.Width || x < 0)
			dx *= -1;
		x += dx;
		indiceW++;
		if (indiceW == 4) {
			indiceW = 0;
		}
	}
	void setVisibility(bool v) { visibility = v; }
	bool getVisibility() { return visibility; }
	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x - 10, y + 10, (W * 0.08) - 30, H * 0.08);
	}

};

