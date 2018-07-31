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
	/// Summary for ManageTables
	/// </summary>
	public ref class Manage_Tables : public System::Windows::Forms::Form
	{
	public:
		Manage_Tables(void)
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
		~Manage_Tables()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  ID_textbox;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  Remove_button;
	private: System::Windows::Forms::Button^  Add_button;


	private: System::Windows::Forms::DataGridView^  dataGridView1;



	private: System::Windows::Forms::BindingSource^  bindingSource1;
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
			this->ID_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Remove_button = (gcnew System::Windows::Forms::Button());
			this->Add_button = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			this->SuspendLayout();
			// 
			// ID_textbox
			// 
			this->ID_textbox->Location = System::Drawing::Point(253, 176);
			this->ID_textbox->Name = L"ID_textbox";
			this->ID_textbox->Size = System::Drawing::Size(200, 22);
			this->ID_textbox->TabIndex = 41;
			this->ID_textbox->Text = L"Id of the table";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(117, 178);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 20);
			this->label1->TabIndex = 40;
			this->label1->Text = L"ID";
			// 
			// Remove_button
			// 
			this->Remove_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Remove_button->Location = System::Drawing::Point(253, 486);
			this->Remove_button->Name = L"Remove_button";
			this->Remove_button->Size = System::Drawing::Size(126, 37);
			this->Remove_button->TabIndex = 39;
			this->Remove_button->Text = L"Remove";
			this->Remove_button->UseVisualStyleBackColor = true;
			this->Remove_button->Click += gcnew System::EventHandler(this, &Manage_Tables::Remove_button_Click);
			// 
			// Add_button
			// 
			this->Add_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Add_button->Location = System::Drawing::Point(121, 486);
			this->Add_button->Name = L"Add_button";
			this->Add_button->Size = System::Drawing::Size(126, 37);
			this->Add_button->TabIndex = 37;
			this->Add_button->Text = L"Add";
			this->Add_button->UseVisualStyleBackColor = true;
			this->Add_button->Click += gcnew System::EventHandler(this, &Manage_Tables::Add_button_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(494, 137);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(657, 321);
			this->dataGridView1->TabIndex = 34;
			// 
			// Manage_Tables
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1269, 609);
			this->Controls->Add(this->ID_textbox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Remove_button);
			this->Controls->Add(this->Add_button);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Manage_Tables";
			this->Text = L"ManageTables";
			this->Load += gcnew System::EventHandler(this, &Manage_Tables::ManageTables_Load);
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

	private: System::Void ManageTables_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void Add_button_Click(System::Object^  sender, System::EventArgs^  e) {
	String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
	MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);

	try {
		conDatabase->Open();
		MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO `test-menu`.`test-menu-table` VALUES() ;", conDatabase);
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
private: System::Void Remove_button_Click(System::Object^  sender, System::EventArgs^  e) {
	try {
		String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
		MySqlConnection ^ conDatabase = gcnew MySqlConnection(connectionString);
		int ID = Int32::Parse(ID_textbox->Text);
		MySqlCommand^ cmd = gcnew MySqlCommand("DELETE from `test-menu`.`test-menu-table` WHERE `id` = '" + ID + "' ;", conDatabase);
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
