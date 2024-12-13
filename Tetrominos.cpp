
#include "Tetrominos.h"

#include <Arduino.h> // Pour Serial

EcranLED Ecran; // Instance globale pour gérer l'écran LED

// Constructeur
Tetrominos::Tetrominos() {
    // Remplit une matrice 5x5 de '0'
    for (int i = 0; i < TailleMatrice; i++) {
        for (int j = 0; j < TailleMatrice; j++) {
            MatricePiece[i][j] = '0';
        }
    }
    PositionX = 0; // Position par rapport à la grille
    PositionY = 0; // Utilisé pour l'affichage final
}

// Destructeur
Tetrominos::~Tetrominos() {}

int Tetrominos::GetPositionX() {
    return PositionX;
}

int Tetrominos::GetPositionY() {
    return PositionY;
}

void Tetrominos::SetPositionX(int x) {
    PositionX = x;
}

void Tetrominos::SetPositionY(int y) {
    PositionY = y;
}

// Overloading de l'opérateur == pour comparer deux pièces entre elles
bool Tetrominos::operator==(const Tetrominos& autre) const {
    // Compare les matrices des deux pièces
    for (int i = 0; i < TailleMatrice; i++) {
        for (int j = 0; j < TailleMatrice; j++) {
            if (MatricePiece[i][j] != autre.MatricePiece[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Rotation de la matrice 5x5 de 90 degrés
void Tetrominos::RotationPiece() {
    // Initialise la matrice temporaire
    char TempMatrice[TailleMatrice][TailleMatrice];

    for (int i = 0; i < TailleMatrice; i++) {
        for (int j = 0; j < TailleMatrice; j++) {
            TempMatrice[i][j] = '0';
        }
    }

    // Effectue la rotation dans le sens horaire
    for (int i = 0; i < TailleMatrice; i++) {
        for (int j = 0; j < TailleMatrice; j++) {
            TempMatrice[j][TailleMatrice - i - 1] = MatricePiece[i][j];
        }
    }

    // Copie la matrice temporaire dans MatricePiece
    for (int i = 0; i < TailleMatrice; i++) {
        for (int j = 0; j < TailleMatrice; j++) {
            MatricePiece[i][j] = TempMatrice[i][j];
        }
    }
}

// Vérifie si la pièce peut bouger vers une position donnée
bool Tetrominos::PeutBouger(char Grille[LongueurGrille][LargeurGrille], int FuturePosX, int FuturePosY) {
    for (int i = 0; i < TailleMatrice; i++) {
        for (int j = 0; j < TailleMatrice; j++) {
            if (MatricePiece[i][j] != '0') { // Vérifie les "pixels" du bloc
                int NouvellePosX = j + FuturePosX;
                int NouvellePosY = i + FuturePosY;

                if (NouvellePosX < 0 || NouvellePosX >= 8 || NouvellePosY < 0 || NouvellePosY >= 32) {
                    return false; // Hors de la grille
                }
                if (Grille[NouvellePosY][NouvellePosX] != '0') {
                    return false; // Collision avec une autre pièce
                }
            }
        }
    }
    return true; // Toutes les positions sont valides
}
