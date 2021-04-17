#include "CString.h"


/**
  * \fn CString::STRChainesEgales(char *pChaineArg1, char *pChaineArg2)
  * \brief permet de vérifier si deux chaînes de caractères sont égales
  *
  * \param[in] pChaineArg1 : la première chaîne de caractères
  * \param[in] pChaineArg2 : la deuxième chaîne de caractères
  * \return vrai si pChaineArg1 == pChaineArg2 sinon faux
  */
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

/**
  * \fn unsigned int CString::STRTailleChaine(char *pChaineArg)
  * \brief permet de calculer la taille d'une chaîne de caractère
  *
  * \param[in] pChaineArg : la chaîne de caractères
  * \return la taille de la chaîne
  */
unsigned int CString::STRTailleChaine(char *pChaineArg)
{
	unsigned int uiTailleChaine = 0;
	while (pChaineArg[uiTailleChaine] != '\0')
	{
		uiTailleChaine++;
	}
	return uiTailleChaine;
}

/**
  * \fn CString::STRExtraireChaine(char *pChaineArg, unsigned int uiDebutChaine, unsigned int uiFinChaine)
  * \brief permet d'extraire une partie de la chaîne de caractère
  *
  * \param[in] pChaineArg : la chaîne de caractères
  * \param[in] uiDebutChaine : le début de la chaîne de caractères
  * \param[in] uiFinChaine : la fin de la chaîne de caractères
  * \return la chaîne comprise entre uiDebutChaine et uiFinChaine
  */
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