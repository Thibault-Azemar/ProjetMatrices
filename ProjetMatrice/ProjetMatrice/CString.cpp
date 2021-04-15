#include "CString.h"
#include <iostream>
using namespace std;


bool CString::STRChainesEgales(char *pChaineArg1, char *pChaineArg2)
{
	if (STRTailleChaine(pChaineArg1) != STRTailleChaine(pChaineArg2))
	{
		return false;
	}
	for (unsigned int uiBoucle = 0; uiBoucle < STRTailleChaine(pChaineArg1); uiBoucle++)
	{
		if (pChaineArg1[uiBoucle] != pChaineArg2[uiBoucle])
		{
			return false;
		}
	}
	return true;
}

unsigned int CString::STRTailleChaine(char *pChaineArg)
{
	unsigned int uiTailleChaine = 0;
	while (pChaineArg[uiTailleChaine] != '\0')
	{
		uiTailleChaine++;
	}
	return uiTailleChaine;
}

char* CString::STRExtraireChaine(char *pChaineArg, unsigned int uiDebutChaine, unsigned int uiFinChaine)
{
	unsigned int uiTailleChaine = uiFinChaine - uiDebutChaine;
	char *pNouvelleChaine = new char[uiTailleChaine];
	unsigned int uiCompteur = 0, uiBoucle;
	for (uiBoucle = uiDebutChaine; uiBoucle < uiFinChaine - 1; uiBoucle++)
	{
		pNouvelleChaine[uiCompteur] = pChaineArg[uiBoucle];
		uiCompteur++;
	}
	pNouvelleChaine[uiCompteur] = '\0';
	return pNouvelleChaine;
}