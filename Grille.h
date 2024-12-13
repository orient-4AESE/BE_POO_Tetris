/*
 * Grille.h
 *
 *  Created on: 25 oct. 2024
 */

#ifndef GRILLE_H_
#define GRILLE_H_

#include "Constantes.h"


class Grille {
protected:
	//static int const LargeurGrille = 8;
	//static int const LongueurGrille = 32;
	char MatriceGrille[LongueurMatrice][LargeurMatrice];
public:
	Grille();

	char GetElementMatriceGrille(int y, int x) const;
	void SetElementMatriceGrille(int y, int x, char caractere);

	static int GetLargeurGrille() { return LargeurMatrice; };
	static int GetLongueurGrille() { return LongueurMatrice; };

	char (*GetMatriceGrille())[LargeurMatrice] { return MatriceGrille; } //Trouvé sur StackOverflow, un peu du mal à comprendre la syntaxe

	void ViderGrille();

	void VerifierLignePleine();
	void ViderLignePleine(int Ligne);
	void GraviteLignePleine(int Ligne); //Fait "tomber" d'un bloc les lignes au dessus de la ligne que l'on vient d'effacer

	void DeplacerPiece();
	virtual ~Grille();
};

#endif /* GRILLE_H_ */
