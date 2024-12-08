/*
 * OPiece.cpp
 *
 *  Created on: 24 oct. 2024
 *      Author: Eliphée
 */

#include "OPiece.h"

OPiece::OPiece() : Tetrominos() {
	MatricePiece[3][2] = 'Y'; //Y pour Yellow
	MatricePiece[3][3] = 'Y';
	MatricePiece[2][2] = 'Y';
	MatricePiece[2][3] = 'Y';

}
