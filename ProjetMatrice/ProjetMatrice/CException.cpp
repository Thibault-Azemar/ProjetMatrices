#include "CException.h"


CException::CException()
{
	unsigned int uiEXCValeur = 0;
	string sEXCDesc = "";
}

CException::CException(CException * EXPobj)
{
	uiEXCValeur = EXPobj->uiEXCValeur;
	pEXCDesc = EXPobj->pEXCDesc;
}

CException::CException(unsigned int uiValeur, char* pDesc)
{
	uiEXCValeur = uiValeur;
	pEXCDesc = pDesc;
}

CException::~CException()
{
}

void CException::EXCModifierDesc(char* pDesc)
{
	pEXCDesc = pDesc;
}

void CException::EXCModifierValeur(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}


unsigned int CException::EXCAvoirValeur()
{
	return uiEXCValeur;
}

char* CException::EXCAvoirDesc()
{
	return this->pEXCDesc;
}
