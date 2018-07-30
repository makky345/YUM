#pragma once
#include "Manager_menu.h"
namespace YUM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using MySql::Data::MySqlClient::MySqlConnection;
	using MySql::Data::MySqlClient::MySqlException;
	using MySql::Data::MySqlClient::MySqlCommand;
	using MySql::Data::MySqlClient::MySqlDataReader;


	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class LoginWindow : public System::Windows::Forms::Form
	{
	public:
		LoginWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		LoginWindow(const bool & managerOrService/*if FALSE, log in as manager; else as service*/)
		{
			InitializeComponent();
			this->managerOrService = managerOrService;
		}
		LoginWindow(const bool & managerOrService, System::Windows::Forms::Form ^ parent) {
			InitializeComponent();
			this->managerOrService = managerOrService;
			this->parentWindow = parent;
		}
	private:
		bool managerOrService;
		System::Windows::Forms::Form ^ parentWindow;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(286, 121);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(286, 259);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password";
			this->label2->Click += gcnew System::EventHandler(this, &LoginWindow::label2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(444, 415);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(172, 47);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LoginWindow::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(496, 121);
			this->textBox1->MaxLength = 45;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(320, 22);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(496, 259);
			this->textBox2->MaxLength = 45;
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(320, 22);
			this->textBox2->TabIndex = 4;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1171, 540);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"MyForm1";
			this->Text = L"Login";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LoginWindow::showParentWindow);
			this->Load += gcnew System::EventHandler(this, &LoginWindow::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
		MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
		MySqlDataReader ^ myReader;

		try {
			conDatabase->Open();
			int count = 0;
			String ^ role = gcnew String(this->managerOrService ? "1" : "0");
			MySqlCommand^ cmdDatabase = gcnew MySqlCommand("SELECT * FROM `test-menu`.`test-menu-users` where id = '" + this->textBox1->Text + "' and role = '" + role + "'  and password = '" + this->textBox2->Text + "' ;", conDatabase);
			myReader = cmdDatabase->ExecuteReader();
			while (myReader->Read()) {
				count = count + 1;
			}
			if (count == 1) {
				MessageBox::Show("Login Successful");
				this->Hide();
				if (role == "1") {
					MessageBox::Show("This is a service staff");
					this->Close();
				}
				else {
					Manager_Menu ^ f1 = gcnew Manager_Menu();
					f1->ShowDialog();
				}
			}
			else if (count != 1) {
				//MessageBox::Show("Login is duplicated....Access denied");
				throw gcnew Exception("Sorry ure stupid. this is bad they have hacked me!!!!!!");
			}

		}
		catch (Exception^ex) {
			MessageBox::Show(ex->Message);
		}


	}
	private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void showParentWindow(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		if (this->parentWindow) this->parentWindow->Show();
	}
	};
}
