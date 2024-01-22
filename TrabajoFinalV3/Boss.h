#pragma once
#pragma once
#include"Virus.h"
class Boss :public Virus
{
private:
	bool visibility;
	int lim;
public:
	Boss(int W, int H) :Virus(W, H)
	{
		srand(time(0));
		x = 500;
		y = 0;
		this->W = W;
		this->H = H;
		lim = 200;
	}
	~Boss()
	{

	}
	void dibujar(Graphics^ g, Bitmap^ bmp) {

		System::Drawing::Rectangle sectionShow = System::Drawing::Rectangle(indiceW * W , indiceH * H+lim, W, H);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W*0.6, H *0.6);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g) {
		indiceW++;
		if (indiceW == 4) {
			indiceW = 0;
		}
		if (indiceW==3|| indiceW == 2)
		{
			lim = 0;
		}
		else
		{
			lim = 200;
		}
	}
	bool getVisibility() { return visibility; }
	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x +200, y + 10, (W * 0.6), H * 0.6);
	}

};


