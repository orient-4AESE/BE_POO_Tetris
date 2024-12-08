/*
 * EcranLED.h
 *
 *  Created on: 27 nov. 2024
 *      Author: Eliphée
 */

#ifndef PIECES_ECRANLED_H_
#define PIECES_ECRANLED_H_

#include <LedControl.h> // Inclusion de la bibliothèque LedControl

#include "Constantes.h"


class EcranLED {
protected:
   
    char MatriceAPrint[LongueurMatrice][LargeurMatrice]; // Matrice à afficher
    LedControl* lc; // Pointeur vers un objet LedControl

public:
    EcranLED();
    void EcranLedInit();
    void UpdateMatrice(char newMatrice[LongueurMatrice][LargeurMatrice]);
    void AfficherMatrice();
    void SetPixel(int ligne, int colonne, bool etat);
    void testEcran();
    void eteindreEcran();
    virtual ~EcranLED();
};

#endif /* PIECES_ECRANLED_H_ */
