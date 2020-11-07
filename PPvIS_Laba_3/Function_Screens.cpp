#include "Screen_and_Session.h"
using namespace std;
pair<int,int> find_card_owner();
extern vector<string> languages;
extern vector<Card_Account> base;
void Screen_Languages::_Show(pair<int, int>& owner)
{
	bool choose = 0;

	cout << "Choose your language/Выберите свой язык\n0.Русский\n1.English\n";

	cin >> choose;


	Read language;
	language._Read_Language(choose);

}
void Screen_Get_Money::_Show(pair<int, int>& owner)
{
	int sum;
	cout << languages[6] << endl;
	cin >> sum;
	if (base[owner.first]._Get_Cards()[owner.second]._Get_Money() < sum)
	{
		
		cout << languages[8] << endl;
		_Show(owner);
	}
	base[owner.first]._Get_Cards()[owner.second]._Set_money(base[owner.first]._Get_Cards()[owner.second]._Get_Money() - sum);
}
void Screen_Transfer::_Show(pair<int, int>& owner)
{
	

	
	cout << languages[5];


	pair<int,int> another = find_card_owner();

	int sum;
	cout << languages[7] << endl;
	cin >> sum;
	if (base[owner.first]._Get_Cards()[owner.second]._Get_Money() < sum)
	{
		cout << languages[8] << endl;
		_Show(owner);
	}
	base[owner.first]._Get_Cards()[owner.second]._Set_money(base[owner.first]._Get_Cards()[owner.second]._Get_Money() - sum);
	base[another.first]._Get_Cards()[another.second]._Set_money(base[another.first]._Get_Cards()[another.second]._Get_Money() + sum);
	


	

}
void Screen_Choose_Operation::_Show(pair<int, int>& owner)
{
	Screen* screen;
	cout << languages[2] << endl << languages[3] <<endl <<languages[4] << endl;
	bool Is_Transfer = false;
	cin >> Is_Transfer;
	if (Is_Transfer)
	{
		screen = new Screen_Transfer;
		screen->_Show(owner);

	}
	else {
		screen = new Screen_Get_Money;
		screen->_Show(owner);
	}
	screen = new Screen_Choose_Operation;
	screen->_Show(owner);


}
void Screen_PIN_CODE::_Show(pair<int, int>& owner)
{
	string PIN_CODE;

	cout << languages[0] << endl;
	try
	{
		cin >> PIN_CODE;
		if (PIN_CODE.size() != 4)
			throw false;
	}
	catch (const bool &bl)
	{
		cout << "Wrong legnth of PIN CODE\n";
	}
	
	if (base[owner.first]._Get_Cards()[owner.second]._Get_PIN_CODE()!=PIN_CODE)
	{
		cout << languages[1] << endl;
		_Show(owner);
	}


}
void Session::_Use_Screen(Screen& now_screen, pair<int, int>& owner)
{
	now_screen._Show(owner);
} 