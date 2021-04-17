#include "CException.h"


/**
  * \fn CException::CException()
  * \brief constructeur par défaut
  */
CException::CException()
{
	uiEXCValeur = 0;
	pEXCDesc = nullptr;
}

/**
  * \fn CException::CException(CException *EXPobj)
  * \brief constructeur de recopie
  * \param[in] EXPObj : l'objet à recopier
  */
CException::CException(CException *EXPobj)
{
	uiEXCValeur = EXPobj->uiEXCValeur;
	pEXCDesc = EXPobj->pEXCDesc;
}

/**
  * \fn CException::CException(unsigned int uiValeur, char* pDesc)
  * \brief constructeur avec paramètres
  * \param[in] uiValeur : la valeur de l'exception
  * \param[in] pEXCDesc : la description de l'exception
  */
CException::CException(unsigned int uiValeur, char* pDesc)
{
	uiEXCValeur = uiValeur;
	pEXCDesc = pDesc;
}

/**
  * CException::~CException()
  * \brief destructeur
  */
CException::~CException()
{
}

/**
  * \fn void CException::EXCModifierDesc(char* pDesc)
  * \brief permet de modifier la description
  * \param[in] pEXCDesc : la description de l'exception
  * \return néant
  */
void CException::EXCModifierDesc(char* pDesc)
{
	pEXCDesc = pDesc;
}

/**
  * \fn void CException::EXCModifierValeur(unsigned int uiValeur)
  * \brief permet de modifier la valeur
  * \param[in] uiValeur : la valeur de l'exception
  * \return néant
  */
void CException::EXCModifierValeur(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}

/**
  * \fn unsigned int CException::EXCAvoirValeur()
  * \brief permet de récupérer la valeur
  * \return la valeur de l'exception
  */
unsigned int CException::EXCAvoirValeur()
{
	return uiEXCValeur;
}

/**
  * \fn char* CException::EXCAvoirDesc()
  * \brief permet de récupérer la description
  * \return la description de l'exception
  */
char* CException::EXCAvoirDesc()
{
	return this->pEXCDesc;
}
