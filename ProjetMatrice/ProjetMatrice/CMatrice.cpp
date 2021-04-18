/**
  * \fn inline CMatrice<MType>::CMatrice()
  * \brief constructeur par défaut
  */
template<class MType>
inline CMatrice<MType>::CMatrice()
{
	uiMATNbLignes = 1;
	uiMATNbColonnes = 1;
	pMATTableau = nullptr;
}

/**
  * \fn inline CMatrice<MType>::CMatrice(CMatrice &MATarg)
  * \brief constructeur de recopie
  * \param[in] MATarg : la matrice à recopier
  */
template<class MType>
inline CMatrice<MType>::CMatrice(CMatrice &MATarg)
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
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pMATTableau[uiBoucleLigne][uiBoucleColonne] = MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
}

/**
  * \fn inline CMatrice<MType>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes, MType** pTab)
  * \brief constructeur avec paramètres
  * \param[in] uiNbLignes : le nombre de lignes
  * \param[in] uiNbColonnes : le nombre de colonnes
  * \param[in] pTab : le tableau de 2D contenant les éléments de la matrice
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
  * \fn inline CMatrice<MType>::~CMatrice()
  * \brief destructeur
  */
template<class MType>
inline CMatrice<MType>::~CMatrice()
{
	unsigned int uiBoucleLigne;

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		delete[] pMATTableau[uiBoucleLigne];
	}
	delete[] pMATTableau;
}

/**
  * \fn inline CMatrice<MType> CMatrice<MType>::MATCalculerTranspose()
  * \brief calcul la transposé de la matrice
  * \return la transposé de la matrice
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
  * \fn inline void CMatrice<MType>::MATAfficherMatrice(char *pNomMatrice)
  * \brief permet de définir le nom de la matrice pour l'affichage
  * \param[in] pNomMatrice : le nom de la matrice
  * \return néant
  */
template<class MType>
inline void CMatrice<MType>::MATAfficherMatrice()
{
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	cout << "MAT = [\n";
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
  * \fn inline MType CMatrice<MType>::MATAvoirValeur(unsigned int uiChoixLigne, unsigned int uiChoixColonne)
  * \brief accesseur
  * \param[in] uiChoixLigne : le choix de la ligne 
  * \param[in] uiChoixColonne : le choix de la colonne
  * \return la valeur du tableau à la ligne uiChoixLigne et la colonne uiChoixColonne
  */
template<class MType>
inline MType CMatrice<MType>::MATAvoirValeur(unsigned int uiChoixLigne, unsigned int uiChoixColonne)
{
	return pMATTableau[uiChoixLigne][uiChoixColonne];
}


/**
  * \fn inline unsigned int CMatrice<MType>::MATGetNbLignes()
  * \brief accesseur de la classe
  * \return le nombre de lignes de la matrice
  */
template<class MType>
inline unsigned int CMatrice<MType>::MATGetNbLignes()
{
	return uiMATNbLignes;
}


/**
  * \fn inline unsigned int CMatrice<MType>::MATGetNbColonnes()
  * \brief accesseur de la classe
  * \return le nombre de colonnes de la matrice
  */
template<class MType>
inline unsigned int CMatrice<MType>::MATGetNbColonnes()
{
	return uiMATNbColonnes;
}


/**
  * \fn inline CMatrice<MType> CMatrice<MType>::operator*(const double valeur)
  * \brief surcharge opérateur * pour multiplier une matrice par un nombre
  * \param[in] valeur : la valeur pour laquelle on veut multiplier la matrice
  * \return le résultat de la matrice multipliée par la valeur
  */
template<class MType>
inline CMatrice<MType> CMatrice<MType>::operator*(const double valeur)
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
  * \fn inline CMatrice<MType> CMatrice<MType>::operator*(CMatrice &MATarg)
  * \brief surcharge opérateur * pour multiplier deux matrices
  * \param[in] MATarg : la matrice pour laquelle on veut multiplier la matrice
  * \return la multiplication des deux matrices
  */
template<class MType>
inline CMatrice<MType> CMatrice<MType>::operator*(CMatrice &MATarg)
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
			for (uiBoucleDimension = 0; uiBoucleDimension < uiDimension; uiBoucleDimension++)
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
  * \fn inline CMatrice<MType> CMatrice<MType>::operator/(const double valeur)
  * \brief surcharge opérateur / pour diviser une matrice par un nombre
  * \param[in] valeur : la valeur pour laquelle on veut diviser la matrice
  * \return le résultat de la matrice divisé par le nombre
  */
template<class MType>
inline CMatrice<MType> CMatrice<MType>::operator/(const double valeur)
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
  * \fn inline CMatrice<MType> CMatrice<MType>::operator+(CMatrice &MATarg)
  * \brief surcharge opérateur + pour additioner deux matrices
  * \param[in] MATarg : la matrice pour laquelle on veut additionner la première matrice
  * \return l'addition des deux matrices
  */
template<class MType>
inline CMatrice<MType> CMatrice<MType>::operator+(CMatrice &MATarg)
{
	if (uiMATNbColonnes == MATarg.uiMATNbColonnes && uiMATNbLignes == MATarg.uiMATNbLignes)
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
				pTab[uiBoucleLigne][uiBoucleColonne] = pMATTableau[uiBoucleLigne][uiBoucleColonne] + MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
			}
		}
		CMatrice MATaddition(uiMATNbLignes, uiMATNbColonnes, pTab);
		return MATaddition;
	}
	else
	{
		char pTexteException[61] = "Impossible d'additionner des matrices de taille différente\n";
		throw CException(Mat_Taille_diff, pTexteException);
	}

}

