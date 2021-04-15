#include "CException.h"


CException::CException()
{
	int uiEXCValeur = 0;
	string const& sEXCDesc = "";
}

CException::CException(CException * EXPobj)
{
	uiEXCValeur = EXPobj->uiEXCValeur;
	sEXCDesc = EXPobj->sEXCDesc;
}

CException::CException(int uiValeur, string sDesc)
{
	uiEXCValeur = uiValeur;
	sEXCDesc = sDesc;
}

CException::~CException()
{
}


int CException::EXCavoir_valeur()
{
	return uiEXCValeur;
}

string CException::EXCavoir_desc()
{
	return this->sEXCDesc;
}
