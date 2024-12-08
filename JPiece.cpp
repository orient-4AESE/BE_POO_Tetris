/*
 * JPiece.cpp
 *
 *  Created on: 24 oct. 2024
 *      Author: Eliphée
 */

#include "JPiece.h"

JPiece::JPiece() : Tetrominos() {
	MatricePiece[3][3] = 'B'; //B pour Blue
	MatricePiece[2][1] = 'B';
	MatricePiece[2][2] = 'B';
	MatricePiece[2][3] = 'B';
}
