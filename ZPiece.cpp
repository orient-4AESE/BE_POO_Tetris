/*
 * ZPiece.cpp
 *
 *  Created on: 24 oct. 2024
 *      Author: Eliphée
 */

#include "ZPiece.h"

ZPiece::ZPiece() : Tetrominos() {
	MatricePiece[2][1] = 'R'; //R pour Red
	MatricePiece[2][2] = 'R';
	MatricePiece[3][2] = 'R';
	MatricePiece[3][3] = 'R';

}
