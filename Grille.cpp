#include <Arduino.h> // Pour Serial.print
#include "Grille.h"

Grille::Grille() {
    // Initialise une grille vide
    for (int i = 0; i < LongueurMatrice; i++) {
        for (int j = 0; j < LargeurMatrice; j++) {
            MatriceGrille[i][j] = '0';
        }
    }
}


void Grille::VerifierLignePleine() {
    for (int i = 0; i < LongueurMatrice; i++) {
        // Vérifie si une ligne est complète
        bool LignePleine = true;
        for (int j = 0; j < LargeurMatrice; j++) {
            if (MatriceGrille[i][j] == '0') {
                LignePleine = false;
                break;
            }
        }
        if (LignePleine) {
            ViderLignePleine(i); // Appelle la fonction pour vider la ligne
        }
    }
}

void Grille::ViderLignePleine(int Ligne) {
    Serial.print("La ligne ");
    Serial.print(Ligne);
    Serial.println(" est pleine, il faut la vider");

    for (int j = 0; j < LargeurMatrice; j++) {
        MatriceGrille[Ligne][j] = '0';
    }

    GraviteLignePleine(Ligne);
}

void Grille::GraviteLignePleine(int Ligne) {
    Serial.println("On fait tomber les lignes du dessus");

    // Fait descendre les lignes au-dessus de la ligne effacée
    for (int i = Ligne; i > 0; i--) {
        for (int j = 0; j < LargeurMatrice; j++) {
            MatriceGrille[i][j] = MatriceGrille[i - 1][j];
        }
    }

    // Remplit la première ligne avec des '0'
    for (int j = 0; j < LargeurMatrice; j++) {
        MatriceGrille[0][j] = '0';
    }

    Serial.println("Fin gravite");
}

void Grille::ViderGrille() {
    for (int i = 0; i < LongueurMatrice; i++) {
        for (int j = 0; j < LargeurMatrice ; j++) {
            MatriceGrille[i][j] = '0';
        }
    }
}

char Grille::GetElementMatriceGrille(int y, int x) const {
    return MatriceGrille[y][x];
}

void Grille::SetElementMatriceGrille(int y, int x, char caractere) {
    MatriceGrille[y][x] = caractere;
}

Grille::~Grille() {
    // Rien à libérer car pas d'allocation dynamique
}
