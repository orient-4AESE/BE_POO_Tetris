/*
 * TPiece.cpp
 *
 *  Created on: 24 oct. 2024
 *      Author: Eliphée
 */

#include "TPiece.h"

TPiece::TPiece() : Tetrominos() {
	MatricePiece[2][1] = 'V'; //V pour Violet
	MatricePiece[2][2] = 'V';
	MatricePiece[2][3] = 'V';
	MatricePiece[3][2] = 'V';
}

