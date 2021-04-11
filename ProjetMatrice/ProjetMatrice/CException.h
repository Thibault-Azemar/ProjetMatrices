#pragma once
class CException
{
private:
	int uiEXCValeur;
public:
	CException();
	CException(CException* EXPobj);
	~CException();
	void EXCmodifier_valeur(int EXCValeur);

};

