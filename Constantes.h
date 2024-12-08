// Constants.h
#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <Arduino.h>

static const int LargeurMatrice = 8;  // Largueur de la matrice de LED
static const int LongueurMatrice = 32; // Longueur de la matrice de LED

static const int LargeurGrille = 8;  // Largueur de la matrice de LED
static const int LongueurGrille = 32; // Longueur de la matrice de LED

// Définition des pins pour LedControl
static const int PIN_IN = 11;
static const int PIN_CS = 10;
static const int PIN_CLK = 9;
static const int INTENSITE = 1;

// Définition de l'IO pour le Joystick
static const int JoystickAxeX = A0;

//Définition de la pin pour le bouton
static const int pinBouton = 2;

#endif
