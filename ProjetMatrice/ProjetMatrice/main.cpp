#include "CInteraction.h"


int main()
{	
	char fichier[14] = "matrice.txt";
	char nomMatrice1[5] = "MAT1";
	CMatrice<double> MAT1;
	try 
	{
		CInteraction Objet1;
		MAT1 = Objet1.INTGetMatrice(fichier);
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
/*
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

	CMatrice<double> MATObjet2(uiLigne, uiColonne, pTab2);
	char nomMatrice1[5] = "MAT1";
	MATObjet2.MATAfficherMatrice(nomMatrice1);
	CMatrice<double> MATObjet3(MATObjet2);
	char nomMatrice2[5] = "MAT2";
	MATObjet.MATModifValeur(1, 2, 5);
	MATObjet.MATModifValeur(1, 1, 6);
	MATObjet.MATModifValeur(2, 1, -1);
	MATObjet.MATModifValeur(1, 3, 9);
	MATObjet.MATCalculerTranspose();
	CMatrice<double> MATobj5;
	
	try {
		MATobj5 = MATObjet2 * MATObjet;
	}
	catch (CException EXCLevee)
	{
		cout << EXCLevee.EXCavoir_desc();
	}
	try {
		MATobj5.MATModifValeur(7,7,5);
	}
	catch (CException EXCLevee)
	{
		cout << EXCLevee.EXCavoir_desc();
	}
	char nomMatrice5[5] = "MAT5";
	MATobj5.MATAfficherMatrice(nomMatrice5);
	MATObjet3.MATAfficherMatrice(nomMatrice2);

	//CMatrice<double> MATobj4 = MATObjet *3;
	*/
}
