/*
 * main.cpp
 *
 *  Created on: 24 oct. 2024
 *      Author: Eliphée
 */
//Dans powershell utiliser [Console]::OutputEncoding = [System.Text.Encoding]::UTF8 pour voir des carrés
//g++ -o Tetris main.cpp LPiece.cpp SPiece.cpp JPiece.cpp OPiece.cpp TPiece.cpp IPiece.cpp ZPiece.cpp Grille.cpp GestionJeu.cpp Tetrominos.cpp
//pour build
/*
#include "Tetrominos.h"

#include "LPiece.h"
#include "SPiece.h"
#include "JPiece.h"
#include "OPiece.h"
#include "TPiece.h"
#include "IPiece.h"
#include "ZPiece.h"

#include "Grille.h"

#include "GestionJeu.h"

#include <chrono> //A mettre dans gestion Jeu, utilisée pour le test

#include <thread> //A mettre dans gestion Jeu, utilisée pour le test


#include <iostream>

using namespace std;

int main () {

/*	//Test L Piece
	LPiece L;
	L.AfficherPiece();
	cout << endl;

	//Test S Piece
	SPiece S;
	S.AfficherPiece();
	cout << endl;

	//Test J Piece
	JPiece J;
	J.AfficherPiece();
	cout << endl;

	//Test O Piece
	OPiece O;
	O.AfficherPiece();
	cout << endl;

	//Test I Piece
	IPiece I;
	I.AfficherPiece();
	cout << endl;

	//Test T Piece
	TPiece T;
	T.AfficherPiece();
	cout << endl;

	//Test Z Piece
	ZPiece Z;
	Z.AfficherPiece();
	cout << endl;

	//Test rotation
	cout << "*************" << endl;
	cout << "Test Rotation" << endl;
	cout << "*************" << endl;
	I.AfficherPiece();
	cout << endl;
	I.RotationPiece();
	cout << endl;
	I.AfficherPiece();
	cout << endl;
	I.RotationPiece();
	cout << endl;
	I.AfficherPiece();
	cout << endl;
	I.RotationPiece();
	cout << endl;
	I.AfficherPiece();
	cout << endl;

	//Test de la grille
	cout << "*************" << endl;
	cout << "Test Grille" << endl;
	cout << "*************" << endl;

	Grille GrilleTest; //Création de la grille de test

	//On compelete une ligne pour les diverses methodes de la classe Grille
	GrilleTest.DefinirLigneNonPleine(0, 'Q');
	GrilleTest.DefinirLigneNonPleine(3, 'Z');
	GrilleTest.DefinirLigneNonPleine(4, 'R');
	GrilleTest.DefinirLignePleine(5, '#');
	GrilleTest.DefinirLigneNonPleine(6, '9');
	GrilleTest.AfficherGrille();
	GrilleTest.VerifierLignePleine();
	GrilleTest.AfficherGrille();
*/
	//Test de Gestion Jeu
/*	cout << "*************" << endl;
	cout << "Test Gestion Jeu" << endl;
	cout << "*************" << endl;
*/
/*
	GestionJeu Partie;
	Partie.InitialiserJeu();
	Partie.GenererPieces();
	Partie.AfficherJeu();

	//On fait une boucle for qui tourne pendant 30 secondes
    auto debut_temps = chrono::steady_clock::now();
    auto temps_precedent = debut_temps;

	while (chrono::steady_clock::now() - debut_temps < chrono::seconds(8)) {
		auto maintenant = chrono::steady_clock::now();
		if (chrono::duration_cast<chrono::milliseconds>(maintenant - temps_precedent).count() >= 500) {

		            Partie.GravitePiece();
		            Partie.AfficherJeu(); // Afficher l'état après chaque rotation
		            temps_precedent = maintenant; // Mettre à jour le temps précédent
		        }
	}

	Partie.FixerPieceActuelle();
	Partie.GenererPieces();
	//On fait une boucle for qui tourne pendant 30 secondes
    auto debut_temps2 = chrono::steady_clock::now();
    auto temps_precedent2 = debut_temps2;

	while (chrono::steady_clock::now() - debut_temps2 < chrono::seconds(8)) {
		auto maintenant2 = chrono::steady_clock::now();
		if (chrono::duration_cast<chrono::milliseconds>(maintenant2  - temps_precedent2).count() >= 500) {

		            Partie.GravitePiece();
		            Partie.AfficherJeu(); // Afficher l'état après chaque rotation
		            temps_precedent2 = maintenant2; // Mettre à jour le temps précédent
		        }

	}
	Partie.FixerPieceActuelle();
	Partie.GenererPieces();
	//On fait une boucle for qui tourne pendant 30 secondes
    auto debut_temps3 = chrono::steady_clock::now();
    auto temps_precedent3 = debut_temps3;

	while (chrono::steady_clock::now() - debut_temps3 < chrono::seconds(8)) {
		auto maintenant3 = chrono::steady_clock::now();
		if (chrono::duration_cast<chrono::milliseconds>(maintenant3  - temps_precedent3).count() >= 500) {

		            Partie.GravitePiece();
		            Partie.AfficherJeu(); // Afficher l'état après chaque rotation
		            temps_precedent3	 = maintenant3; // Mettre à jour le temps précédent
		        }

	}
	Partie.AfficherJeu();
	Partie.FixerPieceActuelle();



/*	cout << "Rotation Piece" << endl;
	Partie.TournerPiece();
	Partie.AfficherJeu();
	for (int i = 0 ; i < 20 ; i++) {
		Partie.GravitePiece();
	}
	Partie.FixerPieceActuelle();
	Partie.GenererPieces();
	for (int i = 0 ; i < 20 ; i++) {
		Partie.GravitePiece();
	}
	Partie.FixerPieceActuelle();

	Partie.GenererPieces();
	for (int i = 0 ; i < 20 ; i++) {
		Partie.GravitePiece();
	}
	Partie.FixerPieceActuelle();


	Partie.GenererPieces();
	for (int i = 0 ; i < 20 ; i++) {
		Partie.GravitePiece();
	}
	Partie.FixerPieceActuelle();

	Partie.GenererPieces();
	for (int i = 0 ; i < 20 ; i++) {
		Partie.GravitePiece();
	}
	Partie.FixerPieceActuelle();

	Partie.AfficherJeu();
*/
/*
	return 0;
}



*/













