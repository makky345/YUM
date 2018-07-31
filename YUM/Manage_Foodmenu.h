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
	/// Summary for Manage_Foodmenu
	/// </summary>
	public ref class Manage_Foodmenu : public System::Windows::Forms::Form
	{
	public:
		Manage_Foodmenu(void)
		{
			InitializeComponent();
			RefreshInfo();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Manage_Foodmenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  Price_textbox;
	private: System::Windows::Forms::TextBox^  Name_textbox;
	private: System::Windows::Forms::TextBox^  Description_textbox;
	private: System::Windows::Forms::BindingSource^  bindingSource1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  Go_button;
	private: System::Windows::Forms::Button^  Getall_button;
	private: System::Windows::Forms::Button^  Add_button;
	private: System::Windows::Forms::Button^  Update_button;
	private: System::Windows::Forms::Button^  Remove_button;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  ID_textbox;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Price_textbox = (gcnew System::Windows::Forms::TextBox());
			this->Name_textbox = (gcnew System::Windows::Forms::TextBox());
			this->Description_textbox = (gcnew System::Windows::Forms::TextBox());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Go_button = (gcnew System::Windows::Forms::Button());
			this->Getall_button = (gcnew System::Windows::Forms::Button());
			this->Add_button = (gcnew System::Windows::Forms::Button());
			this->Update_button = (gcnew System::Windows::Forms::Button());
			this->Remove_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ID_textbox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(81, 229);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(81, 297);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Price";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(81, 367);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(106, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Description";
			// 
			// Price_textbox
			// 
			this->Price_textbox->Location = System::Drawing::Point(217, 295);
			this->Price_textbox->Name = L"Price_textbox";
			this->Price_textbox->Size = System::Drawing::Size(83, 22);
			this->Price_textbox->TabIndex = 13;
			this->Price_textbox->Text = L"0.00";
			// 
			// Name_textbox
			// 
			this->Name_textbox->Location = System::Drawing::Point(217, 227);
			this->Name_textbox->Name = L"Name_textbox";
			this->Name_textbox->Size = System::Drawing::Size(200, 22);
			this->Name_textbox->TabIndex = 14;
			this->Name_textbox->Text = L"Name of the food .......";
			// 
			// Description_textbox
			// 
			this->Description_textbox->Location = System::Drawing::Point(217, 367);
			this->Description_textbox->Name = L"Description_textbox";
			this->Description_textbox->Size = System::Drawing::Size(200, 22);
			this->Description_textbox->TabIndex = 16;
			this->Description_textbox->Text = L"Details on the food .....";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(458, 116);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(657, 321);
			this->dataGridView1->TabIndex = 18;
			// 
			// Go_button
			// 
			this->Go_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Go_button->Location = System::Drawing::Point(486, 65);
			this->Go_button->Name = L"Go_button";
			this->Go_button->Size = System::Drawing::Size(83, 37);
			this->Go_button->TabIndex = 19;
			this->Go_button->Text = L"GO";
			this->Go_button->UseVisualStyleBackColor = true;
			this->Go_button->Click += gcnew System::EventHandler(this, &Manage_Foodmenu::Go_button_Click);
			// 
			// Getall_button
			// 
			this->Getall_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Getall_button->Location = System::Drawing::Point(575, 65);
			this->Getall_button->Name = L"Getall_button";
			this->Getall_button->Size = System::Drawing::Size(126, 37);
			this->Getall_button->TabIndex = 20;
			this->Getall_button->Text = L"Get All";
			this->Getall_button->UseVisualStyleBackColor = true;
			this->Getall_button->Click += gcnew System::EventHandler(this, &Manage_Foodmenu::Getall_button_Click);
			// 
			// Add_button
			// 
			this->Add_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Add_button->Location = System::Drawing::Point(85, 465);
			this->Add_button->Name = L"Add_button";
			this->Add_button->Size = System::Drawing::Size(126, 37);
			this->Add_button->TabIndex = 23;
			this->Add_button->Text = L"Add";
			this->Add_button->UseVisualStyleBackColor = true;
			this->Add_button->Click += gcnew System::EventHandler(this, &Manage_Foodmenu::button3_Click);
			// 
			// Update_button
			// 
			this->Update_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Update_button->Location = System::Drawing::Point(217, 465);
			this->Update_button->Name = L"Update_button";
			this->Update_button->Size = System::Drawing::Size(126, 37);
			this->Update_button->TabIndex = 24;
			this->Update_button->Text = L"Update";
			this->Update_button->UseVisualStyleBackColor = true;
			this->Update_button->Click += gcnew System::EventHandler(this, &Manage_Foodmenu::button2_Click);
			// 
			// Remove_button
			// 
			this->Remove_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Remove_button->Location = System::Drawing::Point(349, 465);
			this->Remove_button->Name = L"Remove_button";
			this->Remove_button->Size = System::Drawing::Size(126, 37);
			this->Remove_button->TabIndex = 25;
			this->Remove_button->Text = L"Remove";
			this->Remove_button->UseVisualStyleBackColor = true;
			this->Remove_button->Click += gcnew System::EventHandler(this, &Manage_Foodmenu::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(81, 157);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 20);
			this->label1->TabIndex = 26;
			this->label1->Text = L"ID";
			// 
			// ID_textbox
			// 
			this->ID_textbox->Location = System::Drawing::Point(217, 155);
			this->ID_textbox->Name = L"ID_textbox";
			this->ID_textbox->Size = System::Drawing::Size(200, 22);
			this->ID_textbox->TabIndex = 27;
			this->ID_textbox->Text = L"Id of the item";
			// 
			// Manage_Foodmenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1276, 611);
			this->Controls->Add(this->ID_textbox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Remove_button);
			this->Controls->Add(this->Update_button);
			this->Controls->Add(this->Add_button);
			this->Controls->Add(this->Getall_button);
			this->Controls->Add(this->Go_button);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->Description_textbox);
			this->Controls->Add(this->Name_textbox);
			this->Controls->Add(this->Price_textbox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Name = L"Manage_Foodmenu";
			this->Text = L"Manage_Foodmenu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void RefreshInfo() {
			String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
			MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
			MySqlDataAdapter^ ada = gcnew MySqlDataAdapter("SELECT * FROM `test-menu`.`test-menu-items` ", conDatabase);
			DataTable^ dt = gcnew DataTable();
			ada->Fill(dt);
			bindingSource1->DataSource = dt;
			dataGridView1->DataSource = bindingSource1;
		}
	private: System::Void Go_button_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
			MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
			int ID = Int32::Parse(ID_textbox->Text);
			MySqlCommand^ comd = gcnew MySqlCommand("SELECT * FROM `test-menu`.`test-menu-items` WHERE id = '" + ID_textbox->Text + "';", conDatabase);
			conDatabase->Open();
			MySqlDataReader^ Reader = comd->ExecuteReader();
			while (Reader->Read()) {
				Name_textbox->Text = Reader->GetString(1);
				Price_textbox->Text = Reader->GetString(2);
				Description_textbox->Text = Reader->GetString(3);
			}
			conDatabase->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
private: System::Void Getall_button_Click(System::Object^  sender, System::EventArgs^  e) {
	RefreshInfo();
	//String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
	//MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
	//MySqlDataAdapter^ ada = gcnew MySqlDataAdapter("SELECT * FROM `test-menu`.`test-menu-items` ", conDatabase);
	//DataTable^ dt = gcnew DataTable();
	//ada->Fill(dt);
	//bindingSource1->DataSource = dt;
	//dataGridView1->DataSource = bindingSource1;
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
	MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
	String^ name = Name_textbox->Text;
	Decimal^ price = Decimal::Parse(Price_textbox->Text);
	String^ desc = Description_textbox->Text;
	try {
		conDatabase->Open();
		MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO `test-menu`.`test-menu-items` (`Name`, `Price`, `Description`) VALUES('" + name+ "', '" + price + "', '" + desc + "');", conDatabase);
		MySqlDataReader^ reader;
		reader = cmd->ExecuteReader();
		MessageBox::Show("Info saved");
		RefreshInfo();
		conDatabase->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	try {
		String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
		MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
		int ID = Int32::Parse(ID_textbox->Text);
		String^ name = Name_textbox->Text;
		Decimal^ price = Decimal::Parse(Price_textbox->Text);
		String^ desc = Description_textbox->Text;

		MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE `test-menu`.`test-menu-items` SET `Name` = '" + name + "', `Price` = '" + price + "', `Description` = '" + desc + "' WHERE Id = '" + ID + "' ;", conDatabase);
		conDatabase->Open();
		if (cmd->ExecuteNonQuery()) {
			MessageBox::Show("info updated");
		}
		else {
			MessageBox::Show("Please check the information entered.");
		}
		RefreshInfo();
		conDatabase->Close();

	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	try {
		String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
		MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
		int ID = Int32::Parse(ID_textbox->Text);
		MySqlCommand^ cmd = gcnew MySqlCommand("DELETE from `test-menu`.`test-menu-items` WHERE `id` = '" + ID + "' ;", conDatabase);
		conDatabase->Open();
		if (cmd->ExecuteNonQuery()) {
			MessageBox::Show("Info Deleted");
		}
		else {
			MessageBox::Show("Please check the information entered.");
		}
		RefreshInfo();
		conDatabase->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}
};
}
