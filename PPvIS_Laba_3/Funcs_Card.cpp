#include "Card.h"
using namespace std;
void Card::_Set_Number(string& Number)
{
	this->Number = Number;
}
void Card::_Set_PIN_CODE(string& PIN_CODE)
{
	this->PIN_CODE = PIN_CODE;
}
void Card::_Set_validty(string& validty)
{
	this->validity = validity;
}
string Card::_Get_PIN_CODE()
{
	return PIN_CODE;
}
string Card::_Get_Number()
{
	return Number;
}