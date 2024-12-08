/*
 * EcranLED.h
 *
 *  Created on: 27 nov. 2024
 *      Author: Eliphée
 */

#ifndef ROUTINETETRIS_H_
#define ROUTINETETRIS_H_

#include "GestionJeu.h"
#include "Joystick.h"
#include "Bouton.h"

class RoutineTetris {
protected:
  GestionJeu partieEnCours;
  Joystick joystick;
  Bouton bouton;
public:
    RoutineTetris();
    void PartieTetris();
    virtual ~RoutineTetris();
};

#endif /* ROUTINETETRIS_H_ */
