#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;


class CException 
{
private:
	unsigned int uiEXCValeur; //numéro de l'erreur
	char* sEXCDesc; //Description de l'erreur
public:
	CException();
	CException(CException* EXPobj);
	CException(unsigned int uiValeur, char* sDesc);
	~CException();
	void EXCmodifier_desc(char* sDesc);
	void EXCmodifier_valeur(unsigned int uiValeur);
	unsigned int EXCavoir_valeur();
	char* EXCavoir_desc();
};

