#include "CInteraction.h"

CMatrice CInteraction::ITELireFichier(char *sFichier)
{
	std::ifstream fichier(sFichier);

	if (fichier)
	{
		// Lecture du fichier

		int *pListeEntiers = nullptr;
		unsigned int nNbEntiers;
		unsigned int nCount = 0;

		while (!fichier.eof()) // Tant qu'on n'est pas à la fin, on lit
		{
			std::string sLigne;
			fichier >> sLigne;
			if (nCount == 0) // nombre d'entiers
			{
				nNbEntiers = std::strtol(sLigne.data(), nullptr, 10);
				pListeEntiers = new int[nNbEntiers];
			}
			else // liste d'entiers séparés par un espace
			{
				pListeEntiers[nCount - 1] = std::strtol(sLigne.data(), nullptr, 10);
			}
			nCount++;
		}
	}
	else
	{
		std::cout << "Erreur : impossible d'ouvrir le fichier " << sNomFichier << std::endl;
		return;
	}
	return CMatrice();
}
