/*
 * Tetrominos.h
 *
 *  Created on: 24 oct. 2024
 *      Author: Eliphée
 */

#ifndef TETROMINOS_H_
#define TETROMINOS_H_


#include "EcranLED.h"
#include "Constantes.h"

class Tetrominos {
protected:
	static int const TailleMatrice = 5;
	//La matrice contient des chars, qui vont nous permettre d'associer les couleurs des blocs
	//On utilise les char des couleurs en anglais car Vert et Violent commencent par la même lettre
	//c, y, v, o, b, r, g
	char MatricePiece[TailleMatrice][TailleMatrice];
	int PositionX;
	int PositionY;
public:
	Tetrominos(); //Constructeur d'un Tetrominos
	void RotationPiece();
	void AfficherPiece();

	static int GetTailleMatrice() { return TailleMatrice; }
	char GetMatricePiece(int y, int x) {return MatricePiece[y][x]; }


	void SetPositionX(int x);
	void SetPositionY(int y);
	int GetPositionX();
	int GetPositionY();

	bool operator == (const Tetrominos& autre) const; //On surcharge l'operateur == pour comparer deuxx pièce entre elles et voir si ce sont les mêmes

	bool PeutBouger(char Grille[32][8], int FuturePosX, int FuturePosY);

	virtual ~Tetrominos();
};

#endif /* TETROMINOS_H_ */
