#include <stdio.h>
#include "CException.h"
using namespace std;

#ifndef Matrice
#define Matrice 

#define Mat_Non_Carre 1
#define Mat_Taille_diff 2
#define Valeur_Non_Valide 3

template <class MType> class CMatrice
{
private:
	unsigned int uiMATNbLignes;
	unsigned int uiMATNbColonnes;
	MType** pMATTableau; 

public:
	CMatrice<MType>();																			//constructeur par défaut
	CMatrice<MType>(CMatrice *MATarg);					   //ok mais exeption a gerer			//constructeur de recopie
	CMatrice<MType>(unsigned int uiNbLignes, unsigned int uiNbColonnes, MType** pMATTableau);	//constructeur avec paramètres
	~CMatrice<MType>();																			//destructeur

	CMatrice MATCalculerTranspose();															//calcule la transposée
	void MATAfficherMatrice(char *pNomMatrice);													//affichage de la matrice
	void MATModifValeur(unsigned int uiChoixLigne, unsigned int uiChoixColonne, MType valeur);  //changement d'une valeur
	CMatrice & operator*(MType rNombre);                    									//multiplication par une constante
	CMatrice & operator/(MType rNombre);                    									//division par une constante
	CMatrice & operator+(CMatrice MATarg);														//addition de deux matrices
	CMatrice & operator*(CMatrice MATarg);														//multiplication de deux matrices
	CMatrice & operator-(CMatrice MATarg);														//soustraction de deux matrices
};

/**
 * @brief construteur par défaut
 */
template<class MType>
inline CMatrice<MType>::CMatrice()
{
	uiMATNbLignes = 1;
	uiMATNbColonnes = 1;
	pMATTableau = nullptr;
}

/**
 * @brief constructeur de recopie
 * @param MATarg
 */
template<class MType>
inline CMatrice<MType>::CMatrice(CMatrice *MATarg)
{
	uiMATNbLignes = MATarg.uiMATNbLignes;
	uiMATNbColonnes = MATarg.uiMATNbColonnes;
	pMATTableau = new MType*[MATarg.uiMATNbLignes];
	unsigned int uiBoucleLigne = 0 ;
	unsigned int uiBoucleColonne = 0 ;

	for (uiBoucleLigne ; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pMATTableau[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne ; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pMATTableau[uiBoucleLigne][uiBoucleColonne] = MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
}

/**
 * @brief constructeur avec paramètre
 * @param uiNbLignes
 * @param uiNbColonnes
 * @param pTab
 */
template<class MType>
inline CMatrice<MType>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes, MType** pTab)
{
	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;
	pMATTableau = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	for (uiBoucleLigne ; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pMATTableau[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne ; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pMATTableau[uiBoucleLigne][uiBoucleColonne] = pTab[uiBoucleLigne][uiBoucleColonne];
		}
	}
}

/**
 * @brief destructeur
 */
template<class MType>
inline CMatrice<MType>::~CMatrice()
{
	/*
	unsigned int uiBoucleLigne = uiMATNbLignes;

	for (uiBoucleLigne ; uiBoucleLigne > 0; uiBoucleLigne--)
	{
			delete[] pMATTableau[uiBoucleLigne];
	}
	delete[] pMATTableau;*/
}

/**
 * @brief calcule de la transposé de la matrice
 * @return 
 */
template<class MType>
inline CMatrice<MType> CMatrice<MType>::MATCalculerTranspose()
{
	if (uiMATNbColonnes != uiMATNbLignes)
	{
		char texte[15] = "matrice non carré\n";
		throw CException(Mat_Non_Carre, texte);
	}

	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	for (uiBoucleLigne ; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne ; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleColonne][uiBoucleLigne];
		}
	}
	CMatrice MATTranspose(uiMATNbLignes, uiMATNbColonnes, pTab);
	
	return MATTranspose;
}

/**
 * @brief permet de définir le nom de la matrice pour l'affichage
 * @param pnomMatrice
 */
