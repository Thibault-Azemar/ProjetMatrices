// ProjetMatrices.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.

#include <iostream>
#include "CMatrice.h"


int main()
{
	unsigned int uiLigne = 3;
	unsigned int uiColonne = 3;
	double** pTab = new double*[uiColonne];
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiLigne; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new double[uiColonne];
	//for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiLigne; uiBoucleLigne++)
		//pTab[uiBoucleLigne] = new double[uiColonne];
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiLigne; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiColonne; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = 2;
		}
	}
	CMatrice<double> MATObjet(uiLigne, uiColonne, pTab);

	//MATObjet.MATAfficherMatrice();
	
	double** pTab2 = new double*[uiColonne];
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiLigne; uiBoucleLigne++)
		pTab2[uiBoucleLigne] = new double[uiColonne];
	//for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiLigne; uiBoucleLigne++)
		//pTab[uiBoucleLigne] = new double[uiColonne];
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiLigne; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiColonne; uiBoucleColonne++)
		{
			pTab2[uiBoucleLigne][uiBoucleColonne] = 1;
		}
	}
	
	CMatrice<double> MATObjet2(uiLigne + 2, uiColonne, pTab2);
	//MATObjet2.MATAfficherMatrice();
	CMatrice<double> MATObjet3(MATObjet2);
	//MATObjet3.MATAfficherMatrice();
	
	//CMatrice<double> MATobj4 = MATObjet *3;


	//MATobj4.MATAfficherMatrice();

	MATObjet.MATModifValeur(1, 2, 5);
	MATObjet.MATModifValeur(1, 1, 6);
	MATObjet.MATModifValeur(2, 1, -1);
	MATObjet.MATModifValeur(1, 3, 9);
	MATObjet.MATCalculerTranspose();
	CMatrice<double> MATobj5;
	MATObjet2.MATAfficherMatrice();
	MATObjet.MATAfficherMatrice();
	MATobj5 = MATObjet2 * MATObjet;
	MATobj5.MATAfficherMatrice();
	/*
	try {
		MATobj3.MATAfficherMatrice();
	}
	catch (CException EXClevee)
	{
		cout << EXClevee.EXCavoir_desc;
	}
	*/
	

	std::cout << "Hello Polytech!\n";
}

// Ex�cuter le programme�: Ctrl+F5 ou menu D�boguer�> Ex�cuter sans d�bogage
// D�boguer le programme�: F5 ou menu D�boguer�> D�marrer le d�bogage

// Astuces pour bien d�marrer�: 
//   1. Utilisez la fen�tre Explorateur de solutions pour ajouter des fichiers et les g�rer.
//   2. Utilisez la fen�tre Team Explorer pour vous connecter au contr�le de code source.
//   3. Utilisez la fen�tre Sortie pour voir la sortie de la g�n�ration et d'autres messages.
//   4. Utilisez la fen�tre Liste d'erreurs pour voir les erreurs.
//   5. Acc�dez � Projet�> Ajouter un nouvel �l�ment pour cr�er des fichiers de code, ou � Projet�> Ajouter un �l�ment existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, acc�dez � Fichier�> Ouvrir�> Projet et s�lectionnez le fichier .sln.