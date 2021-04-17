#include "CString.h"
#include "CMatrice.h"


class CInteraction
{
private:
	/* récupérations des attributs de la matrice */
	unsigned int uiINTNbLignes;
	unsigned int uiINTNbColonnes;
	double **pINTTab;

	/* ce à quoi les lignes de fichier seront comparées */
	char pINTTypeMatriceCorrecte[19] = "TypeMatrice=double";
	char pINTLigneCorrecte[10] = "NBLignes=";
	char pINTColonneCorrecte[12] = "NBColonnes=";
	char pINTMatriceCorrecte[12] = "Matrice=[";
public:
	CInteraction();
	CMatrice<double> INTGetMatrice(char *pNomFichier);
};


