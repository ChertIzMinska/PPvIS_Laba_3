#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <Windows.h>
#include<cmath>
using namespace std;
extern vector<string> languages;
class User
{
	string First_Name;
	string Last_Name;
	string years;

public:
	void _Set_First_Name(string& First_Name);
	void _Set_Last_Name(string& Last_Name);
	void _Set_years(string& years);


};
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

};
class Card_Account {

	User Owner;
	vector<Card> cards;
public:
	void _Set_User(User& owner);
	void _Set_cards(vector<Card>& cards);
	Card_Account(User& owner, vector<Card>& cards);
	User _Get_User();
	vector<Card>_Get_Cards();
	void _Change_Sum_Money(int nubmer, int sum);

};
class Screen
{
public:
	virtual void _Show(Card_Account& owner) = 0;
};
class Screen_Languages:public Screen
{
public:
	void _Show(Card_Account& owner);
};
class Screen_How_much_money :public Screen
{
public:
	void _Show(Card_Account& owner);
};
class Screen_Get_Money :public Screen
{
public:
	void _Show(Card_Account& owner);
};
class Screen_Transfer :public Screen
{
public:
	void _Show(Card_Account& owner);
};
class Screen_Choose_Operation:public Screen
{
public:
	void _Show(Card_Account& owner);
};
class Screen_PIN_CODE :public Screen
{
public:
	void _Show(Card_Account& owner);
};
class Session {
public:
	void _Use_Screen(Screen& now_screen, Card_Account& owner);
	void _Start_Session(Card_Account& owner);
};
class Read
{
	ifstream file;
	
	void _Read_Card(vector<Card>& all_cards);
	void _Read_Account(User& user);
public:
	void _Read();
	void _Read_Language(bool& Is_English);
};
int _String_into_int(string string);
extern vector<Card_Account> base;