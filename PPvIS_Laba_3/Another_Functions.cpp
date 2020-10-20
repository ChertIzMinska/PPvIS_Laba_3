#include"Header.h"
using namespace std;
extern vector<string> languages;
extern vector<Card_Account> base;
void Card_Account::_Set_User(User& owner)
{
	this->Owner = owner;
}
void Card_Account::_Set_cards(vector<Card>& cards)
{
	this->cards = cards;
}
Card_Account::Card_Account(User& owner, vector<Card>& cards)
{
	_Set_User(owner);
	_Set_cards(cards);
}
User Card_Account::_Get_User()
{
	return Owner;
}
vector<Card>Card_Account::_Get_Cards()
{
	return cards;
}
void User::_Set_First_Name(string& First_Name)
{
	this->First_Name = First_Name;
}
void User::_Set_Last_Name(string& Last_Name)
{
	this->Last_Name = Last_Name;
}
void User::_Set_years(string& years)
{
	this->years = years;
}
void Card::_Set_Number(string& Number)
{
	this->Number = Number;
}
void Card::_Set_PIN_CODE(string& PIN_CODE)
{
	this->PIN_CODE = PIN_CODE;
}
void Card::_Set_validty(string& validty)
{
	this->validity = validity;
}
string Card::_Get_PIN_CODE()
{
	return PIN_CODE;
}
void Card_Account::_Change_Sum_Money(int number,int sum)
{
	cards[0]._Set_money(cards[0]._Get_Money() - sum);
}
void Read::_Read()
{
	Session session;
	vector<Card>all_cards;
	User user;


	_Read_Card(all_cards);
	_Read_Account(user);

	Card_Account Is(user, all_cards);

	session._Start_Session(Is);
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
	while (getline(file, buff))
	{
		
		languages.push_back(buff);
		
		
	}
		

	file.close();
}
void Read::_Read_Card(vector<Card>& all_cards)
{

	string buffer;

	file.open("D:/Project_Microsoft_Visual_Soft/PPvIS_Laba_3/Card.txt");

	while (!file.eof())
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

	file.close();



}
void Read::_Read_Account(User& user)
{
	string buff;

	file.open("D:/Project_Microsoft_Visual_Soft/PPvIS_Laba_3/User.txt");

	while (!file.eof())
	{
		file >> buff;
		user._Set_First_Name(buff);

		file >> buff;
		user._Set_Last_Name(buff);

		file >> buff;
		user._Set_years(buff);
		
		file >> buff;
		_Read_Card();

	}
}
int _String_into_int(string string)
{
	int res = 0;
	for (int i = 0; i <string.size(); i++)
	{
		res += (int(string[i]) - 48) * pow(10, string.size()-i-1);
	}
	return res;
}
