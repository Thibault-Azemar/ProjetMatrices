#include "CException.h"

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
	CMatrice<MType>(CMatrice &MATarg);															//constructeur de recopie
	CMatrice<MType>(unsigned int uiNbLignes, unsigned int uiNbColonnes, MType** pMATTableau);	//constructeur avec paramètres
	~CMatrice<MType>();																			//destructeur

	CMatrice<MType> MATCalculerTranspose();															//calcule la transposée
	void MATAfficherMatrice(char *pNomMatrice);													//affichage de la matrice
	MType MATAvoirValeur(unsigned int uiChoixLigne, unsigned int uiChoixColonne);  //changement d'une valeur
	unsigned int MATGetNbLignes(CMatrice<MType> &MATarg);
	unsigned int MATGetNbColonnes(CMatrice<MType> &MATarg);
	CMatrice<MType> operator*(const double valeur);															//multiplication par une constante
	CMatrice<MType> operator*(CMatrice<MType> &MATarg);														//multiplication de deux matrices
	CMatrice<MType> operator/(const double valeur);															//division par une constante
	CMatrice<MType> operator+(CMatrice<MType> &MATarg);														//addition de deux matrices
	CMatrice<MType> operator-(CMatrice<MType> &MATarg);														//soustraction de deux matrices
	CMatrice<MType> operator=(CMatrice<MType> &&MATarg);
};

#include "CMatrice.cpp"

#endif
