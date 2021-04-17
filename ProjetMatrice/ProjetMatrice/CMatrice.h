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
	CMatrice<MType>(CMatrice *MATarg);					   //ok mais exeption a gerer			//constructeur de recopie
	CMatrice<MType>(unsigned int uiNbLignes, unsigned int uiNbColonnes, MType** pMATTableau);	//constructeur avec paramètres
	~CMatrice<MType>();																			//destructeur

	CMatrice MATCalculerTranspose();															//calcule la transposée
	void MATAfficherMatrice(char *pNomMatrice);													//affichage de la matrice
	void MATModifValeur(unsigned int uiChoixLigne, unsigned int uiChoixColonne, MType valeur);  //changement d'une valeur
	CMatrice & operator*(MType valeur);                    									//multiplication par une constante
	CMatrice & operator*(CMatrice MATarg);														//multiplication de deux matrices
	CMatrice & operator/(MType valeur);                    									//division par une constante
	CMatrice & operator+(CMatrice MATarg);														//addition de deux matrices
	CMatrice & operator-(CMatrice MATarg);														//soustraction de deux matrices
};

#include "CMatrice.cpp"

#endif
