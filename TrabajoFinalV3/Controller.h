#pragma once
#include"Doctor.h"
#include"Vacuna.h"
#include"Helicoptero.h"
#include"Tipo1.h"
#include"Tipo2.h"
#include<vector>
#include "Boss.h"
using namespace System::Media;
class Controller
{
private:
	vector<Vacuna*>* vacunas;
	vector<Doctor*>* arrD;
	vector<Helicoptero*>* arrH;
	vector<Tipo1*>* tipo1;
	vector<Tipo2*>* tipo2;
	int vidas;
	int puntos;
	int bvidas;
	bool colConH = false;
	int contvac = 0;
	int potdoc;
public:
	Controller() {
		vacunas = new vector<Vacuna*>();
		arrD = new vector<Doctor*>();
		arrH = new vector<Helicoptero*>();
		tipo1 = new vector<Tipo1*>();
		tipo2 = new vector<Tipo2*>();
		vidas = 3;
		puntos = 5;
		bvidas = 1000;
		potdoc = 0;
	}
	~Controller() {}
	void createDoctor(int width, int height) {
		Doctor* d = new Doctor(width, height);
		arrD->push_back(d);
	}

	void SetVacunas(int VacunasNivelAnteior)
	{
		contvac = VacunasNivelAnteior;
	}

	bool getHeli()
	{
		return colConH;
	}

