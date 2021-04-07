#include <iostream>
using namespace std;

#ifndef Matrice
#define Matrice 

template <class MType> class CMatrice
{
private :
	unsigned int nNombreLignes;
	unsigned int nNombreColonnes;
	MType** pTableau; //MType[][]* pTableau

public :
	CMatrice(); //constructeur par défaut
	CMatrice(CMatrice &MATarg); //constructeur de recopie
	CMatrice(unsigned int nNombreLigne, unsigned int nNombreColonne);
	~CMatrice(); //destructeur par défaut
	CMatrice MATCalculerTranspose();
	CMatrice MATMultElem(void* c);
	CMatrice MATDivElem(void* c);
	CMatrice & operator+(CMatrice);
	CMatrice & operator*(CMatrice);
	CMatrice & operator-(CMatrice);
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
inline CMatrice<MType>::CMatrice(unsigned int nNombreLigne, unsigned int nNombreColonne)
{
}

template<class MType>
inline CMatrice<MType>::~CMatrice()
{
}

template<class MType>
inline CMatrice CMatrice<MType>::MATCalculerTrans()
{
	return CMatrice();
}

template<class MType>
inline CMatrice CMatrice<MType>::MATMultElem(void * c)
{
	return CMatrice();
}

template<class MType>
inline CMatrice CMatrice<MType>::MATDivElem(void * c)
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
