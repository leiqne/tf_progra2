#pragma once
#include"Personaje.h"
#include"Controller.h"
#include <fstream>
#include <thread>

namespace TrabajoFinalV3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Nivel3
	/// </summary>
	public ref class Nivel3 : public System::Windows::Forms::Form
	{
	public:
		Nivel3(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			gr = pnlCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(gr, pnlCanvas->ClientRectangle);
			bmpHero = gcnew Bitmap("Personaje Principal.png");
			bmpMap = gcnew Bitmap("Segundo Nivel.png");
			bmpDoc = gcnew Bitmap("Doctor.png");
			bmpAllow2 = gcnew Bitmap("Avion.png");
			bmpBullet = gcnew Bitmap("Vacuna1.png");
			bmpboss = gcnew Bitmap("Virus1.png");
			bmpTipo2 = gcnew Bitmap("Virus2.png");
			personaje = new Personaje(bmpHero->Width / 6, bmpHero->Height / 5);
			doc1 = new Doctor(bmpDoc->Width / 8, bmpDoc->Height / 5,1);
			b1 = new Boss(bmpboss->Width / 5, bmpboss->Height / 2);
			controller = new Controller();
			S2 = gcnew SoundPlayer("jump.wav");
			S3 = gcnew SoundPlayer("oof.wav");
			curacion = gcnew SoundPlayer("curacion.wav");
			pts = gcnew SoundPlayer("puntos.wav");
			puntos = 5;
			pause = false;
			win = false;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Nivel3()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Graphics^ gr;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpHero;
		Bitmap^ bmpMap;
		Bitmap^ bmpDoc;
		Bitmap^ bmpBullet;
		Bitmap^ bmpAllow2;
		Bitmap^ bmpboss;
		Personaje* personaje;
		Boss* b1;
		Doctor* doc1;
		Bitmap^ bmpTipo2;
		Controller* controller;
		//SoundPlayer^ S1;
		SoundPlayer^ S2;
		SoundPlayer^ S3;
		SoundPlayer^ curacion;
		SoundPlayer^ pts;
		int puntos;
		bool pause;
		int cont;
		bool NivelCompleto = false;
		bool cerrar = false;
		bool win;


		int puntosSum;
		int DocNivAnt;
		int VacunasLvl1;
		int PuntosNivAnt;


	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ pnlCanvas;
	private: System::Windows::Forms::Timer^ timer_doctor;
	private: System::Windows::Forms::Timer^ timer_virus;

	private: System::Windows::Forms::Timer^ timer_v2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::TextBox^ gameov2;

	private: System::Windows::Forms::TextBox^ gamov;
	private: System::Windows::Forms::TextBox^ Pause;
	private: System::Windows::Forms::TextBox^ Pause2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Timer^ MoveBoss;
	private: System::Windows::Forms::Timer^ createT2;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->Pause2 = (gcnew System::Windows::Forms::TextBox());
			   this->Pause = (gcnew System::Windows::Forms::TextBox());
			   this->gameov2 = (gcnew System::Windows::Forms::TextBox());
			   this->gamov = (gcnew System::Windows::Forms::TextBox());
			   this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			   this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			   this->timer_doctor = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timer_virus = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timer_v2 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->MoveBoss = (gcnew System::Windows::Forms::Timer(this->components));
			   this->createT2 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pnlCanvas->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Tick += gcnew System::EventHandler(this, &Nivel3::timer1_Tick);
			   // 
			   // pnlCanvas
			   // 
			   this->pnlCanvas->Controls->Add(this->textBox4);
			   this->pnlCanvas->Controls->Add(this->textBox3);
			   this->pnlCanvas->Controls->Add(this->textBox2);
			   this->pnlCanvas->Controls->Add(this->label2);
			   this->pnlCanvas->Controls->Add(this->textBox1);
			   this->pnlCanvas->Controls->Add(this->Pause2);
			   this->pnlCanvas->Controls->Add(this->Pause);
			   this->pnlCanvas->Controls->Add(this->gameov2);
			   this->pnlCanvas->Controls->Add(this->gamov);
			   this->pnlCanvas->Controls->Add(this->progressBar2);
			   this->pnlCanvas->Controls->Add(this->progressBar1);
			   this->pnlCanvas->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pnlCanvas->Location = System::Drawing::Point(0, 0);
			   this->pnlCanvas->Name = L"pnlCanvas";
			   this->pnlCanvas->Size = System::Drawing::Size(1011, 566);
			   this->pnlCanvas->TabIndex = 0;
			   this->pnlCanvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Nivel3::pnlCanvas_Paint);
			   this->pnlCanvas->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Nivel3::pnlCanvas_MouseClick);
			   // 
			   // textBox4
			   // 
			   this->textBox4->BackColor = System::Drawing::Color::White;
			   this->textBox4->Enabled = false;
			   this->textBox4->Font = (gcnew System::Drawing::Font(L"Arcade Normal", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->textBox4->Location = System::Drawing::Point(3, 279);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->ReadOnly = true;
			   this->textBox4->Size = System::Drawing::Size(1008, 31);
			   this->textBox4->TabIndex = 13;
			   this->textBox4->Text = L"Lograste mejorar el sistema de salud";
			   this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   this->textBox4->Visible = false;
		
			   // 
			   // textBox3
			   // 
			   this->textBox3->BackColor = System::Drawing::Color::White;
			   this->textBox3->Enabled = false;
			   this->textBox3->Font = (gcnew System::Drawing::Font(L"Arcade Normal", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->textBox3->Location = System::Drawing::Point(0, 316);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->ReadOnly = true;
			   this->textBox3->Size = System::Drawing::Size(1008, 31);
			   this->textBox3->TabIndex = 12;
			   this->textBox3->Text = L"press \"esc\" to continue";
			   this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   this->textBox3->Visible = false;
			   // 
			   // textBox2
			   // 
			   this->textBox2->BackColor = System::Drawing::Color::White;
			   this->textBox2->Enabled = false;
			   this->textBox2->Font = (gcnew System::Drawing::Font(L"Arcade Normal", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->textBox2->Location = System::Drawing::Point(3, 208);
			   this->textBox2->Multiline = true;
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->ReadOnly = true;
			   this->textBox2->Size = System::Drawing::Size(1011, 65);
			   this->textBox2->TabIndex = 11;
			   this->textBox2->Text = L"YOU WIN";
			   this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   this->textBox2->Visible = false;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::SystemColors::ScrollBar;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Arcade Normal", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->label2->Location = System::Drawing::Point(667, 548);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(214, 10);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"puntos: 0 vidas: 0 ";
			   // 
			   // textBox1
			   // 
			   this->textBox1->BackColor = System::Drawing::Color::Gray;
			   this->textBox1->Enabled = false;
			   this->textBox1->Location = System::Drawing::Point(-3, 544);
			   this->textBox1->Multiline = true;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->ReadOnly = true;
			   this->textBox1->Size = System::Drawing::Size(1014, 22);
			   this->textBox1->TabIndex = 9;
			   // 
			   // Pause2
			   // 
			   this->Pause2->BackColor = System::Drawing::Color::White;
			   this->Pause2->Enabled = false;
			   this->Pause2->Font = (gcnew System::Drawing::Font(L"Arcade Normal", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Pause2->ForeColor = System::Drawing::Color::Blue;
			   this->Pause2->Location = System::Drawing::Point(3, 303);
			   this->Pause2->Multiline = true;
			   this->Pause2->Name = L"Pause2";
			   this->Pause2->ReadOnly = true;
			   this->Pause2->Size = System::Drawing::Size(1005, 29);
			   this->Pause2->TabIndex = 7;
			   this->Pause2->Text = L"press \"c\" to continue";
			   this->Pause2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   this->Pause2->Visible = false;
			   // 
			   // Pause
			   // 
			   this->Pause->BackColor = System::Drawing::Color::White;
			   this->Pause->Enabled = false;
			   this->Pause->Font = (gcnew System::Drawing::Font(L"Arcade Normal", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Pause->ForeColor = System::Drawing::Color::Blue;
			   this->Pause->Location = System::Drawing::Point(3, 208);
			   this->Pause->Multiline = true;
			   this->Pause->Name = L"Pause";
			   this->Pause->ReadOnly = true;
			   this->Pause->Size = System::Drawing::Size(1005, 65);
			   this->Pause->TabIndex = 6;
			   this->Pause->Text = L"PAUSE";
			   this->Pause->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   this->Pause->Visible = false;
			   this->Pause->TextChanged += gcnew System::EventHandler(this, &Nivel3::textBox1_TextChanged);
			   // 
			   // gameov2
			   // 
			   this->gameov2->BackColor = System::Drawing::Color::Black;
			   this->gameov2->Font = (gcnew System::Drawing::Font(L"Arcade Normal", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->gameov2->ForeColor = System::Drawing::Color::Red;
			   this->gameov2->Location = System::Drawing::Point(289, 301);
			   this->gameov2->Name = L"gameov2";
			   this->gameov2->Size = System::Drawing::Size(411, 31);
			   this->gameov2->TabIndex = 5;
			   this->gameov2->Text = L"press \"esc\" to close";
			   this->gameov2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   this->gameov2->Visible = false;
			   this->gameov2->TextChanged += gcnew System::EventHandler(this, &Nivel3::textBox2_TextChanged);
			   // 
			   // gamov
			   // 
			   this->gamov->BackColor = System::Drawing::Color::Black;
			   this->gamov->Font = (gcnew System::Drawing::Font(L"Arcade Normal", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->gamov->ForeColor = System::Drawing::Color::Red;
			   this->gamov->Location = System::Drawing::Point(209, 208);
			   this->gamov->Name = L"gamov";
			   this->gamov->Size = System::Drawing::Size(588, 87);
			   this->gamov->TabIndex = 4;
			   this->gamov->Text = L"GAME OVER";
			   this->gamov->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   this->gamov->Visible = false;
			   // 
			   // progressBar2
			   // 
			   this->progressBar2->BackColor = System::Drawing::Color::Purple;
			   this->progressBar2->ForeColor = System::Drawing::Color::Cyan;
			   this->progressBar2->Location = System::Drawing::Point(617, 10);
			   this->progressBar2->Name = L"progressBar2";
			   this->progressBar2->Size = System::Drawing::Size(382, 16);
			   this->progressBar2->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			   this->progressBar2->TabIndex = 3;
			   // 
			   // progressBar1
			   // 
			   this->progressBar1->BackColor = System::Drawing::Color::Purple;
			   this->progressBar1->ForeColor = System::Drawing::Color::Cyan;
			   this->progressBar1->Location = System::Drawing::Point(12, 10);
			   this->progressBar1->Name = L"progressBar1";
			   this->progressBar1->Size = System::Drawing::Size(384, 16);
			   this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			   this->progressBar1->TabIndex = 2;
			   this->progressBar1->Click += gcnew System::EventHandler(this, &Nivel3::progressBar1_Click);
			   // 
			   // timer_doctor
			   // 
			   this->timer_doctor->Enabled = true;
			   this->timer_doctor->Interval = 2000;
			   this->timer_doctor->Tick += gcnew System::EventHandler(this, &Nivel3::timer_doctor_Tick);
			   // 
			   // timer_virus
			   // 
			   this->timer_virus->Enabled = true;
			   this->timer_virus->Interval = 5000;
			   this->timer_virus->Tick += gcnew System::EventHandler(this, &Nivel3::timer_virus_Tick);
			   // 
			   // timer_v2
			   // 
			   this->timer_v2->Enabled = true;
			   this->timer_v2->Interval = 10000;
			   this->timer_v2->Tick += gcnew System::EventHandler(this, &Nivel3::timer_v2_Tick);
			   // 
			   // MoveBoss
			   // 
			   this->MoveBoss->Enabled = true;
			   this->MoveBoss->Interval = 1500;
			   this->MoveBoss->Tick += gcnew System::EventHandler(this, &Nivel3::MoveBoss_Tick);
			   // 
			   // createT2
			   // 
			   this->createT2->Enabled = true;
			   this->createT2->Interval = 900;
			   this->createT2->Tick += gcnew System::EventHandler(this, &Nivel3::createT2_Tick);
			   // 
			   // Nivel3
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1011, 566);
			   this->Controls->Add(this->pnlCanvas);
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"Nivel3";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Nivel3";
			   this->Load += gcnew System::EventHandler(this, &Nivel3::Nivel3_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel3::Nivel3_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel3::Nivel3_KeyUp);
			   this->pnlCanvas->ResumeLayout(false);
			   this->pnlCanvas->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		if (controller->getvidas() == 0)
		{
			timer1->Enabled = false;
			buffer->Graphics->Clear(Color::Black);
			gamov->Visible = true;
			gameov2->Visible = true;
		}

		label2->BackColor = Color::Transparent;
		//clear
		//buffer->Graphics->Clear(Color::Black);
		controller->colision(buffer->Graphics, personaje, b1, S3, curacion, pts);
		if (controller->getvidas() != 0) {
			buffer->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 0.8, bmpMap->Height * 0.8);

		}
		controller->DibujarTodo(buffer->Graphics, bmpBullet,bmpTipo2);
		personaje->dibujar(buffer->Graphics, bmpHero);
		b1->dibujar(buffer->Graphics, bmpboss);
		doc1->dibujar(buffer->Graphics, bmpDoc);
		label2->Text = "puntos: " + System::Convert::ToString(controller->getPuntos() - 5) + " " + "Vidas: " +
			System::Convert::ToString(controller->getvidas()) + " Boss: " + System::Convert::ToString(controller->getBVida());
	
		if (controller->getBVida() * 0.1>0)
		{
			progressBar2->Value = controller->getBVida() * 0.1;
		}else
		{
			progressBar2->Value = 0;
		}
		if (progressBar2->Value == 0)
		{
			textBox2->Visible = true;
			textBox3->Visible = true;
			textBox4->Visible = true;
			timer1->Enabled = false; timer_v2->Enabled = false; timer_virus->Enabled = false;
			timer_doctor->Enabled = false;
			win = true;
		}

		if (controller->getvidas() == 3)
		{
			progressBar1->Value = 100;
		}
		if (controller->getvidas() == 2)
		{
			progressBar1->Value = 67;
		}
		if (controller->getvidas() == 1)
		{
			progressBar1->Value = 33;
		}
		if (controller->getvidas() == 0)
		{
			progressBar1->Value = 0;
		}
		controller->MoverTodo(buffer->Graphics, 1);
		personaje->move(buffer->Graphics);
		doc1->mover(buffer->Graphics, 1);
		//Render
		if (cerrar == false)
		{
			buffer->Render(gr);
		}
	}
	private: System::Void Nivel3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (cont < 1)
		{
			switch (e->KeyCode)
			{
			case Keys::A:
				if (!pause)personaje->mover(buffer->Graphics, 'A'); break;

			case Keys::D:
				if (!pause)personaje->mover(buffer->Graphics, 'D'); break;
			case Keys::P:
				Pause->Visible = true;
				Pause2->Visible = true;
				timer1->Enabled = false; timer_v2->Enabled = false; timer_virus->Enabled = false;
				timer_doctor->Enabled = false;
				pause = true;
				break;

			case Keys::C:
				Pause->Visible = false;
				Pause2->Visible = false;
				timer1->Enabled = true; timer_v2->Enabled = true; timer_virus->Enabled = true;
				timer_doctor->Enabled = true;
				pause = false;
				timer1->Enabled = true; break;
			case Keys::Escape:
				if (controller->getvidas() == 0)
				{
					ofstream Escribir("DatosNivel.txt");
					if (Escribir.is_open())
					{
						if (NivelCompleto == false)
						{
							Escribir << 2 << endl;
						}
						Escribir << VacunasLvl1 << endl;
						Escribir << DocNivAnt << endl;
						Escribir << PuntosNivAnt << endl;
					}
					Close();
				}
				if (win)
				{
					Close();
				}
			default:
				personaje->mover(buffer->Graphics, 'N'); break;
				//case Keys::X:
				//	controller->addVacuna(bmpBullet->Width, bmpBullet->Height); break;	
			}
		}
		cont++;
	}
	private: System::Void timer_doctor_Tick(System::Object^ sender, System::EventArgs^ e) {
		//se dibuja el avion y todos los objetos
		controller->addVacuna(bmpBullet->Width, bmpBullet->Height, doc1);

		//esta funcion presenta error
	}
	private: System::Void timer_virus_Tick(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void pnlCanvas_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (timer1->Enabled)
		{
			personaje->saltar();
		}
	}
	private: System::Void Nivel3_Load(System::Object^ sender, System::EventArgs^ e) {
		//S1->PlayLooping();
		ifstream LecturaData("DatosNivel.txt");
		string NivelesC;
		string Vacuna;
		string Doctores;
		string cadena;
		string puntos;
		int cont = 1;
		int contD = 0;
		personaje->setLim(720);
		while (!LecturaData.eof())
		{
			LecturaData >> cadena;

			if (cont == 1)
			{
				NivelesC = cadena;

			}
			if (cont == 2)
			{
				Vacuna = cadena;
			}
			if (cont == 3)
			{
				Doctores = cadena;
			}
			if (cont == 4)
			{
				puntos = cadena;
			}
			cont++;
			PuntosNivAnt = atof(puntos.c_str());
			DocNivAnt = atof(Doctores.c_str());
			VacunasLvl1 = atof(Vacuna.c_str());
			controller->setpotDoc(DocNivAnt);
		}
		controller->SetVacunas(VacunasLvl1);
	}
	private: System::Void timer_v2_Tick(System::Object^ sender, System::EventArgs^ e) {
		/*controller->createTipo2(bmpTipo2->Width / 5, bmpTipo2->Height / 1);*/
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Nivel3_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		personaje->mover(buffer->Graphics, 'N');
		cont = 0;
	}

	private: System::Void pnlCanvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void MoveBoss_Tick(System::Object^ sender, System::EventArgs^ e) {
	b1->mover(buffer->Graphics);
}
private: System::Void createT2_Tick(System::Object^ sender, System::EventArgs^ e) {
	controller->createTipo2(bmpTipo2->Width / 5, bmpTipo2->Height / 1, rand() % 500 + 100, 2);
}

};
}
