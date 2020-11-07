#include "Reader.h"

using namespace std;
void create_account(User& users, vector<Card>& all_cards);
int _String_into_int(string string);
extern vector<string> languages;
void Read::_Check_Exception()
{
	try
	{
		if (!file.is_open())
			throw "Cannot read the file";
	}
	catch (const char* exception)
	{
		cout << "Error:" << exception << endl<<"Closing the program\n";
		exit(0);
	}
}
void Read::_Read()
{
	Session session;
	vector<User> user;

	_Read_Account(user);
	_Read_Card(user);




	session._Start_Session();
}
void Read::_Read_Language(bool& Is_English)
{

	string buff;
	if (Is_English) {
		file.open("D:/Project_Microsoft_Visual_Soft/PPvIS_Laba_3/English.txt");
	}
	else {



		file.open("D:/Project_Microsoft_Visual_Soft/PPvIS_Laba_3/Russian.txt");

	}
	_Check_Exception();
	while (getline(file, buff))
	{

		languages.push_back(buff);


	}


	file.close();
}
void Read::_Read_Card(vector<User>& user)
{

	string buffer;
	file.open("D:/Project_Microsoft_Visual_Soft/PPvIS_Laba_3/Card.txt");
	_Check_Exception();

	for (int i = 0; i < user.size(); i++)
	{
		vector<Card> all_cards;
		for (int g = 0; g < user[i]._Get_Number(); g++)
		{
			Card temp;

			file >> buffer;
			temp._Set_Number(buffer);

			file >> buffer;
			temp._Set_PIN_CODE(buffer);

			file >> buffer;
			temp._Set_validty(buffer);
			file >> buffer;
			temp._Set_money(_String_into_int(buffer));
			all_cards.push_back(temp);

		}
		create_account(user[i], all_cards);
	}
	file.close();





}
void Read::_Read_Account(vector<User>& user)
{
	string buff;

	file.open("D:/Project_Microsoft_Visual_Soft/PPvIS_Laba_3/User.txt");
	_Check_Exception();
	while (!file.eof())
	{
		User temp;
		file >> buff;
		temp._Set_First_Name(buff);

		file >> buff;
		temp._Set_Last_Name(buff);

		file >> buff;
		temp._Set_years(buff);

		file >> buff;
		temp._Set_Number(_String_into_int(buff));

		user.push_back(temp);
	}





	file.close();
}