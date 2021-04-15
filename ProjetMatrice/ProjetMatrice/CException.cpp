#include "CException.h"


CException::CException()
{
	unsigned int uiEXCValeur = 0;
	string const sEXCDesc = "";
}

CException::CException(CException * EXPobj)
{
	uiEXCValeur = EXPobj->uiEXCValeur;
	sEXCDesc = EXPobj->sEXCDesc;
}

CException::CException(unsigned int uiValeur, string sDesc)
{
	uiEXCValeur = uiValeur;
	sEXCDesc = sDesc;
}

CException::~CException()
{
}

void CException::EXCmodifier_desc(string sDesc)
{
	sEXCDesc = sDesc;
}

void CException::EXCmodifier_valeur(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}


unsigned int CException::EXCavoir_valeur()
{
	return uiEXCValeur;
}

string CException::EXCavoir_desc()
{
	return this->sEXCDesc;
}
