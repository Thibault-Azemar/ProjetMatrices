#include "CException.h"
using namespace std;

CException::CException()
{
	int uiEXCValeur = 0;
}

CException::CException(CException * EXPobj)
{
	int uiEXCValeur = EXPobj->uiEXCValeur;
}

CException::~CException()
{
}

void CException::EXCmodifier_valeur(int EXCValeur)
{
	this->uiEXCValeur = EXCValeur;
}

void CException::EXCafficher_valeur()
{
	cout << uiEXCValeur;
}