	int getDoctor()
	{

		return arrD->size();
	}
	void createHelicoptero(int width, int height) {
		if (arrH->size() < 1)
		{
			Helicoptero* h = new Helicoptero(width, height);
			arrH->push_back(h);
		}

	}
	void createTipo1(int width, int height) {
		if (tipo1->size() < 4)
		{
			Tipo1* t1 = new Tipo1(width, height);
			tipo1->push_back(t1);
		}
	}
	void createTipo2(int width, int height) {

		Tipo2* t2 = new Tipo2(width, height);
		tipo2->push_back(t2);

	}
	void createTipo2(int width, int height, int y, int id) {
		srand(time(0));
		Tipo2* t2 = new Tipo2(width, height, id);
		tipo2->push_back(t2);

	}
	void addVacuna(int W, int H) {
		for (int i = 0; i < arrD->size(); i++)
		{
			Vacuna* v = new Vacuna(arrD->at(i)->getX(), arrD->at(i)->getY(), W, H);
			vacunas->push_back(v);
			
		}
	}
	void addVacuna(int W, int H, Doctor* d) {
			Vacuna* v = new Vacuna(d->getX(), d->getY(), W, H);
			vacunas->push_back(v);

	}
	void DibujarTodo(Graphics^ g, Bitmap^ bmpEnemigo, Bitmap^ bmpBala, Bitmap^ bmpHelicoptero, Bitmap^ bmpTipo1, Bitmap^ bmpTipo2) {
		for (int i = 0; i < arrD->size(); i++)
		{
			arrD->at(i)->dibujar(g, bmpEnemigo);
		}
		for (int i = 0; i < vacunas->size(); i++)
		{
			vacunas->at(i)->dibujar(g, bmpBala);
		}
		for (int i = 0; i < arrH->size(); i++)
		{
			arrH->at(i)->dibujar(g, bmpHelicoptero);
		}
		for (int i = 0; i < tipo1->size(); i++)
		{
			tipo1->at(i)->dibujar(g, bmpTipo1);
		}
		for (int i = 0; i < tipo2->size(); i++)
		{
			tipo2->at(i)->dibujar(g, bmpTipo2);
		}
	}
	void DibujarTodo(Graphics^ g,  Bitmap^ bmpBala, Bitmap^ bmpTipo2) {
		for (int i = 0; i < vacunas->size(); i++)
		{
			vacunas->at(i)->dibujar(g, bmpBala);
		}
		for (int i = 0; i < tipo2->size(); i++)
		{
			tipo2->at(i)->dibujar(g, bmpTipo2);
		}
	}
	void MoverTodo(Graphics^ g, int id) {

		for (int i = 0; i < vacunas->size(); i++)
		{
			vacunas->at(i)->mover(g, id);
		}
		for (int i = 0; i < tipo2->size(); i++)
		{
			tipo2->at(i)->mover(g, id);
		}
	}
	void MoverTodo(Graphics^ g) {
		for (int i = 0; i < arrD->size(); i++)
		{
			arrD->at(i)->mover(g);
		}
		for (int i = 0; i < vacunas->size(); i++)
		{
			vacunas->at(i)->mover(g);
		}
		for (int i = 0; i < arrH->size(); i++)
		{
			arrH->at(i)->mover(g);
		}
		for (int i = 0; i < tipo1->size(); i++)
		{
			tipo1->at(i)->mover(g);
		}
		for (int i = 0; i < tipo2->size(); i++)
		{
			tipo2->at(i)->mover(g);
		}
	}
	void colision(Graphics^ g, Personaje* personaje, SoundPlayer^ s3, SoundPlayer^ c, SoundPlayer^ p) {
		for (int i = 0; i < vacunas->size(); i++)
		{
			if (vacunas->at(i)->getX() <= 0 || vacunas->at(i)->getXWidth() >= g->VisibleClipBounds.Width ||
				vacunas->at(i)->getY() <= 0 || vacunas->at(i)->getYHeight() >= g->VisibleClipBounds.Height) {
				vacunas->at(i)->setVisibility(false);
			}
		}
		//vacunas enemigo
		for (int i = 0; i < tipo1->size(); i++)
		{
			for (int j = 0; j < vacunas->size(); j++)
			{
				if (tipo1->at(i)->getRectangle().IntersectsWith(vacunas->at(j)->getRectangle())) {

					tipo1->at(i)->setVisibility(false);
					vacunas->at(j)->setVisibility(false);
				}
			}
		}

		//personaje enemigo
		for (int i = 0; i < tipo1->size(); i++)
		{
			if (personaje->getRectangle().IntersectsWith(tipo1->at(i)->getRectangle()))
			{
				s3->Play();
				tipo1->at(i)->setVisibility(false);

				vidas--;

			}
		}
		//enemigo 2
		for (int i = 0; i < tipo2->size(); i++)
		{
			if (personaje->getRectangle().IntersectsWith(tipo2->at(i)->getRectangle()))
			{
				s3->Play();
				tipo2->at(i)->setVisibility(false);
				vidas--;
			}
		}

		//vacunas personaje
		for (int j = 0; j < vacunas->size(); j++)
		{

			if (vacunas->at(j)->getRectangle().IntersectsWith(personaje->getRectangle())) {
				vacunas->at(j)->setVisibility(false);
				if (vidas < 3)
				{
					c->Play();
					vidas = vidas + 1;
				}
				else
				{
					p->Play();
					puntos = puntos + 2;
					
				}
				contvac++;

			}
		}
		//Helicoptero
		for (int i = 0; i < arrH->size(); i++)
		{
			if (arrH->at(i)->getHelicoptero() == true)
			{
				if (personaje->getRectangle().IntersectsWith(arrH->at(i)->getRectangle()))
				{


					this->colConH = true;
				}
			}
		}

		//borrar
		for (int i = 0; i < vacunas->size(); i++)
		{
			if (!vacunas->at(i)->getVisibility()) {
				vacunas->erase(vacunas->begin() + i);
			}
		}

		for (int i = 0; i < tipo1->size(); i++)
		{
			if (!tipo1->at(i)->getVisibility()) {
				tipo1->erase(tipo1->begin() + i);
			}
		}
		for (int i = 0; i < tipo2->size(); i++)
		{
			if (!tipo2->at(i)->getVisibility()) {
				tipo2->erase(tipo2->begin() + i);
			}
		}
	}
	void colision(Graphics^ g, Personaje* personaje,Boss*b1, SoundPlayer^ s3, SoundPlayer^ c, SoundPlayer^ p) {
		for (int i = 0; i < vacunas->size(); i++)
		{
			if (vacunas->at(i)->getX() <= 0 || vacunas->at(i)->getXWidth() >= g->VisibleClipBounds.Width ||
				vacunas->at(i)->getY() <= 0 || vacunas->at(i)->getYHeight() >= g->VisibleClipBounds.Height) {
				vacunas->at(i)->setVisibility(false);
			}
		}
		for (int i = 0; i < tipo2->size(); i++)
		{
			if (tipo2->at(i)->getX() <= 0 || tipo2->at(i)->getXWidth() >= g->VisibleClipBounds.Width) {
				tipo2->at(i)->setVisibility(false);
			}
		}
		//vacunas enemigo
		for (int i = 0; i < vacunas->size(); i++) {
			if (b1->getRectangle().IntersectsWith(vacunas->at(i)->getRectangle())) {
				vacunas->at(i)->setVisibility(false);
				bvidas =bvidas-(potdoc*8);
			}
		}

		//personaje enemigo
		for (int i = 0; i < tipo2->size(); i++)
		{
			if (personaje->getRectangle().IntersectsWith(tipo2->at(i)->getRectangle()))
			{
				s3->Play();
				tipo2->at(i)->setVisibility(false);
				vidas--;
			}
		}

		//vacunas personaje
		for (int j = 0; j < vacunas->size(); j++)
		{
			if (vacunas->at(j)->getRectangle().IntersectsWith(personaje->getRectangle())) {
				vacunas->at(j)->setVisibility(false);
				if (vidas < 3)
				{
					c->Play();
					vidas = vidas + 1;
				}
				else
				{
					p->Play();
					puntos = puntos + 2;

				}
				contvac++;

			}
		}

		//borrar
		for (int i = 0; i < vacunas->size(); i++)
		{
			if (!vacunas->at(i)->getVisibility()) {
				vacunas->erase(vacunas->begin() + i);
			}
		}

		for (int i = 0; i < tipo1->size(); i++)
		{
			if (!tipo1->at(i)->getVisibility()) {
				tipo1->erase(tipo1->begin() + i);
			}
		}
		for (int i = 0; i < tipo2->size(); i++)
		{
			if (!tipo2->at(i)->getVisibility()) {
				tipo2->erase(tipo2->begin() + i);
			}
		}
	}
	int getvidas() {
		return vidas;
	}
	int getvacunas() {
		return contvac;
	}
	int getPuntos()
	{
		return puntos;
	}
	void setpotDoc(int x) {
		this->potdoc = x;
	}
	int getBVida() { return this->bvidas; }
};


