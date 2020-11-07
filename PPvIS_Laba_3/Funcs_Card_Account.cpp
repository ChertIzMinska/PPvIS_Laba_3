#include "Card_Account.h"
using namespace std;
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
vector<Card>&Card_Account::_Get_Cards()
{
	return cards;
}
void Card_Account::_Change_Sum_Money(int number, int sum)
{
	cards[0]._Set_money(cards[0]._Get_Money() - sum);
}