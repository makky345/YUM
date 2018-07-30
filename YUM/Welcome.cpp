#include "Welcome.h"
using namespace System;
using namespace System::Windows::Forms;
using MySql::Data::MySqlClient::MySqlConnection;
using MySql::Data::MySqlClient::MySqlException;
using MySql::Data::MySqlClient::MySqlCommand;
using MySql::Data::MySqlClient::MySqlDataReader;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	System::Diagnostics::Debug::WriteLine("\n\n\\n\n\n\n");
	String ^ connectionString("server=localhost;port=3306;database=test-menu;uid=root;pwd=dopeswag123;");
	MySqlConnection ^ conn = gcnew MySqlConnection(connectionString);
	try
	{
		conn->Open();
		MySqlCommand ^ command = gcnew MySqlCommand();
		command->CommandText = "SELECT * FROM `test-menu-items`";
		command->Connection = conn;
		MySqlDataReader ^ reader = command->ExecuteReader();
		while (reader->Read())
		{
			for (int i = 0; i < reader->FieldCount; i++)
				System::Diagnostics::Debug::WriteLine(reader[i]);
		}
	}
	catch (MySqlException ^ ex)
	{
		System::Diagnostics::Debug::WriteLine("\n\n\n\n\n\nERROR");
		System::Diagnostics::Debug::WriteLine(ex->Message);
	}
	//////
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	YUM::Welcome form;
	Application::Run(%form);
}