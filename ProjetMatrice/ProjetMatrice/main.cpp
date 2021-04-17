#include "CInteraction.h"


/**
  * \fn int main()
  * \brief fonction principale testant la librairie
  */
int main()
{	
	char fichier1[14] = "matrice.txt";
	char nomMatrice1[5] = "MAT1";
	CMatrice<double> MAT1;
	try 
	{
		CInteraction Objet1;
		MAT1 = Objet1.INTGetMatrice(fichier1);
	}
	catch (CException EXCLevee)
	{
		cout << EXCLevee.EXCAvoirDesc();
	}
	MAT1.MATAfficherMatrice(nomMatrice1);
	

	char fichier2[15] = "matrice2.txt";
	char nomMatrice2[5] = "MAT2";
	CMatrice<double> MAT2;
	try {
		CInteraction Objet2;
		MAT2 = Objet2.INTGetMatrice(fichier2);
	}
	catch (CException EXCLevee)
	{
		cout << EXCLevee.EXCAvoirDesc();
	}
	MAT2.MATAfficherMatrice(nomMatrice2);


	char nomMatrice3[5] = "MAT3";
	CMatrice<double> MAT3;
	try
	{
		MAT3 = MAT1 * MAT2;
	}
	catch (CException EXCLevee)
	{
		cout << EXCLevee.EXCAvoirDesc();
	}
	MAT3.MATAfficherMatrice(nomMatrice3);

	char nomMatrice4[5] = "MAT4";
	CMatrice<double> MAT4;
	try
	{
		MAT4 = MAT1 + MAT3 - MAT1 + MAT2 - MAT1;
		MAT4.MATAfficherMatrice(nomMatrice4);
	}
	catch (CException EXCLevee)
	{
		cout << EXCLevee.EXCAvoirDesc();
	}

	char nomMatrice5[5] = "MAT5";
	CMatrice<double> MAT5;
	try
	{
		MAT5 = MAT1 * 5;
		MAT5.MATAfficherMatrice(nomMatrice5);
	}
	catch (CException EXCLevee)
	{
		cout << EXCLevee.EXCAvoirDesc();
	}
}
