// ProjetMatrices.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

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

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.