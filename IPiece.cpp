/*
 * IPiece.cpp
 *
 *  Created on: 24 oct. 2024
 *      Author: Eliphée
 */

#include "IPiece.h"

IPiece::IPiece() : Tetrominos() {
	MatricePiece[2][0] = 'C'; //C pour Cyan
	MatricePiece[2][1] = 'C';
	MatricePiece[2][2] = 'C';
	MatricePiece[2][3] = 'C';
}
