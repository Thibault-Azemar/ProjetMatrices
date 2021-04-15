#pragma once
#include <iostream>
using namespace std;

class CException 
{
private:
	int uiEXCValeur; //numéro de l'erreur
	string sEXCDesc; //Description de l'erreur
public:
	CException();
	CException(CException* EXPobj);
	CException(int uiValeur, string sDesc);
	~CException();
	int EXCavoir_valeur();
	string EXCavoir_desc();
};

