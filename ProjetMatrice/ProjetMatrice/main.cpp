// ProjetMatrices.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include "CMatrice.h"
#include "CInteraction.h"


int main()
{

	char fichier[14] = "matrice.txt";
	CInteraction Objet1(fichier);
	char nomMatrice1[5] = "MAT1";
	CMatrice<double> MAT1(Objet1.INTGetNbLignes(), Objet1.INTGetNbColonnes(), Objet1.INTGetTab());
	MAT1.MATAfficherMatrice(nomMatrice1);

	char fichier2[15] = "matrice2.txt";
	CInteraction Objet2(fichier2);
	char nomMatrice2[5] = "MAT2";
	CMatrice<double> MAT2(Objet2.INTGetNbLignes(), Objet2.INTGetNbColonnes(), Objet2.INTGetTab());
	MAT2.MATAfficherMatrice(nomMatrice2);


	char nomMatrice3[5] = "MAT3";
	CMatrice<double> MAT3 = MAT1 * MAT2;
	MAT3.MATAfficherMatrice(nomMatrice3);
}
