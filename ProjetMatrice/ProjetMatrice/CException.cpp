#include "CException.h"


CException::CException()
{
	unsigned int uiEXCValeur = 0;
	string sEXCDesc = "";
}

CException::CException(CException * EXPobj)
{
	uiEXCValeur = EXPobj->uiEXCValeur;
	sEXCDesc = EXPobj->sEXCDesc;
}

CException::CException(unsigned int uiValeur, char* sDesc)
{
	uiEXCValeur = uiValeur;
	sEXCDesc = sDesc;
}

CException::~CException()
{
}

void CException::EXCmodifier_desc(char* sDesc)
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

char* CException::EXCavoir_desc()
{
	return this->sEXCDesc;
}
