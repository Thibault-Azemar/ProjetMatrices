#include "CInteraction.h"


CInteraction::CInteraction()
{

}

CInteraction::CInteraction(char *pNomFichier)
{
	ifstream fichier(pNomFichier, ios::in);  // on ouvre en lecture

	if (fichier)  // si l'ouverture a fonctionné
	{
		unsigned int uiCompteur = 0;
		unsigned int uiDebut = 0;
		char cCaractere = 'a';

		while (cCaractere != '\n')
		{
			fichier.get(cCaractere);
			if (cCaractere == '=')
				uiDebut = uiCompteur + 1;
			uiCompteur++;
		}
		CString CSTTest;
		//CSTTest.CSTExtraireChaine(uiDebut, uiCompteur);


		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}
