#pragma once
#ifndef Matrice
#define Matrice 

template <class MType> class CMatrice
{
private :
	unsigned int nNombreLigne;
	unsigned int nNombreColonne;
	MType** pTableau; //MType[][]* pTableau

public :
	CMatrice(); //constructeur par défaut
	CMatrice(CMatrice &MATarg); //constructeur de recopie
	CMatrice(unsigned int nNombreLigne, unsigned int nNombreColonne);
	~CMatrice(); //destructeur par défaut
	CMatrice MATCalculerTrans();
	CMatrice MATMultElem(void* c);
	CMatrice MATDivElem(void* c);
	CMatrice operator+(CMatrice* MATarg);
	CMatrice operator*(CMatrice* MATarg);
	CMatrice operator-(CMatrice* MATarg);
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