template<class MType>
inline void CMatrice<MType>::MATAfficherMatrice(char *pNomMatrice)
{
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	cout << pNomMatrice << " = [\n";
	for ( uiBoucleLigne ; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for ( uiBoucleColonne ; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			cout << pMATTableau[uiBoucleLigne][uiBoucleColonne] << "\t ";
		}
		cout << endl;
	}
	cout << " ]\n" << endl;
}

/**
 * @brief Modifier une valeur de la matrice sans passer par le fichier (fonction pour les test)
 * @param uiChoixLigne
 * @param uiChoixColonne
 * @param valeur
 */
template<class MType>
inline void CMatrice<MType>::MATModifValeur(unsigned int uiChoixLigne, unsigned int uiChoixColonne, MType valeur)
{
	if (uiChoixLigne > uiMATNbLignes || uiChoixColonne > uiMATNbColonnes) 
	{
		char texte[30] = "Choix en dehors de la taille de la matrice\n";
		throw CException(Mat_Taille_diff, texte);
	}
	pMATTableau[uiChoixLigne-1][uiChoixColonne-1] = valeur;
}

/**
 * @brief surcharge opérateur *
 * @param rNombre
 * @return 
 */
template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator*(MType rNombre)
{
	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	for (uiBoucleLigne ; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for ( uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for ( uiBoucleColonne ; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = rNombre * pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATmultiplication(uiMATNbLignes, uiMATNbColonnes, pTab);
	
	return MATmultiplication;
}

/**
 * @brief surcharge opérateur /
 * @param rNombre
 * @return 
 */
template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator/(MType rNombre)
{
	if (rNombre == 0)
	{
		char texte[20] = "Division impossible\n";
		throw CException(Valeur_Non_Valide, texte);
	}

	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	for ( uiBoucleLigne ; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new double[uiMATNbColonnes];

	for ( uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for ( uiBoucleColonne ; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] / rNombre;
		}
	}
	CMatrice MATdivision(uiMATNbLignes, uiMATNbColonnes, pTab);
	
	return MATdivision;
}

/**
 * @brief surcharge opérateur +
 * @param MATarg
 * @return 
 */
template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator+(CMatrice MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbColonnes || uiMATNbLignes != MATarg.uiMATNbLignes)
	{
		char texte[45] = "Impossible d'additionner des matrices de taille différente";
		throw CException(Mat_Taille_diff, texte);
	}

	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	for ( uiBoucleLigne ; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for ( uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for ( uiBoucleColonne ; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] + MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATaddition(uiMATNbLignes, uiMATNbColonnes, pTab);
	
	return MATaddition;

}

/**
 * @brief deuxième surcharge opérateur *
 * @param MATarg
 * @return 
 */
template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator*(CMatrice MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbLignes)
	{
		char texte[100] = "Nb Colonnes de la 1ère matrice différent du Nb Lignes de la 2eme matrice\n";
		throw CException(Mat_Taille_diff,texte);
	}
	unsigned int uiDimension = uiMATNbColonnes;
	
	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;
	unsigned int uiBoucleDimension = 0;

	for (uiBoucleLigne ; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[MATarg.uiMATNbColonnes];

	for ( uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for ( uiBoucleColonne ; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			MType temp = 0;
			for ( uiBoucleDimension ; uiBoucleDimension < uiDimension; uiBoucleDimension++) 
			{
				 temp += this->pMATTableau[uiBoucleLigne][uiBoucleDimension] * MATarg.pMATTableau[uiBoucleDimension][uiBoucleColonne];
			}
			pTab[uiBoucleLigne][uiBoucleColonne] = temp;
		}
	}
	
	CMatrice MATmultiplication(uiMATNbLignes, uiMATNbColonnes, pTab);
	
	return MATmultiplication;
}

/**
 * @brief surcharge opérateur -
 * @param MATarg
 * @return 
 */
template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator-(CMatrice MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbColonnes || uiMATNbLignes != MATarg.uiMATNbLignes)
	{
		char texte[30] = "Matrice de taille différentes\n";
		throw CException(Mat_Taille_diff, texte);
	}

	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	for ( uiBoucleLigne ; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for ( uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for ( uiBoucleColonne ; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] - MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATsoustraction(uiMATNbLignes, uiMATNbColonnes, pTab);
	
	return MATsoustraction;
}

#endif
