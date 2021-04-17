#include "CInteraction.h"
#include "CException.h"

#define Mat_Mauvais_Type 4
#define Syntaxe_Incorrecte 5
#define Fichier_Err 6

CInteraction::CInteraction()
{

}

CInteraction::CInteraction(char *pNomFichier)
{
	ifstream fichier(pNomFichier, ios::in);  // on ouvre en lecture

	if (fichier) // si l'ouverture a fonctionn�
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
			//throw CException(Mat_Mauvais_Type, "Choix en dehors du type de la matrice\n");
		}


		/* 2. On est sur la deuxi�me ligne du fichier cens�e contenir le nombre de lignes */
		uiCompteur = 0; // r�initialisation � 0 du compteur
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
			//throw CException(Syntaxe_Incorrecte, "Syntaxe incorrecte, on ne peut pas recup�rer le nombre de lignes(ligne 2)\n");
		}

		/* on r�cup�re le nombre de lignes */
		uiCompteur = 0;
		while (cCaractere != '\n')
		{
			fichier.get(cCaractere);
			pLigneFichier[uiCompteur] = cCaractere;
			uiCompteur++;
		}

		pLigneFichierExtraite = STRTest.STRExtraireChaine(pLigneFichier, 0, uiCompteur + 1); // le nombre se trouve apr�s le "="
		uiINTNbLignes = atoi(pLigneFichierExtraite); // conversion de la cha�ne de caract�re en nombre entier


		/* 3. On est sur la troisi�me ligne du fichier cens�e contenir le nombre de colonnes */
		uiCompteur = 0; // r�initialisation � 0 du compteur
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
			//throw CException(Syntaxe_Incorecte, "Syntaxe incorrecte, on ne peut pas recup�rer le nombre de colonnes(ligne 3)\n");
		}

		/* on r�cup�re le nombre de colonnes */
		uiCompteur = 0;
		while (cCaractere != '\n')
		{
			fichier.get(cCaractere);
			pLigneFichier[uiCompteur] = cCaractere;
			uiCompteur++;
		}

		pLigneFichierExtraite = STRTest.STRExtraireChaine(pLigneFichier, 0, uiCompteur + 1); // le nombre se trouve apr�s le "="
		uiINTNbColonnes = atoi(pLigneFichierExtraite); // conversion de la cha�ne de caract�re en nombre entier


		/* 4. On est sur la quatri�me ligne du fichier cens�e d�clarer "Matrice=[" */
		uiCompteur = 0; // r�initialisation � 0 du compteur
		cCaractere = 'a'; // r�initialisation du caract�re
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
			// alors la syntaxe n'est pas correcte et on ne peut pas r�cup�rer la matrice 
			// trow exception
			//throw CException(Syntaxe_Incorecte, "Syntaxe incorrecte, ligne 5 (Matrice=[)\n");
		}

		/* cr�ation du tableau de la matrice */
		pINTTab = new double*[uiINTNbColonnes];
		for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiINTNbLignes; uiBoucleLigne++)
			pINTTab[uiBoucleLigne] = new double[uiINTNbColonnes];


		/* 5. On est sur les lignes 5 � 5 + uiINTNbLignes du fichier cens�e d�clarer */
		uiCompteur = 0; // r�initialisation � 0 du compteur
		cCaractere = 'a'; // r�initialisation du caract�re
		unsigned int uiLigne = 0, uiColonne = 0;
		while (cCaractere != ']' && (uiLigne != uiINTNbLignes && uiColonne != uiINTNbColonnes)) // la boucle s'arr�te quand on d�tecte ']' ou quand on a le nombre de lignes et de colonnes exactes
		{
			cCaractere = 'a'; // r�initialisation du caract�re
			char *pNombreTemp = new char[10]; // le nombre va d'abord �tre r�cup�rer sous forme de tableau de cha�ne puis �tre converti en float
			unsigned int uiTailleNombreChaine = 0; // la taille du nombre tant que celui-ci est un tableau de char
			while (cCaractere != ' ' && cCaractere != '\n') // boucle pour r�cup�rer un nombre double
			{
				fichier.get(cCaractere);
				pNombreTemp[uiTailleNombreChaine] = cCaractere;
				uiTailleNombreChaine++;
			}

			pLigneFichierExtraite = STRTest.STRExtraireChaine(pNombreTemp, 0, uiTailleNombreChaine); // r�cup�ration de la ligne
			pINTTab[uiLigne][uiColonne] = atof(pLigneFichierExtraite); // conversion et ajout au tableau 2D

			if (cCaractere == ' ')
			{
				// si le caract�re est un espace alors on passe au nombre suivant sur la m�me ligne et donc le nombre de colonne augmente
				uiColonne++;
				if (uiColonne == uiINTNbColonnes)
				{
					//cout << "Veuillez ne pas mettre d'espace avant ou apr�s chaque nombre, seules les tabulations sont autoris�es." << endl;
					// lever exception
					//throw CException(Syntaxe_Incorecte, "Veuillez ne pas mettre d'espace en fin de ligne\n");
				}
			}
			else
			{
				// sinon, c'est un caract�re de retour � la ligne donc on passe � la ligne suivante et on repasse � la colonne 0
				uiLigne++;
				uiColonne = 0;
			}
		}
		delete[] pLigneFichierExtraite;

		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier." << endl;
		//throw CException(Fichier_Err, "Impossible d'ouvrir le fichier.\n");
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
