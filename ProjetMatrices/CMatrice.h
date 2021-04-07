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
<<<<<<< HEAD
	CMatrice MATCalculerTranspose();
	CMatrice MATMultElem(void* c);
	CMatrice MATDivElem(void* c);
	CMatrice & operator+(CMatrice);
	CMatrice & operator*(CMatrice);
	CMatrice & operator-(CMatrice);
=======
	CMatrice MATCalculerTrans();
	CMatrice operator*(MType* c);
	CMatrice operator/(MType* c);
	CMatrice operator+(CMatrice* MATarg);
	CMatrice operator*(CMatrice* MATarg);
	CMatrice operator-(CMatrice* MATarg);
>>>>>>> fa8812ebf19e709fbc93230e382ce87470285522
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
