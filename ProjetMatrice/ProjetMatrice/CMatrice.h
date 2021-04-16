#include <stdio.h>
#include "CException.h"
using namespace std;

#ifndef Matrice
#define Matrice 

template <class MType> class CMatrice
{
private:
	unsigned int uiMATNbLignes;
	unsigned int uiMATNbColonnes;
	MType** pMATTableau; //MType[][]* pTableau //tableau � double entr�e de pointeur

public:
	CMatrice<MType>();                                    //constructeur par d�faut
	CMatrice<MType>(CMatrice &MATarg);                          //constructeur de recopie
	CMatrice<MType>(unsigned int uiNbLignes, unsigned int uiNbColonnes, MType** pMATTableau); //constructeur avec param�tres
	~CMatrice<MType>();                                   //destructeur

	CMatrice MATCalculerTranspose();               //calcule la transpos�e
	void MATAfficherMatrice();                     //affichage de la matrice
	void MATModifValeur(unsigned int uiChoixLigne, unsigned int uiChoixColonne, MType valeur);                         //changement d'une valeur
	CMatrice & operator*(MType &rNombre);                    //multiplication par une constante
	CMatrice & operator/(MType &rNombre);                    //division par une constante
	CMatrice & operator+(CMatrice &MATarg);                  //addition de deux matrices
	CMatrice & operator*(CMatrice &MATarg);                  //multiplication de deux matrices
	CMatrice & operator-(CMatrice &MATarg);                  //soustraction de deux matrices
};

template<class MType>
inline CMatrice<MType>::CMatrice()
{
	uiMATNbLignes = 0;
	uiMATNbColonnes = 0;
	pMATTableau = nullptr;
}

template<class MType>
inline CMatrice<MType>::CMatrice(CMatrice &MATarg)
{
	uiMATNbLignes = MATarg.uiMATNbLignes;
	uiMATNbColonnes = MATarg.uiMATNbColonnes;
	pMATTableau = new MType*[uiMATNbColonnes];
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pMATTableau[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pMATTableau[uiBoucleLigne][uiBoucleColonne] = MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
}

template<class MType>
inline CMatrice<MType>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes, MType** pTab)
{
	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;
	pMATTableau = new MType*[uiMATNbColonnes];
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pMATTableau[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pMATTableau[uiBoucleLigne][uiBoucleColonne] = pTab[uiBoucleLigne][uiBoucleColonne];
		}
	}
}

template<class MType>
inline CMatrice<MType>::~CMatrice()
{
}

template<class MType>
inline CMatrice<MType> CMatrice<MType>::MATCalculerTranspose()
{
	MType** pTab = new MType*[uiMATNbColonnes];
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		pTab[uiBoucleColonne] = new MType[uiMATNbLignes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pMATTableau[uiBoucleColonne][uiBoucleLigne] = pTab[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MAT1(uiMATNbColonnes, uiMATNbLignes, pTab);
	return MAT1;
}

template<class MType>
inline void CMatrice<MType>::MATAfficherMatrice()
{
	cout << "M = [ ";
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			cout << pMATTableau[uiBoucleLigne][uiBoucleColonne] << " ";
		}
		cout << endl;
	}
	cout << " ]" << endl;
}

template<class MType>
inline void CMatrice<MType>::MATModifValeur(unsigned int uiChoixLigne, unsigned int uiChoixColonne, MType valeur)
{
	if (uiChoixLigne > uiMATNbLignes || uiChoixColonne > uiMATNbColonnes) 
	{
		CException EXCobj;
		EXCobj.EXCmodifier_desc("Choix en dehors de la taille de la matrice");
		throw (EXCobj);
	}
	pMATTableau[uiChoixLigne][uiChoixColonne] = valeur;
}


template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator*(MType &rNombre)
{
	MType** pTab = new MType*[uiMATNbColonnes];
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		pTab[uiBoucleColonne] = new MType[uiMATNbLignes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = rNombre * pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATmultiplication(uiMATNbLignes, uiMATNbColonnes, pTab);
	return MATmultiplication;
}

template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator/(MType &rNombre)
{
	if (rNombre == 0)
	{
		cout << "Impossible de diviser par 0." << endl;
		return;
	}
	MType** pTab = new MType*[uiMATNbColonnes];
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		pTab[uiBoucleColonne] = new double[uiMATNbLignes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] / rNombre;
		}
	}
	CMatrice MATdivision(uiMATNbLignes, uiMATNbColonnes, pTab);
	return MATdivision;
}

template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator+(CMatrice &MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbColonnes || uiMATNbLignes != MATarg.uiMATNbLignes)
	{
		//cout << "Impossible d'additionner ces deux matrices." << endl;
		CException EXCobj;
		EXCobj.EXCmodifier_desc("Matrices de dimensions diff�rentes");
		throw (EXCobj);
	}
	MType** pTab = new MType*[uiMATNbColonnes];
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		pTab[uiBoucleColonne] = new MType[uiMATNbLignes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] + MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATaddition(uiMATNbColonnes, uiMATNbLignes, pTab);
	return MATaddition;
}

template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator*(CMatrice &MATarg)
{
	MType** pTab = new MType*[uiMATNbColonnes];
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		pTab[uiBoucleColonne] = new MType[uiMATNbLignes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = 0;
		}
	}

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] += pMATTableau[uiBoucleLigne][uiBoucleColonne] * MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATmultiplication(uiMATNbLignes, uiMATNbColonnes, pTab);
	return MATmultiplication;
}


template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator-(CMatrice & MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbColonnes || uiMATNbLignes != MATarg.uiMATNbLignes)
	{
		cout << "Impossible de soustraire ces deux matrices." << endl;
		return;
	}
	MType** pTab = new MType*[uiMATNbColonnes];
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		pTab[uiBoucleColonne] = new MType[uiMATNbLignes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] - MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATsoustraction(uiMATNbLignes, uiMATNbColonnes, pTab);
	return MATsoustraction;
}

#endif
