#include "CInteraction.h"


CInteraction::CInteraction()
{

}

CInteraction::CInteraction(char *pNomFichier)
{
	ifstream fichier(pNomFichier, ios::in);  // on ouvre en lecture

	if (fichier)  // si l'ouverture a fonctionn�
	{
		unsigned int uiCompteur = 0;
		char cCaractere = 'a'; // caractere � r�cup�rer sur la ligne du fichier
		char *pLigneFichier = new char[100]; // tableau comportant la ligne de fichier � r�cup�rer (100 est arbitraire)
		char *pLigneFichierExtraite;

		/* 1. On est sur la premi�re ligne du fichier cens�e contenir le type de la matrice */
		while (cCaractere != '\n') // tant qu'on est pas � la fin de la ligne
		{
			fichier.get(cCaractere); // on r�cup�re le caract�re de la ligne du fichier
			pLigneFichier[uiCompteur] = cCaractere; // on place le caract�re dans le tableau de la ligne de fichier
			uiCompteur++;
		}

		CString STRTest;
		pLigneFichierExtraite = STRTest.STRExtraireChaine(pLigneFichier, 0, uiCompteur); // appeler cette fonction va permettre de copier la ligne du fichier dans une autre variable

		if (!STRTest.STRChainesEgales(pINTTypeMatriceCorrecte, pLigneFichierExtraite))
		{
			// alors le tableau n'est pas de type double
			// trow exception
		}

		uiCompteur = 0; // r�initialisation � 0 du compteur

		/* 2. On est sur la deuxi�me ligne du fichier cens�e contenir le nombre de lignes */
		while (cCaractere != '=') // tant qu'on est pas � la fin de la ligne
		{
			fichier.get(cCaractere); // on r�cup�re le caract�re de la ligne du fichier
			pLigneFichier[uiCompteur] = cCaractere; // on place le caract�re dans le tableau de la ligne de fichier
			uiCompteur++;
		}

		pLigneFichierExtraite = STRTest.STRExtraireChaine(pLigneFichier, 0, uiCompteur + 1); // appeler cette fonction va permettre de copier la ligne du fichier dans une autre variable

		if (!STRTest.STRChainesEgales(pINTLigneCorrecte, pLigneFichierExtraite))
		{
			// alors la syntaxe n'est pas correcte et on ne peut pas r�cup�rer le nombre de lignes
			// trow exception
		}

		/* on r�cup�re le nombre de lignes */
		char *pNombreLignesTrouve = new char[10];
		uiCompteur = 0;
		while (cCaractere != '\n')
		{
			fichier.get(cCaractere);
			pNombreLignesTrouve[uiCompteur] = cCaractere;
			uiCompteur++;
		}

		pLigneFichierExtraite = STRTest.STRExtraireChaine(pNombreLignesTrouve, 0, uiCompteur + 1); // le nombre se trouve apr�s le "="
		uiINTNbLignes = atoi(pLigneFichierExtraite); // conversion de la cha�ne de caract�re en nombre entier


		uiCompteur = 0; // r�initialisation � 0 du compteur

		/* 3. On est sur la troisi�me ligne du fichier cens�e contenir le nombre de colonnes */
		while (cCaractere != '=') // tant qu'on est pas � la fin de la ligne
		{
			fichier.get(cCaractere); // on r�cup�re le caract�re de la ligne du fichier
			pLigneFichier[uiCompteur] = cCaractere; // on place le caract�re dans le tableau de la ligne de fichier
			uiCompteur++;
		}

		pLigneFichierExtraite = STRTest.STRExtraireChaine(pLigneFichier, 0, uiCompteur + 1); // appeler cette fonction va permettre de copier la ligne du fichier dans une autre variable

		if (!STRTest.STRChainesEgales(pINTColonneCorrecte, pLigneFichierExtraite))
		{
			// alors la syntaxe n'est pas correcte et on ne peut pas r�cup�rer le nombre de colonnes
			// trow exception
		}

		/* on r�cup�re le nombre de lignes */
		char *pNombreColonnesTrouve = new char[10];
		uiCompteur = 0;
		while (cCaractere != '\n')
		{
			fichier.get(cCaractere);
			pNombreColonnesTrouve[uiCompteur] = cCaractere;
			uiCompteur++;
		}

		pLigneFichierExtraite = STRTest.STRExtraireChaine(pNombreColonnesTrouve, 0, uiCompteur + 1); // le nombre se trouve apr�s le "="
		uiINTNbColonnes = atoi(pLigneFichierExtraite); // conversion de la cha�ne de caract�re en nombre entier

		uiCompteur = 0; // r�initialisation � 0 du compteur
		cCaractere = 'a'; // r�initialisation du caract�re

		/* 4. On est sur la quatri�me ligne du fichier cens�e d�clarer */
		while (cCaractere != '\n') // tant qu'on est pas � la fin de la ligne
		{
			fichier.get(cCaractere); // on r�cup�re le caract�re de la ligne du fichier
			pLigneFichier[uiCompteur] = cCaractere; // on place le caract�re dans le tableau de la ligne de fichier
			uiCompteur++;
		}

		pLigneFichierExtraite = STRTest.STRExtraireChaine(pLigneFichier, 0, uiCompteur + 1); // appeler cette fonction va permettre de copier la ligne du fichier dans une autre variable
		delete[] pLigneFichier;

		if (!STRTest.STRChainesEgales(pINTMatriceCorrecte, pLigneFichierExtraite))
		{
			// alors la syntaxe n'est pas correcte et on ne peut pas r�cup�rer le nombre de colonnes
			// trow exception
		}

		uiCompteur = 0; // r�initialisation � 0 du compteur
		cCaractere = 'a'; // r�initialisation du caract�re

		/* cr�ation du tableau de la matrice */
		pINTTab = new double*[uiINTNbColonnes];
		for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiINTNbLignes; uiBoucleLigne++)
			pINTTab[uiBoucleLigne] = new double[uiINTNbColonnes];


		/* 5. On est sur les lignes 5 � 5 + uiINTNbLignes du fichier cens�e d�clarer */
		unsigned int uiLigne = 0, uiColonne = 0;
		while (cCaractere != ']' && (uiLigne != uiINTNbLignes && uiColonne != uiINTNbColonnes))
		{
			cCaractere = 'a';
			char *ptest = new char[10];
			unsigned int i = 0;
			while (cCaractere != ' ' && cCaractere != '\n') // boucle pour r�cup�rer un nombre double
			{
				fichier.get(cCaractere);
				ptest[i] = cCaractere;
				i++;
			}
			pLigneFichierExtraite = STRTest.STRExtraireChaine(ptest, 0, i);
			pINTTab[uiLigne][uiColonne] = atof(pLigneFichierExtraite);
			if (cCaractere == ' ')
			{
				uiColonne++;
			}
			else
			{
				uiLigne++;
				uiColonne = 0;
			}
		}

		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier." << endl;
}

int CInteraction::INTGetNbLignes()
{
	return uiINTNbLignes;
}

int CInteraction::INTGetNbColonnes()
{
	return uiINTNbColonnes;
}

double** CInteraction::INTGetTab()
{
	return pINTTab;
}
