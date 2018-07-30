#pragma once
#include "Windows.h"
#include "ManageStaff.h"

namespace YUM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class Manager_Menu : public System::Windows::Forms::Form
	{
	public:
		Manager_Menu(void)
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
		~Manager_Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  Operation_Combobox;



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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Operation_Combobox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(466, 425);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(172, 46);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Go";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Manager_Menu::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(229, 304);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Select Operation";
			// 
			// Operation_Combobox
			// 
			this->Operation_Combobox->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) {
				L"Manage Employees",
					L"Check Sales"
			});
			this->Operation_Combobox->DisplayMember = L"Please Select...";
			this->Operation_Combobox->FormattingEnabled = true;
			this->Operation_Combobox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Manage Accounts", L"Check Sales", L"Manage FoodItems",
					L"Manage Tables"
			});
			this->Operation_Combobox->Location = System::Drawing::Point(466, 304);
			this->Operation_Combobox->Name = L"Operation_Combobox";
			this->Operation_Combobox->Size = System::Drawing::Size(172, 24);
			this->Operation_Combobox->TabIndex = 2;
			this->Operation_Combobox->Text = L"Please Select...";
			// 
			// Manager_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1170, 586);
			this->Controls->Add(this->Operation_Combobox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Manager_Menu";
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &Manager_Menu::Manager_Menu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show(System::Convert::ToString(Operation_Combobox->SelectedIndex));
		if (Operation_Combobox->SelectedIndex == -1) {
			MessageBox::Show("Please select something");
			return;
		}
		this->Hide();
		ManageStaff ^ f1 = gcnew ManageStaff();
		f1->ShowDialog();
		//MyForm1^ f1 = gcnew MyForm1();
		//f1->ShowDialog();
	};
	private: System::Void Manager_Menu_Load(System::Object^  sender, System::EventArgs^  e) {
	}
};
	
}
