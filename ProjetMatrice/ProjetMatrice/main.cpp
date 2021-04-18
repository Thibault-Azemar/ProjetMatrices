#include "CInteraction.h"


/**
  * \fn int main()
  * \brief fonction principale testant la librairie
  */
int main(int argc, char* argv[])
{
	const int NbMatrices = argc - 1;

	if (NbMatrices > 0)
	{
		CMatrice<double> *TableauMatrices = new CMatrice<double>[NbMatrices];
		int NbBoucle;
		CMatrice<double> MAT;

		try
		{
			for (NbBoucle = 0; NbBoucle < NbMatrices; NbBoucle++)
			{
				CInteraction Objet1;
				TableauMatrices[NbBoucle] = Objet1.INTGetMatrice(argv[NbBoucle + 1]);
			}
		}
		catch (CException EXCLevee)
		{
			cout << EXCLevee.EXCAvoirDesc();
		}

		cout << "Rentrez une valeur c." << endl;
		double c;
		cin >> c;

		cout << "Resultat de la multiplication de chaque matrice par " << c << " :" << endl;
		try
		{
			for (NbBoucle = 0; NbBoucle < NbMatrices; NbBoucle++)
			{
				MAT = c * TableauMatrices[NbBoucle];
				MAT.MATAfficherMatrice();
				cout << endl;
			}
		}
		catch (CException EXCLevee)
		{
			cout << EXCLevee.EXCAvoirDesc();
		}

		cout << "Resultat de la division de chaque matrice par " << c << " :" << endl;
		try
		{
			for (NbBoucle = 0; NbBoucle < NbMatrices; NbBoucle++)
			{
				MAT = TableauMatrices[NbBoucle] / c;
				MAT.MATAfficherMatrice();
				cout << endl;
			}
		}
		catch (CException EXCLevee)
		{
			cout << EXCLevee.EXCAvoirDesc();
		}
		if (NbMatrices > 1)
		{
			cout << "Resultat de l'addition de chaques matrices :" << endl;
			try
			{
				CMatrice<double> MAT = TableauMatrices[0];
				for (NbBoucle = 1; NbBoucle < NbMatrices; NbBoucle++)
				{
					MAT = MAT + TableauMatrices[NbBoucle];
				}
				MAT.MATAfficherMatrice();
				cout << endl;
			}
			catch (CException EXCLevee)
			{
				cout << EXCLevee.EXCAvoirDesc();
			}

			cout << "Resultat de l'operation M1 - M2 + M3 ... :" << endl;
			try
			{
				CMatrice<double> MAT = TableauMatrices[0];
				for (NbBoucle = 1; NbBoucle < NbMatrices; NbBoucle++)
				{
					if (NbBoucle % 2 == 0)
					{
						MAT = MAT + TableauMatrices[NbBoucle];
					}
					else
					{
						MAT = MAT - TableauMatrices[NbBoucle];
					}
				}
				MAT.MATAfficherMatrice();
				cout << endl;
			}
			catch (CException EXCLevee)
			{
				cout << EXCLevee.EXCAvoirDesc();
			}

			cout << "Resultat de la multiplication de chaques matrices :" << endl;
			try
			{
				CMatrice<double> MAT = TableauMatrices[0];
				for (NbBoucle = 1; NbBoucle < NbMatrices; NbBoucle++)
				{
					MAT = MAT * TableauMatrices[NbBoucle];
				}
				MAT.MATAfficherMatrice();
				cout << endl;
			}
			catch (CException EXCLevee)
			{
				cout << EXCLevee.EXCAvoirDesc();
			}
		}
		else
		{
			cout << "Saissisez plusieurs fichiers pour faire les operations entre plusieurs matrices." << endl;

		}
		delete[] TableauMatrices;
		return 0;
	}
	cout << "Veuillez saisir le nom de fichier" << endl;
	return 1;
}
