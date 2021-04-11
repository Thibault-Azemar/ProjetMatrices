#include "CException.h"

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
