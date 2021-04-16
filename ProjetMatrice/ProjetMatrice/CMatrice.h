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
	MType** pMATTableau; //MType[][]* pTableau //tableau à double entrée de pointeur

public:
	CMatrice<MType>();                                     //ok					//constructeur par défaut
	CMatrice<MType>(CMatrice *MATarg);					   //ok mais exeption a gerer					//constructeur de recopie
	CMatrice<MType>(unsigned int uiNbLignes, unsigned int uiNbColonnes, MType** pMATTableau); //constructeur avec paramètres
	~CMatrice<MType>();                                   //destructeur

	CMatrice MATCalculerTranspose();						//ok				//calcule la transposée
	void MATAfficherMatrice(char *nomMatrice);								//ok				//affichage de la matrice
	void MATModifValeur(unsigned int uiChoixLigne, unsigned int uiChoixColonne, MType valeur);           //ok              //changement d'une valeur
	CMatrice & operator*(MType rNombre);                    //ok				//multiplication par une constante
	CMatrice & operator/(MType rNombre);                    //ok				//division par une constante
	CMatrice & operator+(CMatrice MATarg);                 //ok				//addition de deux matrices
	CMatrice & operator*(CMatrice MATarg);										//multiplication de deux matrices
	CMatrice & operator-(CMatrice MATarg);                 //ok				//soustraction de deux matrices
};

template<class MType>
inline CMatrice<MType>::CMatrice()
{
	uiMATNbLignes = 1;
	uiMATNbColonnes = 1;
	pMATTableau = nullptr;
}

template<class MType>
inline CMatrice<MType>::CMatrice(CMatrice *MATarg)
{
	uiMATNbLignes = MATarg.uiMATNbLignes;
	uiMATNbColonnes = MATarg.uiMATNbColonnes;
	pMATTableau = new MType*[MATarg.uiMATNbLignes];
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
	pMATTableau = new MType*[uiMATNbLignes];
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
	if (uiMATNbColonnes != uiMATNbLignes)
	{
		CException EXCobj;
		EXCobj.EXCmodifier_desc("Matrice non caré");
		throw (EXCobj);
	}
	MType** pTab = new MType*[uiMATNbLignes];
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleColonne][uiBoucleLigne];
		}
	}
	CMatrice MAT1(uiMATNbLignes, uiMATNbColonnes, pTab);
	//MAT1.MATAfficherMatrice();
	return MAT1;
}

template<class MType>
inline void CMatrice<MType>::MATAfficherMatrice(char *nomMatrice)
{
	cout << nomMatrice << " = [\n";
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			cout << pMATTableau[uiBoucleLigne][uiBoucleColonne] << "\t ";
		}
		cout << endl;
	}
	cout << " ]\n" << endl;
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
	pMATTableau[uiChoixLigne-1][uiChoixColonne-1] = valeur;
}


template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator*(MType rNombre)
{
	MType** pTab = new MType*[uiMATNbLignes];
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = rNombre * pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATmultiplication(uiMATNbLignes, uiMATNbColonnes, pTab);
	//MATmultiplication.MATAfficherMatrice();
	return MATmultiplication;
}

template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator/(MType rNombre)
{
	if (rNombre == 0)
	{
		CException EXCobj;
		EXCobj.EXCmodifier_desc("Division impossible");
		throw (EXCobj);
	}
	MType** pTab = new MType*[uiMATNbLignes];
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
	MATdivision.MATAfficherMatrice();
	return MATdivision;
}

template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator+(CMatrice MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbColonnes || uiMATNbLignes != MATarg.uiMATNbLignes)
	{
		//cout << "Impossible d'additionner ces deux matrices." << endl;
		CException EXCobj;
		EXCobj.EXCmodifier_desc("Matrices de dimensions différentes");
		throw (EXCobj);
	}
	MType** pTab = new MType*[uiMATNbLignes];
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] + MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATaddition(uiMATNbLignes, uiMATNbColonnes, pTab);
	//MATaddition.MATAfficherMatrice();
	return MATaddition;

}

template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator*(CMatrice MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbLignes)
	{
		CException EXCobj;
		EXCobj.EXCmodifier_desc("Matrices de dimensions différentes");  //PAS LA BONNE EXCEPTION A CHANGER
		throw (EXCobj);
	}
	unsigned int uiDimension = uiMATNbColonnes;
	
	MType** pTab = new MType*[uiMATNbLignes];
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[MATarg.uiMATNbColonnes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			MType temp = 0;
			for (unsigned int uiBoucleDimension = 0; uiBoucleDimension < uiDimension; uiBoucleDimension++) 
			{
				 temp += this->pMATTableau[uiBoucleLigne][uiBoucleDimension] * MATarg.pMATTableau[uiBoucleDimension][uiBoucleColonne];
			}
			pTab[uiBoucleLigne][uiBoucleColonne] = temp;
		}
	}
	
	CMatrice MATmultiplication(uiMATNbLignes, uiMATNbColonnes, pTab);
	//MATmultiplication.MATAfficherMatrice();
	return MATmultiplication;
}


template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator-(CMatrice MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbColonnes || uiMATNbLignes != MATarg.uiMATNbLignes)
	{
		//cout << "Impossible de soustraire ces deux matrices." << endl;
		CException EXCobj;
		EXCobj.EXCmodifier_desc("Matrices de dimensions différentes");
		throw (EXCobj);
		
	}
	MType** pTab = new MType*[uiMATNbLignes];
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] - MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATsoustraction(uiMATNbLignes, uiMATNbColonnes, pTab);
	//MATsoustraction.MATAfficherMatrice();
	return MATsoustraction;
}

#endif
