#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;


class CException 
{
private:
	unsigned int uiEXCValeur; // Numéro de l'erreur
	char* pEXCDesc;           // Description de l'erreur
public:
	CException();
	CException(CException* EXPobj);
	CException(unsigned int uiValeur, char* pDesc);
	~CException();
	void EXCModifierDesc(char* pDesc);
	void EXCModifierValeur(unsigned int uiValeur);
	unsigned int EXCAvoirValeur();
	char* EXCAvoirDesc();
};