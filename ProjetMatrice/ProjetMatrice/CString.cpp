#include "CString.h"


bool CString::CSTComparerChaines(char *pChaineArg1, char *pChaineArg2)
{
	if (CSTTailleChaine(pChaineArg1) != CSTTailleChaine(pChaineArg2))
	{
		return false;
	}
	for (unsigned int uiBoucle = 0; uiBoucle < CSTTailleChaine(pChaineArg1); uiBoucle++)
	{
		if (pChaineArg1[uiBoucle] != pChaineArg2[uiBoucle])
		{
			return false;
		}
	}
	return true;
}

unsigned int CString::CSTTailleChaine(char *pChaineArg)
{
	unsigned int uiTailleChaine = 0;
	while (pChaineArg[uiTailleChaine] != '\0')
	{
		uiTailleChaine++;
	}
	return uiTailleChaine
}

char* CString::CSTExtraireChaine(char *pChaineArg, unsigned int uiDebutChaine, unsigned int uiFinChaine)
{
	unsigned int uiTailleChaine = uiFinChaine - uiDebutChaine + 1;
	char *pNouvelleChaine = new char[uiTailleChaine];
	unsigned int uiCompteur = 0;
	for (unsigned int uiBoucle = uiDebutChaine; uiBoucle < uiFinChaine; uiBoucle++)
	{
		pNouvelleChaine[uiCompteur] = pChaineArg[uiBoucle];
		uiCompteur++;
	}
	return pNouvelleChaine;
}