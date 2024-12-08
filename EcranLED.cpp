#include "EcranLED.h"
#include <LedControl.h>

EcranLED::EcranLED() {
    for (int i = 0; i < LongueurMatrice; i++) {
        for (int j = 0; j < LargeurMatrice; j++) {
            MatriceAPrint[i][j] = '0';
        }
    }
    lc = nullptr;
}

void EcranLED::EcranLedInit() {
    // Use constants directly
    lc = new LedControl(PIN_IN, PIN_CLK, PIN_CS, 4);

    for (int i = 0; i < 4; i++) {
        lc->shutdown(i, false);
        lc->setIntensity(i, INTENSITE);
        lc->clearDisplay(i);
    }
}

void EcranLED::UpdateMatrice(char newMatrice[LongueurMatrice][LargeurMatrice]) {
    for (int i = 0; i < LongueurMatrice; i++) {
        for (int j = 0; j < LargeurMatrice; j++) {
            MatriceAPrint[i][j] = newMatrice[i][j];
        }
    }
}

void EcranLED::AfficherMatrice() {
    for (int i = 0; i < LongueurMatrice; i++) {
        for (int j = 0; j < LargeurMatrice; j++) {
            bool etatLED = (MatriceAPrint[i][j] != '0');
            SetPixel(i, j, etatLED);
        }
    }
}

void EcranLED::SetPixel(int ligne, int colonne, bool etat) {
    if (ligne < 0 || ligne >= LongueurMatrice || colonne < 0 || colonne >= LargeurMatrice) {
        return;
    }

    int moduleIndex = ligne / 8;       
    int localLigne = 7 - (ligne % 8); 
    lc->setLed(moduleIndex, colonne, localLigne, etat);
}

void EcranLED::testEcran() {
      char matTest[LongueurMatrice][LargeurMatrice] = {
    {'0', '0', '1', '0', '0', '1', '0', '0'},
    {'0', '1', '1', '1', '1', '1', '1', '0'},
    {'1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1'},
    {'0', '1', '1', '1', '1', '1', '1', '0'},
    {'0', '0', '1', '1', '1', '1', '0', '0'},
    {'0', '0', '0', '1', '1', '0', '0', '0'},
    {'0', '0', '0', '0', '1', '0', '0', '0'},

    {'0', '0', '1', '1', '1', '1', '0', '0'},
    {'0', '1', '0', '0', '0', '0', '1', '0'},
    {'1', '0', '1', '0', '0', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '0', '0', '1', '0', '1'},
    {'0', '1', '0', '1', '1', '0', '1', '0'},
    {'0', '0', '1', '1', '1', '1', '0', '0'},

    {'0', '0', '0', '0', '1', '0', '0', '0'},
    {'0', '0', '0', '1', '1', '0', '0', '0'},
    {'0', '0', '1', '1', '1', '0', '0', '0'},
    {'0', '1', '1', '1', '1', '1', '1', '1'},
    {'0', '0', '1', '1', '1', '0', '0', '0'},
    {'0', '0', '0', '1', '1', '0', '0', '0'},
    {'0', '0', '0', '0', '1', '0', '0', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '0'},

    {'0', '0', '0', '1', '0', '0', '0', '0'},
    {'0', '0', '1', '1', '1', '0', '0', '0'},
    {'0', '1', '1', '1', '1', '1', '0', '0'},
    {'1', '1', '1', '1', '1', '1', '1', '0'},
    {'0', '1', '1', '1', '1', '1', '0', '0'},
    {'0', '0', '1', '1', '1', '0', '0', '0'},
    {'0', '0', '0', '1', '0', '0', '0', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '0'}
};

    UpdateMatrice(matTest);
    AfficherMatrice();
}

EcranLED::~EcranLED() {
    if (lc != nullptr) {
        delete lc;
        lc = nullptr;
    }
}
