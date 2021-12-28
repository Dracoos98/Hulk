#pragma once
#include "Controladora.h";

namespace Hulk {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			objcontroladora = new Controladora();
			bmphulkc = gcnew Bitmap("Hulk.png");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete objcontroladora, bmphulkc;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Controladora* objcontroladora;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


		   Bitmap^ bmphulkc;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(186, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Zona Peligrosa";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(342, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 21);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Zona segura";
			this->label2->Visible = false;
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(666, 472);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);
		bf->Graphics->Clear(Color::White);
		objcontroladora->Dibujar_Hulkc(bf->Graphics, bmphulkc);
		bf->Render(g);
		delete bf, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left) objcontroladora->Desplazar_Hulkc(direccion::izquierda);
		if (e->KeyCode == Keys::Right)objcontroladora->Desplazar_Hulkc(direccion::derecha);
		if (e->KeyCode == Keys::Up) objcontroladora->Desplazar_Hulkc(direccion::arriba);
		if (e->KeyCode == Keys::Down)objcontroladora->Desplazar_Hulkc(direccion::abajo);

	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (objcontroladora->Colision() == true) label2->Visible = false; label1->Visible = true;
}
private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (objcontroladora->Colision() == true) label1->Visible = false; label2->Visible = true;
}
};
}
