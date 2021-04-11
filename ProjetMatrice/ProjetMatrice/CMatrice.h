#include <iostream>
using namespace std;

#ifndef Matrice
#define Matrice 

template <class MType> class CMatrice
{
private:
	unsigned int nNombreLignes;
	unsigned int nNombreColonnes;
	MType** pTableau; //MType[][]* pTableau //tableau à double entrée de pointeur

public:
	CMatrice();                                    //constructeur par défaut
	CMatrice(CMatrice &);                          //constructeur de recopie
	CMatrice(unsigned int, unsigned int, MType**); //constructeur avec paramètres
	~CMatrice();                                   //destructeur
	CMatrice MATCalculerTranspose();               //calcule la transposée
	void MATAfficherMatrice();                     //affichage de la matrice
	CMatrice operator*(MType);                     //multiplication par une constante
	CMatrice operator/(MType);                     //division par une constante
	CMatrice operator+(CMatrice);                  //addition de deux matrices
	CMatrice operator*(CMatrice);                  //multiplication de deux matrices
	CMatrice operator-(CMatrice);                  //soustraction de deux matrices
};

template<class MType>
inline CMatrice<MType>::CMatrice()
{
}

template<class MType>
inline CMatrice<MType>::CMatrice(CMatrice &MATarg)
{
	nNombreLignes = MATarg.nNombreLignes;
	nNombreColonnes = MATarg.nNombreColonnes;
	pTableau = new MType*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTableau[nI] = new MType[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTableau[nI][nJ] = MATarg.pTableau[nI][nJ];
		}
	}
}

template<class MType>
inline CMatrice<MType>::CMatrice(unsigned int nNbLignes, unsigned int nNbColonnes, MType** pTableau)
{
	nNombreLignes = nNbLignes;
	nNombreColonnes = nNbColonnes;
	pTableau = new MType*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTableau[nI] = new MType[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTableau[nI][nJ] = pTab[nI][nJ];
		}
	}
}

template<class MType>
inline CMatrice<MType>::~CMatrice()
{
}

template<class MType>
inline CMatrice CMatrice<MType>::MATCalculerTranspose()
{
	MType** pTab = new MType*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTab[nI] = new MType[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTableau[nJ][nI] = pTab[nI][nJ];
		}
	}
	CMatrice MAT1(nNombreColonnes, nNombreLignes, pTab);
	return MAT1;
}

template<class MType>
inline void CMatrice<MType>::MATAfficherMatrice()
{
	cout << "M = [ ";
	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			cout << pTableau[nJ][nI] << " ";
		}
		cout << endl;
	}
	cout << " ]" << endl;
}

template<class MType>
inline CMatrice CMatrice<MType>::operator*(MType *rNombre)
{
	MType** pTab = new MType*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTab[nI] = new MType[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTab[nI][nJ] = rNombre * pTableau[nI][nJ];
		}
	}
	CMatrice MATmultiplication(nNombreLignes, nNombreColonnes, pTab);
	return MATmultiplication;
}

template<class MType>
inline CMatrice CMatrice<MType>::operator/(MType *rNombre)
{
	if (rNombre == 0)
	{
		cout << "Impossible de diviser par 0." << endl;
		return;
	}
	MType** pTab = new MType*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTab[nI] = new double[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTab[nI][nJ] = pTableau[nI][nJ] / rNombre;
		}
	}
	CMatrice MATdivision(nNombreLignes, nNombreColonnes, pTab);
	return MATdivision;
}

template<class MType>
inline CMatrice CMatrice<MType>::operator+(CMatrice MATarg)
{
	if (nNombreColonnes != MATarg.nNombreColonnes || nNombreLignes != MATarg.nNombreLignes)
	{
		cout << "Impossible d'additionner ces deux matrices." << endl;
		return;
	}
	MType** pTab = new MType*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTab[nI] = new MType[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTab[nI][nJ] = pTableau[nI][nJ] + MATarg.pTableau[nI][nJ];
		}
	}
	CMatrice MATaddition(nNombreColonnes, nNombreLignes, pTab);
	return MATaddition;
}

template<class MType>
inline CMatrice CMatrice<MType>::operator*(CMatrice MATarg)
{
	MType** pTab = new MType*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTab[nI] = new MType[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTab[nI][nJ] = 0;
		}
	}

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTab[nI][nJ] += pTableau[nI][nJ] * MATarg.pTableau[nI][nJ];
		}
	}
	CMatrice MATmultiplication(nNombreLignes, nNombreColonnes, pTab);
	return MATmultiplication;
}

template<class MType>
inline CMatrice CMatrice<MType>::operator-(CMatrice MATarg)
{
	if (nNombreColonnes != MATarg.nNombreColonnes || nNombreLignes != MATarg.nNombreLignes)
	{
		cout << "Impossible de soustraire ces deux matrices." << endl;
		return;
	}
	MType** pTab = new MType*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTab[nI] = new MType[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTab[nI][nJ] = pTableau[nI][nJ] - MATarg.pTableau[nI][nJ];
		}
	}
	CMatrice MATsoustraction(nNombreLignes, nNombreColonnes, pTab);
	return MATsoustraction;
}

#endif
