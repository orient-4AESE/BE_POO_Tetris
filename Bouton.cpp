
#include "Bouton.h"

Bouton::Bouton() {}

void Bouton::InitialiserBouton () {
  pinMode(pinBouton, INPUT);
  Serial.begin(9600);
}

int Bouton::getEtatBouton () {
  Serial.println(digitalRead(pinBouton));
  return (digitalRead(pinBouton));
}

