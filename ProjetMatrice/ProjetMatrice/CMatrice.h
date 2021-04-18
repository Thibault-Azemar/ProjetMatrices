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

	CMatrice<MType> MATCalculerTranspose();													    //calcule la transposée
	void MATAfficherMatrice();																	//affichage de la matrice
	//Accesseurs
	MType MATAvoirValeur(unsigned int uiChoixLigne, unsigned int uiChoixColonne);               //retourne une valeur dans un tableau
	unsigned int MATGetNbLignes();                                                              //retourne le nombre de lignes de la matrice
	unsigned int MATGetNbColonnes();                                                            //retourne le nombre de colonnes de la matrice
	//Operateurs
	CMatrice<MType> operator*(const double valeur);												//multiplication par une constante
	CMatrice<MType> operator*(CMatrice<MType> &MATarg);											//multiplication de deux matrices
	CMatrice<MType> operator/(const double valeur);												//division par une constante
	CMatrice<MType> operator+(CMatrice<MType> &MATarg);											//addition de deux matrices
	CMatrice<MType> operator-(CMatrice<MType> &MATarg);											//soustraction de deux matrices
	CMatrice<MType> operator=(CMatrice<MType> &&MATarg);                                        //surcharge de l'opérateur =
};

#include "CMatrice.cpp"

#endif
