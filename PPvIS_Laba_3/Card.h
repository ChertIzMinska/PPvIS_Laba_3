#pragma once
#include<string>
using namespace std;
class Card
{
	string Number;
	string PIN_CODE;
	string validity;
	int money = 0;
public:
	void _Set_Number(string& Number);
	void _Set_PIN_CODE(string& PIN_CODE);
	void _Set_validty(string& validty);
	string _Get_PIN_CODE();
	void _Set_money(int money)
	{
		this->money = money;
	}
	int _Get_Money()
	{
		return money;
	}
	string _Get_Number();

};