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
	/// Summary for Manage_a_Table
	/// </summary>
	public ref class Manage_a_Table : public System::Windows::Forms::Form
	{
	public:
		Manage_a_Table(void)
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
		~Manage_a_Table()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::BindingSource^  bindingSource1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TextBox^  ID_textbox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Total_textbox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ComboBox^  Status_combobox;
	protected:
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
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Total_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Status_combobox = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(602, 19);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(621, 487);
			this->dataGridView1->TabIndex = 0;
			// 
			// ID_textbox
			// 
			this->ID_textbox->Location = System::Drawing::Point(139, 68);
			this->ID_textbox->Name = L"ID_textbox";
			this->ID_textbox->Size = System::Drawing::Size(200, 22);
			this->ID_textbox->TabIndex = 43;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(42, 169);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 20);
			this->label1->TabIndex = 42;
			this->label1->Text = L"Status";
			// 
			// Total_textbox
			// 
			this->Total_textbox->Location = System::Drawing::Point(139, 284);
			this->Total_textbox->Name = L"Total_textbox";
			this->Total_textbox->Size = System::Drawing::Size(200, 22);
			this->Total_textbox->TabIndex = 45;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(42, 286);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 44;
			this->label2->Text = L"Total";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(42, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 20);
			this->label3->TabIndex = 46;
			this->label3->Text = L"ID";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(46, 416);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 36);
			this->button1->TabIndex = 48;
			this->button1->Text = L"Select";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Manage_a_Table::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(308, 416);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 36);
			this->button2->TabIndex = 49;
			this->button2->Text = L"Pay";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(177, 416);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(125, 36);
			this->button3->TabIndex = 50;
			this->button3->Text = L"Update";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Manage_a_Table::button3_Click);
			// 
			// Status_combobox
			// 
			this->Status_combobox->FormattingEnabled = true;
			this->Status_combobox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Booked", L"Un-booked" });
			this->Status_combobox->Location = System::Drawing::Point(139, 163);
			this->Status_combobox->Name = L"Status_combobox";
			this->Status_combobox->Size = System::Drawing::Size(128, 24);
			this->Status_combobox->TabIndex = 51;
			// 
			// Manage_a_Table
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1239, 551);
			this->Controls->Add(this->Status_combobox);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Total_textbox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->ID_textbox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Manage_a_Table";
			this->Text = L"Manage_a_Table";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
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

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		try {
			int ID = Int32::Parse(ID_textbox->Text);
			String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
			MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
			MySqlCommand^ comd = gcnew MySqlCommand("SELECT * FROM `test-menu`.`test-menu-table` WHERE id = " + ID + ";", conDatabase);
			conDatabase->Open();
			MySqlDataReader^ Reader = comd->ExecuteReader();
			 //= Convert::ToDouble(Total_textbox->Text);
			while (Reader->Read()) {
				Status_combobox->Text = Reader->GetString(1);
				Double total = Convert::ToDouble(Reader->GetString(2));
				Total_textbox->Text = Convert::ToString(total);
			}
			conDatabase->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}

	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

		try {

			String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
			MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);



			int Status = Status_combobox->SelectedIndex;

			MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE `test-menu`.`test-menu-table` SET `status` = '" + Status + "' ;", conDatabase);
			conDatabase->Open();
			MySqlDataReader^ reader = cmd->ExecuteReader();
			MessageBox::Show("User info updated");
			conDatabase->Close();

		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}

	}
	}
	; }

