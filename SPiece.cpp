/*
 * SPiece.cpp
 *
 *  Created on: 24 oct. 2024
 *      Author: Eliphée
 */

#include "SPiece.h"

SPiece::SPiece() : Tetrominos() {
	MatricePiece[3][1] = 'G'; //G pour Greeen
	MatricePiece[3][2] = 'G';
	MatricePiece[2][2] = 'G';
	MatricePiece[2][3] = 'G';
}
