#pragma once
#include<string>
using namespace std;
class User
{
	string First_Name;
	string Last_Name;
	string years;
	int number_cards = 0;

public:
	void _Set_First_Name(string& First_Name);
	void _Set_Last_Name(string& Last_Name);
	void _Set_years(string& years);
	void _Set_Number(int number)
	{
		number_cards = number;
	}
	int _Get_Number()
	{
		return number_cards;
	}

};