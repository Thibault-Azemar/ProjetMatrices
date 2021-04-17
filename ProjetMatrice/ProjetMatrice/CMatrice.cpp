/**
 * @brief construteur par défaut
 */
template<class MType>
inline CMatrice<MType>::CMatrice()
{
	uiMATNbLignes = 1;
	uiMATNbColonnes = 1;
	pMATTableau = nullptr;
}

/**
 * @brief constructeur de recopie
 * @param MATarg
 */
template<class MType>
inline CMatrice<MType>::CMatrice(CMatrice *MATarg)
{
	uiMATNbLignes = MATarg.uiMATNbLignes;
	uiMATNbColonnes = MATarg.uiMATNbColonnes;
	pMATTableau = new MType*[MATarg.uiMATNbLignes];
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	for (uiBoucleLigne; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pMATTableau[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pMATTableau[uiBoucleLigne][uiBoucleColonne] = MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
}

/**
 * @brief constructeur avec paramètre
 * @param uiNbLignes
 * @param uiNbColonnes
 * @param pTab
 */
template<class MType>
inline CMatrice<MType>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes, MType** pTab)
{
	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;
	pMATTableau = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pMATTableau[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pMATTableau[uiBoucleLigne][uiBoucleColonne] = pTab[uiBoucleLigne][uiBoucleColonne];
		}
	}
}

/**
 * @brief destructeur
 */
template<class MType>
inline CMatrice<MType>::~CMatrice()
{
	/*
	unsigned int uiBoucleLigne = uiMATNbLignes;

	for (uiBoucleLigne ; uiBoucleLigne > 0; uiBoucleLigne--)
	{
			delete[] pMATTableau[uiBoucleLigne];
	}
	delete[] pMATTableau;*/
}

/**
 * @brief calcule de la transposé de la matrice
 * @return
 */
template<class MType>
inline CMatrice<MType> CMatrice<MType>::MATCalculerTranspose()
{
	if (uiMATNbColonnes != uiMATNbLignes)
	{
		char pTexteException[19] = "Matrice non carré\n";
		throw CException(Mat_Non_Carre, pTexteException);
	}

	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleColonne][uiBoucleLigne];
		}
	}
	CMatrice MATTranspose(uiMATNbLignes, uiMATNbColonnes, pTab);

	return MATTranspose;
}

/**
 * @brief permet de définir le nom de la matrice pour l'affichage
 * @param pnomMatrice
 */
template<class MType>
inline void CMatrice<MType>::MATAfficherMatrice(char *pNomMatrice)
{
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	cout << pNomMatrice << " = [\n";
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			cout << pMATTableau[uiBoucleLigne][uiBoucleColonne] << "\t ";
		}
		cout << endl;
	}
	cout << " ]\n" << endl;
}

/**
 * @brief Modifier une valeur de la matrice sans passer par le fichier (fonction pour les test)
 * @param uiChoixLigne
 * @param uiChoixColonne
 * @param valeur
 */
template<class MType>
inline void CMatrice<MType>::MATModifValeur(unsigned int uiChoixLigne, unsigned int uiChoixColonne, MType valeur)
{
	if (uiChoixLigne > uiMATNbLignes || uiChoixColonne > uiMATNbColonnes)
	{
		char pTexteException[37] = "Choix en dehors de la taille de la matrice\n";
		throw CException(Mat_Taille_diff, pTexteException);
	}
	pMATTableau[uiChoixLigne - 1][uiChoixColonne - 1] = valeur;
}

/**
 * @brief surcharge opérateur *
 * @param rNombre
 * @return
 */
template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator*(MType valeur)
{
	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = valeur * pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATmultiplication(uiMATNbLignes, uiMATNbColonnes, pTab);

	return MATmultiplication;
}


/**
 * @brief deuxième surcharge opérateur *
 * @param MATarg
 * @return
 */
template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator*(CMatrice MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbLignes)
	{
		char pTexteException[74] = "Nb Colonnes de la 1ère matrice différent du Nb Lignes de la 2eme matrice\n";
		throw CException(Mat_Taille_diff, pTexteException);
	}
	unsigned int uiDimension = uiMATNbColonnes;

	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;
	unsigned int uiBoucleDimension;

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[MATarg.uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			MType temp = 0;
			for (uiBoucleDimension = 0 ; uiBoucleDimension < uiDimension; uiBoucleDimension++)
			{
				temp += this->pMATTableau[uiBoucleLigne][uiBoucleDimension] * MATarg.pMATTableau[uiBoucleDimension][uiBoucleColonne];
			}
			pTab[uiBoucleLigne][uiBoucleColonne] = temp;
		}
	}

	CMatrice MATmultiplication(uiMATNbLignes, uiMATNbColonnes, pTab);

	return MATmultiplication;
}

/**
 * @brief surcharge opérateur /
 * @param rNombre
 * @return
 */
template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator/(MType valeur)
{
	if (valeur == 0)
	{
		char pTexteException[21] = "Division impossible\n";
		throw CException(Valeur_Non_Valide, pTexteException);
	}

	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new double[uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] / valeur;
		}
	}
	CMatrice MATdivision(uiMATNbLignes, uiMATNbColonnes, pTab);

	return MATdivision;
}

/**
 * @brief surcharge opérateur +
 * @param MATarg
 * @return
 */
template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator+(CMatrice MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbColonnes || uiMATNbLignes != MATarg.uiMATNbLignes)
	{
		char pTexteException[59] = "Impossible d'additionner des matrices de taille différente\n";
		throw CException(Mat_Taille_diff, pTexteException);
	}

	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] + MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATaddition(uiMATNbLignes, uiMATNbColonnes, pTab);

	return MATaddition;

}


/**
 * @brief surcharge opérateur -
 * @param MATarg
 * @return
 */
template<class MType>
inline CMatrice<MType> & CMatrice<MType>::operator-(CMatrice MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbColonnes || uiMATNbLignes != MATarg.uiMATNbLignes)
	{
		char pTexteException[29] = "Matrice de taille différentes\n";
		throw CException(Mat_Taille_diff, pTexteException);
	}

	MType** pTab = new MType*[uiMATNbLignes];
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] - MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	CMatrice MATsoustraction(uiMATNbLignes, uiMATNbColonnes, pTab);

	return MATsoustraction;
}
