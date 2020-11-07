#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <Windows.h>
#include<cmath>
#include "Reader.h"
#include "Card_Account.h"
using namespace std;
class Screen
{
public:
	virtual void _Show(pair<int,int> &owner) = 0;
};
class Screen_Languages :public Screen
{
public:
	void _Show(pair<int, int>& owner);
};
class Screen_Get_Money :public Screen
{
public:
	void _Show(pair<int, int>& owner);
};
class Screen_Transfer :public Screen
{
public:
	void _Show(pair<int, int>& owner);
};
class Screen_Choose_Operation :public Screen
{
public:
	void _Show(pair<int, int>& owner);
};
class Screen_PIN_CODE :public Screen
{
public:
	void _Show(pair<int, int>& owner);
};
class Session {
public:
	void _Use_Screen(Screen& now_screen, pair<int, int>& owner);
	void _Start_Session();
};