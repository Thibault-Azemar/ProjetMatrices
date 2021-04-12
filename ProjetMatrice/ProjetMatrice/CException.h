#pragma once
#include <iostream>

class CException
{
private:
	int uiEXCValeur;
public:
	CException();
	CException(CException* EXPobj);
	~CException();
	void EXCmodifier_valeur(int EXCValeur);
	void EXCafficher_valeur();
};