/**
  * \fn inline CMatrice<MType> CMatrice<MType>::operator-(CMatrice &MATarg)
  * \brief surcharge opérateur - pour soustraire deux matrices
  * \param[in] MATarg : la matrice pour laquelle on veut soustraire la première matrice
  * \return la soustraction des deux matrices
  */
template<class MType>
inline CMatrice<MType> CMatrice<MType>::operator-(CMatrice &MATarg)
{
	if (uiMATNbColonnes != MATarg.uiMATNbColonnes || uiMATNbLignes != MATarg.uiMATNbLignes)
	{
		char pTexteException[32] = "Matrice de taille différentes\n";
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


/**
  * \fn CMatrice<MType> CMatrice<MType>::operator=(CMatrice &&MATarg)
  * \brief surcharge de l'opérateur =
  * \param[in] MATarg : la matrice pour laquelle on veut appliquer l'opérateur =
  * \return opérateur d'auto-référencement
  */
template<class MType>
inline CMatrice<MType> CMatrice<MType>::operator=(CMatrice &&MATarg)
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
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pMATTableau[uiBoucleLigne][uiBoucleColonne] = MATarg.pMATTableau[uiBoucleLigne][uiBoucleColonne];
		}
	}
	return *this;

}


/**
  * \fn inline CMatrice<MType> operator*(const double Valeur, CMatrice<MType> &MATarg)
  * \brief commutateur de l'opérateur*
  * \param[in] Valeur : la constante
  * \param[in] MATarg : la matrice pour laquelle on veut multiplier la constante
  * \return inversion des valeurs (commutation)
  */
template<class MType>
inline CMatrice<MType> operator*(const double Valeur, CMatrice<MType> &MATarg)
{
	
	unsigned int uiMATNbLignes = MATarg.MATGetNbLignes();
	unsigned int uiMATNbColonnes = MATarg.MATGetNbColonnes();
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	MType** pTab = new MType*[uiMATNbLignes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		pTab[uiBoucleLigne] = new MType[uiMATNbColonnes];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			pTab[uiBoucleLigne][uiBoucleColonne] = Valeur * MATarg.MATAvoirValeur(uiBoucleLigne, uiBoucleColonne);
		}
	}

	CMatrice<MType> MATmultiplication(uiMATNbLignes, uiMATNbColonnes, pTab);
	
	return MATmultiplication;
}