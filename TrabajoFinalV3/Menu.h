#pragma once
#include <fstream>
#include <Windows.h>
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
using namespace std;
namespace TrabajoFinalV3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Menu
	/// </summary>
	public ref class Menu : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Button^ BotonNivel2;
	public:


	private: System::Windows::Forms::Button^ BotonNivel1;
	private: System::Windows::Forms::Button^ BotonNivel3;
	public:


	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;






	public:
		SoundPlayer^ clik = gcnew SoundPlayer("Click.wav");



		Menu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//



		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BotonIns;
	private: System::Windows::Forms::Button^ BotonPlay;
	private: System::Windows::Forms::Button^ BotonCred;

	protected:

	protected:



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


		int ver = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->BotonIns = (gcnew System::Windows::Forms::Button());
			this->BotonPlay = (gcnew System::Windows::Forms::Button());
			this->BotonCred = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->BotonNivel2 = (gcnew System::Windows::Forms::Button());
			this->BotonNivel1 = (gcnew System::Windows::Forms::Button());
			this->BotonNivel3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// BotonIns
			// 
			this->BotonIns->BackColor = System::Drawing::Color::MediumPurple;
			this->BotonIns->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BotonIns->Font = (gcnew System::Drawing::Font(L"Impact", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonIns->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->BotonIns->Location = System::Drawing::Point(113, 385);
			this->BotonIns->Name = L"BotonIns";
			this->BotonIns->Size = System::Drawing::Size(433, 48);
			this->BotonIns->TabIndex = 1;
			this->BotonIns->Text = L"Instrucciones";
			this->BotonIns->UseVisualStyleBackColor = false;
			this->BotonIns->Click += gcnew System::EventHandler(this, &Menu::BotonIns_Click);
			this->BotonIns->MouseLeave += gcnew System::EventHandler(this, &Menu::BotonIns_MouseLeave);
			this->BotonIns->MouseHover += gcnew System::EventHandler(this, &Menu::BotonIns_MouseHover);
			// 
			// BotonPlay
			// 
			this->BotonPlay->BackColor = System::Drawing::Color::MediumPurple;
			this->BotonPlay->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BotonPlay->Font = (gcnew System::Drawing::Font(L"Impact", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonPlay->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->BotonPlay->Location = System::Drawing::Point(113, 333);
			this->BotonPlay->Name = L"BotonPlay";
			this->BotonPlay->Size = System::Drawing::Size(433, 46);
			this->BotonPlay->TabIndex = 2;
			this->BotonPlay->Text = L"JUGAR!";
			this->BotonPlay->UseVisualStyleBackColor = false;
			this->BotonPlay->Click += gcnew System::EventHandler(this, &Menu::BotonPlay_Click);
			this->BotonPlay->MouseLeave += gcnew System::EventHandler(this, &Menu::BotonPlay_MouseLeave);
			this->BotonPlay->MouseHover += gcnew System::EventHandler(this, &Menu::BotonPlay_MouseHover);
			// 
			// BotonCred
			// 
			this->BotonCred->BackColor = System::Drawing::Color::MediumPurple;
			this->BotonCred->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BotonCred->Font = (gcnew System::Drawing::Font(L"Impact", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonCred->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->BotonCred->Location = System::Drawing::Point(113, 439);
			this->BotonCred->Name = L"BotonCred";
			this->BotonCred->Size = System::Drawing::Size(433, 50);
			this->BotonCred->TabIndex = 3;
			this->BotonCred->Text = L"Creditos";
			this->BotonCred->UseVisualStyleBackColor = false;
			this->BotonCred->Click += gcnew System::EventHandler(this, &Menu::BotonCred_Click);
			this->BotonCred->MouseLeave += gcnew System::EventHandler(this, &Menu::BotonCred_MouseLeave);
			this->BotonCred->MouseHover += gcnew System::EventHandler(this, &Menu::BotonCred_MouseHover);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Impact", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Indigo;
			this->label1->Location = System::Drawing::Point(42, 176);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(584, 117);
			this->label1->TabIndex = 0;
			this->label1->Text = L"PandemiSave";
			this->label1->Click += gcnew System::EventHandler(this, &Menu::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(-2, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(713, 605);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Menu::pictureBox1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Impact", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DarkMagenta;
			this->label2->Location = System::Drawing::Point(0, -5);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(584, 117);
			this->label2->TabIndex = 5;
			this->label2->Text = L"PandemiSave";
			this->label2->Click += gcnew System::EventHandler(this, &Menu::label2_Click);
			// 
			// BotonNivel2
			// 
			this->BotonNivel2->BackColor = System::Drawing::Color::Gold;
			this->BotonNivel2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BotonNivel2->Enabled = false;
			this->BotonNivel2->Font = (gcnew System::Drawing::Font(L"Impact", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonNivel2->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->BotonNivel2->Location = System::Drawing::Point(263, 306);
			this->BotonNivel2->Name = L"BotonNivel2";
			this->BotonNivel2->Size = System::Drawing::Size(195, 100);
			this->BotonNivel2->TabIndex = 7;
			this->BotonNivel2->Text = L"Nivel 2";
			this->BotonNivel2->UseVisualStyleBackColor = false;
			this->BotonNivel2->Visible = false;
			this->BotonNivel2->Click += gcnew System::EventHandler(this, &Menu::BotonNivel2_Click);
			// 
			// BotonNivel1
			// 
			this->BotonNivel1->BackColor = System::Drawing::Color::Green;
			this->BotonNivel1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BotonNivel1->Enabled = false;
			this->BotonNivel1->Font = (gcnew System::Drawing::Font(L"Impact", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonNivel1->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->BotonNivel1->Location = System::Drawing::Point(62, 306);
			this->BotonNivel1->Name = L"BotonNivel1";
			this->BotonNivel1->Size = System::Drawing::Size(195, 100);
			this->BotonNivel1->TabIndex = 8;
			this->BotonNivel1->Text = L"Nivel 1";
			this->BotonNivel1->UseVisualStyleBackColor = false;
			this->BotonNivel1->Visible = false;
			this->BotonNivel1->Click += gcnew System::EventHandler(this, &Menu::BotonNivel1_Click);
			// 
			// BotonNivel3
			// 
			this->BotonNivel3->BackColor = System::Drawing::Color::Crimson;
			this->BotonNivel3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BotonNivel3->Enabled = false;
			this->BotonNivel3->Font = (gcnew System::Drawing::Font(L"Impact", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonNivel3->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->BotonNivel3->Location = System::Drawing::Point(464, 306);
			this->BotonNivel3->Name = L"BotonNivel3";
			this->BotonNivel3->Size = System::Drawing::Size(195, 100);
			this->BotonNivel3->TabIndex = 9;
			this->BotonNivel3->Text = L"Nivel 3";
			this->BotonNivel3->UseVisualStyleBackColor = false;
			this->BotonNivel3->Visible = false;
			this->BotonNivel3->Click += gcnew System::EventHandler(this, &Menu::BotonNivel3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::MediumPurple;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Enabled = false;
			this->button4->Font = (gcnew System::Drawing::Font(L"Impact", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->button4->Location = System::Drawing::Point(512, 542);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(184, 49);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Volver";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &Menu::button4_Click);
			this->button4->MouseLeave += gcnew System::EventHandler(this, &Menu::button4_MouseLeave);
			this->button4->MouseHover += gcnew System::EventHandler(this, &Menu::button4_MouseHover);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::RoyalBlue;
			this->label3->Font = (gcnew System::Drawing::Font(L"Impact", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label3->Location = System::Drawing::Point(55, 60);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 39);
			this->label3->TabIndex = 11;
			this->label3->Text = L".";
			this->label3->Visible = false;
			this->label3->Click += gcnew System::EventHandler(this, &Menu::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Crimson;
			this->label4->Font = (gcnew System::Drawing::Font(L"Impact", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label4->Location = System::Drawing::Point(55, 264);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 39);
			this->label4->TabIndex = 12;
			this->label4->Text = L".";
			this->label4->Visible = false;
			// 
			// Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(711, 603);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->BotonNivel3);
			this->Controls->Add(this->BotonNivel1);
			this->Controls->Add(this->BotonNivel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->BotonCred);
			this->Controls->Add(this->BotonPlay);
			this->Controls->Add(this->BotonIns);
			this->Controls->Add(this->pictureBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu";
			this->Load += gcnew System::EventHandler(this, &Menu::Menu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BotonPlay_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		BotonPlay->BackColor = Color::Firebrick;
		BotonPlay->ForeColor = Color::WhiteSmoke;




	}
	private: System::Void BotonPlay_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		BotonPlay->BackColor = Color::MediumPurple;
		BotonPlay->ForeColor = Color::WhiteSmoke;
	}
	private: System::Void Menu_Load(System::Object^ sender, System::EventArgs^ e) {
		System::Drawing::Image^ img = gcnew Bitmap("Primer Nivel.png");
		pictureBox1->Image = img;
		ofstream Escribir("DatosNivel.txt");
		if (Escribir.is_open())
		{
			Escribir << 0 << endl;
			Escribir << 0 << endl;
			Escribir << 0 << endl;
			Escribir << 0 << endl;
		}

		label1->Parent = pictureBox1;
		label1->BackColor = Color::Transparent;
		label2->Parent = label1;
		label2->BackColor = Color::Transparent;


		label3->Text = "                      INSTRUCCIONES: \n" +
			"El personaje se mueve con las teclas A y D\npara moverse a los lados \ny para saltar usa el click.\n\n" +
			"TEN CUIDADO CON LOS VIRUS!\n\nEl sistema de salud necesita tu ayuda\nSOBREVIVE Y MEJORA EL SISTEMA DE SALUD\n"
			+ "A medida que recolectes vacunas\nel staff medico incrementara\npara ayudarte en tu mission."
			;
		label4->Text = "                         Juego hecho por:\n\n" +
			"Nombre:                                                |Codigo:\n"
			"Sebastian Ramirez Hoffmann | U202211894\n" +
			"Mathias Alejandro Jave Diaz    | U202212721\n" +
			"Joaquin Eguia Castilla                 | U202213539\n" +
			"Rodrigo Alonso Alcantara Cruz | U202216698"

			;

	
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BotonIns_Click(System::Object^ sender, System::EventArgs^ e) {

		button4->Visible = true;
		button4->Enabled = true;
		label1->Visible = false;
		label2->Visible = false;

		BotonCred->Visible = false;
		BotonCred->Enabled = false;
		BotonIns->Visible = false;
		BotonIns->Enabled = false;
		BotonPlay->Visible = false;
		BotonPlay->Enabled = false;


		label3->Visible = true;


	}
	private: System::Void BotonIns_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		BotonIns->BackColor = Color::Firebrick;
		BotonIns->ForeColor = Color::WhiteSmoke;
	}
	private: System::Void BotonIns_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		BotonIns->BackColor = Color::MediumPurple;
		BotonIns->ForeColor = Color::WhiteSmoke;
	}
	private: System::Void BotonCred_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		BotonCred->BackColor = Color::Firebrick;
		BotonCred->ForeColor = Color::WhiteSmoke;
	}
	private: System::Void BotonCred_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		BotonCred->BackColor = Color::MediumPurple;
		BotonCred->ForeColor = Color::WhiteSmoke;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {



	}
	private: System::Void BotonPlay_Click(System::Object^ sender, System::EventArgs^ e) {

		ifstream LecturaData("DatosNivel.txt");
		string NivelesC;
		string Vacuna;
		string Doctores;
		string cadena;
		string puntos;
		int cont = 1;

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

		}



		ver = atof(NivelesC.c_str());



		button4->Visible = true;
		button4->Enabled = true;


		BotonCred->Visible = false;
		BotonCred->Enabled = false;
		BotonIns->Visible = false;
		BotonIns->Enabled = false;
		BotonPlay->Visible = false;
		BotonPlay->Enabled = false;

		BotonNivel1->Visible = true;
		BotonNivel1->Enabled = true;
		BotonNivel2->Visible = true;


		BotonNivel3->Visible = true;

		BotonNivel2->Enabled = false;
		BotonNivel3->Enabled = false;
		BotonNivel2->BackColor = Color::LightGray;
		BotonNivel3->BackColor = Color::LightGray;



		if (ver == 1)
		{
			BotonNivel2->Enabled = true;
			BotonNivel2->BackColor = Color::Gold;


		}
		if (ver == 2)
		{
			BotonNivel3->Enabled = true;
			BotonNivel3->BackColor = Color::Crimson;
			BotonNivel2->Enabled = true;
			BotonNivel2->BackColor = Color::Gold;
		}


	}
	private: System::Void BotonNivel1_Click(System::Object^ sender, System::EventArgs^ e) {

		Nivel1^ N1 = gcnew Nivel1();
		this->Visible = false;
		N1->ShowDialog();
		BotonCred->Visible = true;
		BotonCred->Enabled = true;
		BotonIns->Visible = true;
		BotonIns->Enabled = true;
		BotonPlay->Visible = true;
		BotonPlay->Enabled = true;

		BotonNivel1->Visible = false;
		BotonNivel1->Enabled = false;
		BotonNivel2->Visible = false;
		BotonNivel2->Enabled = false;
		BotonNivel3->Visible = false;
		BotonNivel3->Enabled = false;

		button4->Visible = false;
		button4->Enabled = false;

		label3->Visible = false;
		label2->Visible = true;
		label1->Visible = true;
		label4->Visible = false;

		this->Visible = true;

	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {


		BotonCred->Visible = true;
		BotonCred->Enabled = true;
		BotonIns->Visible = true;
		BotonIns->Enabled = true;
		BotonPlay->Visible = true;
		BotonPlay->Enabled = true;

		BotonNivel1->Visible = false;
		BotonNivel1->Enabled = false;
		BotonNivel2->Visible = false;
		BotonNivel2->Enabled = false;
		BotonNivel3->Visible = false;
		BotonNivel3->Enabled = false;

		button4->Visible = false;
		button4->Enabled = false;

		label3->Visible = false;
		label2->Visible = true;
		label1->Visible = true;
		label4->Visible = false;



	}
	private: System::Void button4_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		button4->BackColor = Color::Firebrick;
		button4->ForeColor = Color::WhiteSmoke;
	}
	private: System::Void button4_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		button4->BackColor = Color::MediumPurple;
		button4->ForeColor = Color::WhiteSmoke;
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BotonCred_Click(System::Object^ sender, System::EventArgs^ e) {

		button4->Visible = true;
		button4->Enabled = true;
		label1->Visible = false;
		label2->Visible = false;

		BotonCred->Visible = false;
		BotonCred->Enabled = false;
		BotonIns->Visible = false;
		BotonIns->Enabled = false;
		BotonPlay->Visible = false;
		BotonPlay->Enabled = false;


		label4->Visible = true;

	}
	private: System::Void BotonNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		Nivel2^ N2 = gcnew Nivel2();
		this->Visible = false;
		N2->ShowDialog();
		BotonCred->Visible = true;
		BotonCred->Enabled = true;
		BotonIns->Visible = true;
		BotonIns->Enabled = true;
		BotonPlay->Visible = true;
		BotonPlay->Enabled = true;

		BotonNivel1->Visible = false;
		BotonNivel1->Enabled = false;
		BotonNivel2->Visible = false;
		BotonNivel2->Enabled = false;
		BotonNivel3->Visible = false;
		BotonNivel3->Enabled = false;

		button4->Visible = false;
		button4->Enabled = false;

		label3->Visible = false;
		label2->Visible = true;
		label1->Visible = true;
		label4->Visible = false;

		this->Visible = true;
	}
	private: System::Void BotonNivel3_Click(System::Object^ sender, System::EventArgs^ e) {
		Nivel3^ N3 = gcnew Nivel3();
		this->Visible = false;
		N3->ShowDialog();
		BotonCred->Visible = true;
		BotonCred->Enabled = true;
		BotonIns->Visible = true;
		BotonIns->Enabled = true;
		BotonPlay->Visible = true;
		BotonPlay->Enabled = true;

		BotonNivel1->Visible = false;
		BotonNivel1->Enabled = false;
		BotonNivel2->Visible = false;
		BotonNivel2->Enabled = false;
		BotonNivel3->Visible = false;
		BotonNivel3->Enabled = false;

		button4->Visible = false;
		button4->Enabled = false;

		label3->Visible = false;
		label2->Visible = true;
		label1->Visible = true;
		label4->Visible = false;

		this->Visible = true;
	}
};
}
