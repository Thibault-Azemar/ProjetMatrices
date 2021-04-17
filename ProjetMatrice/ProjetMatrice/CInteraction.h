#include "CString.h"
#include "CMatrice.h"


class CInteraction
{
private:
	/* r�cup�rations des attributs de la matrice */
	unsigned int uiINTNbLignes;
	unsigned int uiINTNbColonnes;
	double **pINTTab;

	/* ce � quoi les lignes de fichier seront compar�es */
	char pINTTypeMatriceCorrecte[19] = "TypeMatrice=double";
	char pINTLigneCorrecte[10] = "NBLignes=";
	char pINTColonneCorrecte[12] = "NBColonnes=";
	char pINTMatriceCorrecte[12] = "Matrice=[";
public:
	CInteraction();
	CMatrice<double> INTGetMatrice(char *pNomFichier);
};


