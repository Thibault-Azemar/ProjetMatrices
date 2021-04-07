#include "CMatrice.h"

CMatrice::CMatrice()
{
	nNombreLignes = 0;
	nNombreColonnes = 0;
	pTableau = nullptr;
}

CMatrice::CMatrice(unsigned int nNbLignes, unsigned int nNbColonnes, double **pTab)
{
	nNombreLignes = nNbLignes;
	nNombreColonnes = nNbColonnes;
	pTableau = new double*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTableau[nI] = new double[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTableau[nI][nJ] = pTab[nI][nJ];
		}
	}
}

CMatrice::~CMatrice()
{

}

CMatrice CMatrice::MATCalculerTranspose()
{
	double** pTab = new double*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTab[nI] = new double[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTableau[nJ][nI] = pTab[nI][nJ];
		}
	}
	CMatrice MAT1(nNombreColonnes, nNombreLignes, pTab);
	return MAT1;
}

CMatrice & CMatrice::operator+(CMatrice MATarg)
{
	if (nNombreColonnes != MATarg.nNombreColonnes || nNombreLignes != MATarg.nNombreLignes)
	{
		cout << "Impossible d'additionner ces deux matrices." << endl;
		return;
	}
	double** pTab = new double*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTab[nI] = new double[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTab[nI][nJ] = pTableau[nI][nJ] + MATarg.pTableau[nI][nJ];
		}
	}
	CMatrice MATaddition(nNombreColonnes, nNombreLignes, pTab);
	return MATaddition;
}

CMatrice & CMatrice::operator-(CMatrice MATarg)
{
	if (nNombreColonnes != MATarg.nNombreColonnes || nNombreLignes != MATarg.nNombreLignes)
	{
		cout << "Impossible d'additionner ces deux matrices." << endl;
		return;
	}
	double** pTab = new double*[nNombreColonnes];
	for (unsigned int nI = 0; nI < nNombreColonnes; nI++)
		pTab[nI] = new double[nNombreLignes];

	for (unsigned int nI = 0; nI < nNombreLignes; nI++)
	{
		for (unsigned int nJ = 0; nJ < nNombreColonnes; nJ++)
		{
			pTab[nI][nJ] = pTableau[nI][nJ] - MATarg.pTableau[nI][nJ];
		}
	}
	CMatrice MATsoustraction(nNombreColonnes, nNombreLignes, pTab);
	return MATsoustraction;
}