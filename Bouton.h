#ifndef BOUTON_H_
#define BOUTON_H_

#include <Arduino.h>
#include "Constantes.h"

class Bouton {
public:
    Bouton();
    void InitialiserBouton();
    int getEtatBouton();
};

#endif // BOUTON_H_
