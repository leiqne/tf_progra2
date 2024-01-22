#pragma once
#include"Aliados.h"
#include <time.h>
using namespace std;
class Doctor : public Aliados
{
private:
	
public:
	Doctor(int W, int H) :Aliados(W, H) {

		srand(time(0));

		x = rand()%800+50;
		y = 50;
	}
	Doctor(int W, int H, int id ) :Aliados(W, H) {
		x = 10;
		y = 50;
	}
	~Doctor() {}
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		System::Drawing::Rectangle sectionShow = System::Drawing::Rectangle(indiceW * W, indiceH * H, W, H);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W * 0.25, H * 0.25);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g) {

		//if (direccion == 1) { // los enemigos se mueven de izquierda a derecha
		if (x + W * 0.25 > g->VisibleClipBounds.Width || x < 0) dx *= -1;

		if (dx > 0) { //dx=20
			indiceH = 2;
		}
		else // dx=-20
			indiceH = 2;
		x += dx;
		/*}*/
			/*if (y +H * 0.25 > g->VisibleClipBounds.Height || y < 0) dy *= -1;

			if (dy > 0) {
				indiceH = 0;
			}
			else
				indiceH = 1;
			y += dy;*/

		indiceW++;
		if (indiceW > 4)
			indiceW = 0;
	}
	void mover(Graphics^ g, int id) {

		//if (direccion == 1) { // los enemigos se mueven de izquierda a derecha
		if (y + H * 0.25 > g->VisibleClipBounds.Height-20 || y < 50) dy *= -1;

		if (dy > 0) { //dx=20
			indiceH = 2;
		}
		else // dx=-20
			indiceH = 2;
		y += dy;
		/*}*/
			/*if (y +H * 0.25 > g->VisibleClipBounds.Height || y < 0) dy *= -1;

			if (dy > 0) {
				indiceH = 0;
			}
			else
				indiceH = 1;
			y += dy;*/

		indiceW++;
		if (indiceW > 4)
			indiceW = 0;
	}
};