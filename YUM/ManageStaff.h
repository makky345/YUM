#pragma once

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
	using MySql::Data::MySqlClient::MySqlDataAdapter;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class ManageStaff : public System::Windows::Forms::Form
	{
	public:
		ManageStaff(void)
		{
			InitializeComponent();
			RefreshInfo();
			//
			//TODO: Add the constructor code here
			//
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ManageStaff()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Button^  Getall_button;

	private: System::Windows::Forms::Button^  Go_button;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::TextBox^  ID_textbox;
	private: System::Windows::Forms::TextBox^  Uname_textbox;
	private: System::Windows::Forms::TextBox^  Password_textbox;









	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::BindingSource^  bindingSource1;
	private: System::Windows::Forms::TextBox^  Fname_textbox;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  Role_combobox;
	private: System::Windows::Forms::TextBox^  Lname_textbox;


	private: System::Windows::Forms::Label^  label6;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Getall_button = (gcnew System::Windows::Forms::Button());
			this->Go_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->ID_textbox = (gcnew System::Windows::Forms::TextBox());
			this->Uname_textbox = (gcnew System::Windows::Forms::TextBox());
			this->Password_textbox = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->Fname_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Role_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->Lname_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(89, 526);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(126, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ManageStaff::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(231, 526);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 37);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Update";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ManageStaff::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(373, 526);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(126, 37);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Remove";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ManageStaff::button3_Click);
			// 
			// Getall_button
			// 
			this->Getall_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Getall_button->Location = System::Drawing::Point(669, 119);
			this->Getall_button->Name = L"Getall_button";
			this->Getall_button->Size = System::Drawing::Size(126, 37);
			this->Getall_button->TabIndex = 5;
			this->Getall_button->Text = L"Get All";
			this->Getall_button->UseVisualStyleBackColor = true;
			this->Getall_button->Click += gcnew System::EventHandler(this, &ManageStaff::Getall_button_Click);
			// 
			// Go_button
			// 
			this->Go_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Go_button->Location = System::Drawing::Point(551, 119);
			this->Go_button->Name = L"Go_button";
			this->Go_button->Size = System::Drawing::Size(83, 37);
			this->Go_button->TabIndex = 6;
			this->Go_button->Text = L"GO";
			this->Go_button->UseVisualStyleBackColor = true;
			this->Go_button->Click += gcnew System::EventHandler(this, &ManageStaff::Go_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(99, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 20);
			this->label1->TabIndex = 7;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(99, 354);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Firstname";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(99, 279);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Role";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(99, 127);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Username";
			// 
			// ID_textbox
			// 
			this->ID_textbox->Location = System::Drawing::Point(226, 53);
			this->ID_textbox->Name = L"ID_textbox";
			this->ID_textbox->Size = System::Drawing::Size(200, 22);
			this->ID_textbox->TabIndex = 12;
			// 
			// Uname_textbox
			// 
			this->Uname_textbox->Location = System::Drawing::Point(226, 127);
			this->Uname_textbox->Name = L"Uname_textbox";
			this->Uname_textbox->Size = System::Drawing::Size(200, 22);
			this->Uname_textbox->TabIndex = 13;
			// 
			// Password_textbox
			// 
			this->Password_textbox->Location = System::Drawing::Point(226, 200);
			this->Password_textbox->Name = L"Password_textbox";
			this->Password_textbox->PasswordChar = '*';
			this->Password_textbox->Size = System::Drawing::Size(200, 22);
			this->Password_textbox->TabIndex = 14;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(530, 173);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(657, 321);
			this->dataGridView1->TabIndex = 17;
			// 
			// Fname_textbox
			// 
			this->Fname_textbox->Location = System::Drawing::Point(226, 354);
			this->Fname_textbox->Name = L"Fname_textbox";
			this->Fname_textbox->Size = System::Drawing::Size(200, 22);
			this->Fname_textbox->TabIndex = 18;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(99, 200);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 20);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Password";
			// 
			// Role_combobox
			// 
			this->Role_combobox->FormattingEnabled = true;
			this->Role_combobox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"0", L"1" });
			this->Role_combobox->Location = System::Drawing::Point(226, 279);
			this->Role_combobox->Name = L"Role_combobox";
			this->Role_combobox->Size = System::Drawing::Size(66, 24);
			this->Role_combobox->TabIndex = 20;
			// 
			// Lname_textbox
			// 
			this->Lname_textbox->Location = System::Drawing::Point(226, 431);
			this->Lname_textbox->Name = L"Lname_textbox";
			this->Lname_textbox->Size = System::Drawing::Size(200, 22);
			this->Lname_textbox->TabIndex = 21;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(99, 431);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 20);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Lastname";
			// 
			// ManageStaff
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1296, 594);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->Lname_textbox);
			this->Controls->Add(this->Role_combobox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Fname_textbox);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->Password_textbox);
			this->Controls->Add(this->Uname_textbox);
			this->Controls->Add(this->ID_textbox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Go_button);
			this->Controls->Add(this->Getall_button);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"ManageStaff";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &ManageStaff::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void RefreshInfo() {
			String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
			MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
			MySqlDataAdapter^ ada = gcnew MySqlDataAdapter("SELECT * FROM `test-menu`.`test-menu-table` ", conDatabase);
			DataTable^ dt = gcnew DataTable();
			ada->Fill(dt);
			bindingSource1->DataSource = dt;
			dataGridView1->DataSource = bindingSource1;
		}



	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
	MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
	int ID = Int32::Parse(ID_textbox->Text);
	String^ Fname = Fname_textbox->Text;
	String^ Lname = Lname_textbox->Text;
	String^ Uname = Uname_textbox->Text;
	String^ Password = Password_textbox->Text;
	int Role = Role_combobox->SelectedIndex;
	try {
		conDatabase->Open();
		MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO `test-menu`.`test-menu-users` (`id`, `username`, `password`, `role`, `Firstname`, `Lastname`) VALUES('"+ID+"', '" + Uname + "', '" + Password + "', '" + Role + "', '" + Fname + "', '" + Lname + "');", conDatabase);
		MySqlDataReader^ reader;
		reader = cmd->ExecuteReader();
		MessageBox::Show("User info saved");
	}
	catch(Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}
}
private: System::Void Go_button_Click(System::Object^  sender, System::EventArgs^  e) {
	try {
		int ID = Int32::Parse(ID_textbox->Text);
		String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
		MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
		MySqlCommand^ comd = gcnew MySqlCommand("SELECT * FROM `test-menu`.`test-menu-users` WHERE id = " + ID + ";", conDatabase);
		conDatabase->Open();
		MySqlDataReader^ Reader = comd->ExecuteReader();
		while (Reader->Read()) {
			Uname_textbox->Text = Reader->GetString(1);
			Password_textbox->Text = Reader->GetString(2);
			Role_combobox->Text = Reader->GetString(3);
			Fname_textbox->Text = Reader->GetString(4);
			Lname_textbox->Text = Reader->GetString(5);
			//Uname_textbox->Text = Reader->GetString(6);
		}
		conDatabase->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}
private: System::Void Getall_button_Click(System::Object^  sender, System::EventArgs^  e) {
	String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
	MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
	MySqlDataAdapter^ ada = gcnew MySqlDataAdapter("SELECT * FROM `test-menu`.`test-menu-users` ", conDatabase);
	DataTable^ dt = gcnew DataTable();
	ada->Fill(dt);
	bindingSource1->DataSource = dt;
	dataGridView1->DataSource=bindingSource1;

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	try {

		String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
		MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
		int ID = Int32::Parse(ID_textbox->Text);
		String^ Fname = Fname_textbox->Text;
		String^ Lname = Lname_textbox->Text;
		String^ Uname = Uname_textbox->Text;
		String^ Password = Password_textbox->Text;
		int Role = Role_combobox->SelectedIndex;

		MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE `test-menu`.`test-menu-users` SET `id` = '" + ID + "', `username` = '" + Uname + "', `password` = '" + Password + "', `Role` = '" + Role + "', `Firstname` = '" + Fname + "', `Lastname` = '" + Lname + "' WHERE id = '"+ID+"' ;", conDatabase);
		conDatabase->Open();
		MySqlDataReader^ reader = cmd->ExecuteReader();
		MessageBox::Show("User info updated");
		conDatabase->Close();

	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
	MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
	int ID = Int32::Parse(ID_textbox->Text);
	MySqlCommand^ cmd = gcnew MySqlCommand("DELETE from `test-menu`.`test-menu-users` WHERE `id` = '" + ID + "' ;", conDatabase);
	conDatabase->Open();
	MySqlDataReader^ reader = cmd->ExecuteReader();
	MessageBox::Show("User Info Deleted");
	conDatabase->Close();
}
};
}
