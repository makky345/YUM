#pragma once

#include "Windows.h"
#include "LoginWindow.h"

namespace YUM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Welcome : public System::Windows::Forms::Form
	{
	public:
		Welcome(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Welcome()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::ComboBox^  managementOrService_comboBox;
	private: System::Windows::Forms::PictureBox^  pictureBox1;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Welcome::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->managementOrService_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(441, 381);
			this->label1->Name = L"label1";
			this->label1->Padding = System::Windows::Forms::Padding(12, 0, 12, 0);
			this->label1->Size = System::Drawing::Size(200, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Please select user type:";
			this->label1->Click += gcnew System::EventHandler(this, &Welcome::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(930, 475);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Continue";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Welcome::login_button_click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::IndianRed;
			this->textBox1->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textBox1->Location = System::Drawing::Point(241, 316);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(611, 51);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Welcome asshole, hope you finished jacking off already\n. Please follow the instru"
				L"ctions below to log in";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Welcome::textBox1_TextChanged);
			// 
			// managementOrService_comboBox
			// 
			this->managementOrService_comboBox->AllowDrop = true;
			this->managementOrService_comboBox->DisplayMember = L"Please select...";
			this->managementOrService_comboBox->FormattingEnabled = true;
			this->managementOrService_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Managing Staff", L"Service Staff" });
			this->managementOrService_comboBox->Location = System::Drawing::Point(470, 428);
			this->managementOrService_comboBox->Name = L"managementOrService_comboBox";
			this->managementOrService_comboBox->Size = System::Drawing::Size(144, 28);
			this->managementOrService_comboBox->TabIndex = 6;
			this->managementOrService_comboBox->Text = L"Please Select...";
			this->managementOrService_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Welcome::comboBox1_SelectedIndexChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(241, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(611, 264);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Welcome::pictureBox1_Click);
			// 
			// Welcome
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCoral;
			this->ClientSize = System::Drawing::Size(1100, 533);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->managementOrService_comboBox);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Cambria", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Welcome";
			this->Text = L"Welcome";
			this->Load += gcnew System::EventHandler(this, &Welcome::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void login_button_click(System::Object^  sender, System::EventArgs^  e) {
		/*
		 * managementOrService_comboBox->SelectedIndex:
		 * -1 for NA; 0 for the first selection (manager); 1 for the second selection (service); so on & so forth
		*/
		MessageBox::Show(System::Convert::ToString(managementOrService_comboBox->SelectedIndex));
		if (managementOrService_comboBox->SelectedIndex == -1) {
			MessageBox::Show("Please select something");
			return;
		}
		this->Hide();
		LoginWindow ^ f1 = gcnew LoginWindow(managementOrService_comboBox->SelectedIndex, this);
		f1->ShowDialog();
		//MyForm1^ f1 = gcnew MyForm1();
		//f1->ShowDialog();
	}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
