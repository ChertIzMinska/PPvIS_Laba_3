#include "Header.h"
using namespace std;
extern vector<string> languages;
extern vector<Card_Account> base;
void Screen_Languages::_Show(Card_Account& owner)
{
	bool choose = 0;

	cout << "Choose your language/Выберите свой язык\n0.Русский\n1.English\n";

	cin >> choose;

	Read language;
	language._Read_Language(choose);

}
void Screen_How_much_money::_Show(Card_Account& owner)
{
	int sum;
	cout << languages[7] << endl;
	cin >> sum;
	if (owner._Get_Cards()[0]._Get_Money() < sum)
	{
		cout << languages[8] << endl;
		_Show(owner);
	}
	owner._Change_Sum_Money(0, sum);
}
void Screen_Get_Money::_Show(Card_Account& owner)
{
	int sum;
	cout << languages[6] << endl;
	cin >> sum;
	if (owner._Get_Cards()[0]._Get_Money() < sum)
	{
		
		cout << languages[8] << endl;
		_Show(owner);
	}
	owner._Change_Sum_Money(0,sum);
}
void Screen_Transfer::_Show(Card_Account& owner)
{
	string Number_Card;
	string validity;
	cout << languages[5];
	cin >> Number_Card;
	cin >> validity;

}
void Screen_Choose_Operation::_Show(Card_Account& owner)
{
	Screen* screen;
	cout << languages[2] << endl << languages[3] <<endl <<languages[4] << endl;
	bool Is_Transfer = false;
	cin >> Is_Transfer;
	if (Is_Transfer)
	{
		screen = new Screen_Transfer;
		screen->_Show(owner);
		screen = new Screen_How_much_money;
		screen->_Show(owner);

	}
	else {
		screen = new Screen_Get_Money;
		screen->_Show(owner);
	}
	screen = new Screen_Choose_Operation;
	screen->_Show(owner);


}
void Screen_PIN_CODE::_Show(Card_Account& owner)
{
	string PIN_CODE;

	cout << languages[0] << endl;
	cin >> PIN_CODE;
	if (PIN_CODE.compare(owner._Get_Cards()[0]._Get_PIN_CODE()) != 0)
	{
		cout << languages[1] << endl;
		_Show(owner);
	}


}
void Session::_Use_Screen(Screen& now_screen, Card_Account& owner)
{
	now_screen._Show(owner);
}
void Session::_Start_Session(Card_Account& owner)
{
	string Number_card;
	cin >> Number_card;

	Screen* screen = new Screen_Languages;
	_Use_Screen(*screen, owner);
	screen = new Screen_PIN_CODE;
	_Use_Screen(*screen, owner);
	screen = new Screen_Choose_Operation;
	_Use_Screen(*screen, owner);
}