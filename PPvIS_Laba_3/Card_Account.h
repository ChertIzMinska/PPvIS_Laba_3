#pragma once
#include "User.h"
#include <vector>
#include "Card.h"
using namespace std;
class Card_Account {

	User Owner;
	vector<Card> cards;
public:
	void _Set_User(User& owner);
	void _Set_cards(vector<Card>& cards);
	Card_Account(User& owner, vector<Card>& cards);
	User _Get_User();
	vector<Card>& _Get_Cards();
	void _Change_Sum_Money(int nubmer, int sum);

};