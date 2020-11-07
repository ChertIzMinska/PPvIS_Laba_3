#pragma once
#include<vector>
#include<string>
#include<fstream>
#include"User.h"
#include"Card.h"
#include"Screen_and_Session.h"
using namespace std;
class Read
{
	ifstream file;

	void _Check_Exception();
	void _Read_Card(vector<User>& user);
	void _Read_Account(vector<User>& user);
public:
	void _Read();
	void _Read_Language(bool& Is_English);
};