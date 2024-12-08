/*
 * GestionJeu.h
 *
 *  Created on: 28 oct. 2024
 *      Author: Eliphée
 */

#ifndef PIECES_GESTIONJEU_H_
#define PIECES_GESTIONJEU_H_

#include "IPiece.h"
#include "JPiece.h"
#include "LPiece.h"
#include "OPiece.h"
#include "SPiece.h"
#include "ZPiece.h"
#include "TPiece.h"

#include "EcranLED.h"
#include "Constantes.h"
#include "Grille.h"
#include "Tetrominos.h"
#include "EcranLED.h"

class GestionJeu {
protected:
	Grille GrillePartie;
	Tetrominos* PieceActuelle = nullptr;
	bool FinDePartie = false;
  EcranLED Ecran; // Instance de l'écran LED
public:

   // Add this accessor function to initialize or modify Ecran
  void InitEcran() { Ecran.EcranLedInit(); }
	GestionJeu();
	void GenererPieces();
	void AfficherJeu();
	void InitialiserJeuEtEcran();
	void FixerPieceActuelle();
  
  Grille& GetGrillePartie() { return GrillePartie; }


	bool GetFinDePartie() { return FinDePartie; }
	void TerminerPartie() { FinDePartie = true; }

  bool PieceActuellePeutBouger();

	void TournerPiece(); //Uniquement pour le test
	void GravitePiece();//Pour le test
  void DeplacementLateral( int direction );
};

#endif /* PIECES_GESTIONJEU_H_ */
