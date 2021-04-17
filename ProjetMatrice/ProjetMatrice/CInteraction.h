#include <iostream>
#include <fstream>
#include "CString.h"
#include "CMatrice.h"
#include "CException.h"

using namespace std;

class CInteraction
{
private:
	/* récupérations des attributs de la matrice */
	int uiINTNbLignes;
	int uiINTNbColonnes;
	double **pINTTab;

	/* ce à quoi les lignes de fichier seront comparées */
	char pINTTypeMatriceCorrecte[19] = "TypeMatrice=double";
	char pINTLigneCorrecte[10] = "NBLignes=";
	char pINTColonneCorrecte[12] = "NBColonnes=";
	char pINTMatriceCorrecte[12] = "Matrice=[";
public:
	CInteraction();
	CInteraction(char *pNomFichier);
	CMatrice<double> INTGetMatrice(char *pNomFichier);
	int INTGetNbLignes();
	int INTGetNbColonnes();
	double **INTGetTab();
};


