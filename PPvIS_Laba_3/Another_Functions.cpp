#include "Reader.h"
#include "Card_Account.h"
using namespace std;
extern vector<string> languages;
int _String_into_int(string string);
extern vector<Card_Account> base;
pair<int,int>find_card_owner();
void create_account(User& users, vector<Card>& all_cards);
bool check_correct_card(string &Number_card)
{
	int arr[3] = { 16,3};
	for (int i = 0; i < Number_card.size(); i++)
	{
		if (Number_card[i] == '-')
		{
			arr[1]--;
			
		}
		else if (Number_card[i] == '1' || Number_card[i] == '2'|| Number_card[i] == '3'|| Number_card[i] == '4'|| Number_card[i] == '5'|| Number_card[i] == '6'|| Number_card[i] == '7'|| Number_card[i] == '8'|| Number_card[i] == '9'|| Number_card[i] == '0')
		{
			arr[0]--;
		}
		else {
			return 0;
		}


		
	}
	if (arr[0] != 0)
		return 0;
	if (arr[1] != 0)
		return 0;

	return 1;
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
void create_account(User& users, vector<Card>& all_cards)
{
	Card_Account Is(users, all_cards);
	base.push_back(Is);
}
void Session::_Start_Session()
{
	pair<int,int> owner = find_card_owner();
	Screen* screen = new Screen_Languages;
	_Use_Screen(*screen, owner);
	screen = new Screen_PIN_CODE;
	_Use_Screen(*screen, owner);
	screen = new Screen_Choose_Operation;
	_Use_Screen(*screen, owner);
}
pair<int,int> find_card_owner()
{
	string Number_card;
	try
	{
		cin >> Number_card;
		if (!check_correct_card(Number_card))
			throw "totally incorrect card entry.";
		
	}
	catch (const string &str)
	{
		cout << str<<endl;
		cout << "Example of correct card : 5578 - 2312 - 2212 - 5554." << endl;
		return find_card_owner();
		
	}
	

	for (int g=0;g<base.size();g++)
	{
		Card_Account ch = base[g];
		for (int i = 0; i < ch._Get_Cards().size(); i++)
		{
			if (Number_card == ch._Get_Cards()[i]._Get_Number())
			{
				pair<int, int> res;
				res.first = g;
				res.second = i;
				return res;
			}
		}
	}
	find_card_owner();
	
}
