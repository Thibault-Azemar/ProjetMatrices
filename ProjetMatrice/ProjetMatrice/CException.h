#pragma once
#include <iostream>
using namespace std;

class CException 
{
private:
	unsigned int uiEXCValeur; //numéro de l'erreur
	string sEXCDesc; //Description de l'erreur
public:
	CException();
	CException(CException* EXPobj);
	CException(unsigned int uiValeur, string sDesc);
	~CException();
	void EXCmodifier_desc(string sDesc);
	void EXCmodifier_valeur(unsigned int uiValeur);
	unsigned int EXCavoir_valeur();
	string EXCavoir_desc();
};

