#include <iostream>
using namespace std;

#ifndef Matrice
#define Matrice 

template <class MType> class CMatrice
{
private :
	unsigned int nNombreLignes;
	unsigned int nNombreColonnes;
	MType** pTableau; //MType[][]* pTableau //tableau à double entrée de pointeur

public :
	CMatrice(); //constructeur par défaut
	CMatrice(CMatrice &MATarg); //constructeur de recopie
	CMatrice(unsigned int nNombreLigne, unsigned int nNombreColonne, MType** pTableau);
	~CMatrice(); //destructeur par défaut
	CMatrice MATCalculerTranspose(); //calcule la transposée
	CMatrice operator*(MType* c); //multiplication par une constante
	CMatrice operator/(MType* c); //division par une constante
	CMatrice operator+(CMatrice* Mat); //addition de deux matrices
	CMatrice operator*(CMatrice* Mat); //multiplication de deux matrices
	CMatrice operator-(CMatrice* Mat); //soustraction de deux matrices
};
#endif

template<class MType>
inline CMatrice<MType>::CMatrice()
{
}

template<class MType>
inline CMatrice<MType>::CMatrice(CMatrice & MATarg)
{
}

template<class MType>
inline CMatrice<MType>::CMatrice(unsigned int nNombreLigne, unsigned int nNombreColonne, MType** pTableau)
{
}

template<class MType>
inline CMatrice<MType>::~CMatrice()
{
}

template<class MType>
inline CMatrice CMatrice<MType>::MATCalculerTranspose()
{
	return CMatrice();
}

template<class MType>
inline CMatrice CMatrice<MType>::operator*(MType * c)
{
	return CMatrice();
}

template<class MType>
inline CMatrice CMatrice<MType>::operator/(MType * c)
{
	return CMatrice();
}

template<class MType>
inline CMatrice CMatrice<MType>::operator+(CMatrice * MATarg)
{
	return CMatrice();
}

template<class MType>
inline CMatrice CMatrice<MType>::operator*(CMatrice * MATarg)
{
	return CMatrice();
}

template<class MType>
inline CMatrice CMatrice<MType>::operator-(CMatrice * MATarg)
{
	return CMatrice();
}
