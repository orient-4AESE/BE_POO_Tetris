  #include "GestionJeu.h"

  #include <Arduino.h>

  GestionJeu::GestionJeu() {
      randomSeed(analogRead(4)); // Initialisation pour la génération aléatoire
      //Serial.begin(9600);
      //Serial.print("Test Random");
  }

  void GestionJeu::InitialiserJeuEtEcran() {
      GrillePartie.ViderGrille(); // Vide la grille
      PieceActuelle = new Tetrominos(); // Réinitialise la pièce
      Ecran.EcranLedInit(); // Initialise l'écran LED avec des broches
      Ecran.UpdateMatrice(GrillePartie.GetMatriceGrille()); // Met à jour l'écran
  }

  void GestionJeu::GenererPieces() {
    //On verifie avant de liberer de la mémoire, que la piece existe
    if (PieceActuelle != nullptr) {
      delete PieceActuelle; //On libère la mémoire utilisé par l'ancienne pièce
    }
      // Génère une pièce aléatoire
      int pieceType = random(1, 8); // Entre 1 et 7 inclus
      //Serial.println(pieceType);
      switch (pieceType) {
          case 1: PieceActuelle = new TPiece(); break;
          case 2: PieceActuelle = new IPiece(); break;
          case 3: PieceActuelle = new LPiece(); break;
          case 4: PieceActuelle = new SPiece(); break;
          case 5: PieceActuelle = new ZPiece(); break;
          case 6: PieceActuelle = new OPiece(); break;
          case 7: PieceActuelle = new JPiece(); break;
      }

    int PositionInitialeX = 2;
    int PositionInitialeY = 0;

    if (PieceActuelle->PeutBouger(GrillePartie.GetMatriceGrille(), PositionInitialeX, PositionInitialeY) == true) {
    PieceActuelle->SetPositionX(PositionInitialeX); //2 pour centrer la pièce
    PieceActuelle->SetPositionY(PositionInitialeY); //On met -2 car toutes les matrices des blocs non bougés on les deux premières lignes vides
    }
    else {
      TerminerPartie();
    }
  }

  bool GestionJeu::PieceActuellePeutBouger() {

    return (PieceActuelle->PeutBouger(GrillePartie.GetMatriceGrille(), PieceActuelle->GetPositionX(), PieceActuelle->GetPositionY()));

  }

  void GestionJeu::FixerPieceActuelle() {
    //On crée une matrice copie de la matrice de la grille
    char GrilleTemp[GrillePartie.GetLongueurGrille()][GrillePartie.GetLargeurGrille()];

    //On copie la grille dans la Matrice temporaire
    for (int i = 0 ; i < GrillePartie.GetLongueurGrille() ; i++) {
      for (int j = 0 ; j < GrillePartie.GetLargeurGrille() ; j++) {
        GrilleTemp[i][j] = GrillePartie.GetElementMatriceGrille(i,j);
      }
    }

    if (PieceActuelle) { //Pour éviter les éventuels problèmes, on vérifie qu'une PieceActuelle est existante
      //On récupère l'offset qu'a la piece par rapport à la grille
      int OffsetX = PieceActuelle->GetPositionX();
      int OffsetY = PieceActuelle->GetPositionY();

      //On vérifie que positionner la pièce ne crée pas de collisions
      if (PieceActuelle->PeutBouger(GrillePartie.GetMatriceGrille(), OffsetX, OffsetY)) {
        //On ajoute la pièce dans la grille temporaire
        for (int i = 0 ; i < PieceActuelle->GetTailleMatrice() ; i++) {
          for (int j = 0 ; j< PieceActuelle->GetTailleMatrice() ; j++) {
            //On regarde si l'élement de la matrice est un bloc d'une pièce ou non
            if (PieceActuelle->GetMatricePiece(i,j) != '0') {
              int PosGrilleX = OffsetX + j; //On indique dans une variable l'offset par rapport a la grille
              int PosGrilleY = OffsetY + i;


              GrilleTemp[PosGrilleY][PosGrilleX] = PieceActuelle->GetMatricePiece(i,j);
            }
          }
        }
      }
    }
    //On actualise la grille de la partie avec la grille temporaire
    for (int i = 0 ; i < GrillePartie.GetLongueurGrille() ; i++) {
      for (int j = 0 ; j < GrillePartie.GetLargeurGrille() ; j++) {
        GrillePartie.SetElementMatriceGrille(i,j, GrilleTemp[i][j]);
      }
    }

      // Met à jour l'écran LED
      //Ecran.UpdateMatrice(GrillePartie.GetMatriceGrille());
      //Ecran.AfficherMatrice();
  }

  void GestionJeu::AfficherJeu() {
    //On crée une matrice copie de la matrice de la grille
    char GrilleTemp[LongueurMatrice][LargeurMatrice];

    //On copie la grille dans la Matrice temporaire
    for (int i = 0 ; i < GrillePartie.GetLongueurGrille() ; i++) {
      for (int j = 0 ; j < GrillePartie.GetLargeurGrille() ; j++) {
        GrilleTemp[i][j] = GrillePartie.GetElementMatriceGrille(i,j);
      }
    }

    if (PieceActuelle) { //Pour éviter les éventuels problèmes, on vérifie qu'une PieceActuelle est existante
      //On récupère l'offset qu'a la piece par rapport à la grille
      int OffsetX = PieceActuelle->GetPositionX();
      int OffsetY = PieceActuelle->GetPositionY();

      //On vérifie que positionner la pièce ne crée pas de collisions
      if (PieceActuelle->PeutBouger(GrillePartie.GetMatriceGrille(), OffsetX, OffsetY)) {
        //On ajoute la pièce dans la grille temporaire
        for (int i = 0 ; i < PieceActuelle->GetTailleMatrice() ; i++) {
          for (int j = 0 ; j< PieceActuelle->GetTailleMatrice() ; j++) {
            //On regarde si l'élement de la matrice est un bloc d'une pièce ou non
            if (PieceActuelle->GetMatricePiece(i,j) != '0') {
              int PosGrilleX = OffsetX + j; //On indique dans une variable l'offset par rapport a la grille
              int PosGrilleY = OffsetY + i;


              GrilleTemp[PosGrilleY][PosGrilleX] = PieceActuelle->GetMatricePiece(i,j);
            }
          }
        }
      }
    }
      // Met à jour l'écran LED
      Ecran.UpdateMatrice(GrilleTemp);
      Ecran.AfficherMatrice();
  }

  void GestionJeu::GravitePiece() {
      // Fait tomber la pièce si possible
    int PositionActuelleX = PieceActuelle->GetPositionX();
    int PositionActuelleY = PieceActuelle->GetPositionY();
    int PositionFutureGraviteY = PositionActuelleY +1;

      if (PieceActuelle->PeutBouger(GrillePartie.GetMatriceGrille(), PositionActuelleX, PositionFutureGraviteY)) {
          PieceActuelle->SetPositionY(PositionFutureGraviteY);
      } else {
          FixerPieceActuelle(); // Fixe la pièce si elle ne peut plus tomber
          GenererPieces();
      }
  }

  void GestionJeu::DeplacementLateral(int direction) {
    //On récupère la position actuelle de la pièce
    int PositionActuelleX = PieceActuelle->GetPositionX();
    int PositionActuelleY = PieceActuelle->GetPositionY();
    int PositionFutureDeplacementX = 0; //On initialise à 0, comme ca si aucun if n'est vérifié, la pièce ne bouge pas latéralement

    if (direction == -1 ) { //Si direction = -1 on va à gauche
      PositionFutureDeplacementX = PositionActuelleX -1;
    }
    else if (direction == 1) { //Si direction = 1 on va à droite
      PositionFutureDeplacementX = PositionActuelleX +1;
    } //Dans les autres cas on laisse la pièce la ou elle est

    if (PieceActuelle->PeutBouger(GrillePartie.GetMatriceGrille(), PositionFutureDeplacementX, PositionActuelleY)) {
      PieceActuelle->SetPositionX(PositionFutureDeplacementX);
    }

  }

  void GestionJeu::TournerPiece() {
      PieceActuelle->RotationPiece(); // Tourne la pièce
      if (!PieceActuelle->PeutBouger(GrillePartie.GetMatriceGrille(), PieceActuelle->GetPositionX(), PieceActuelle->GetPositionY())) {
          // Annule la rotation si elle crée une collision
          PieceActuelle->RotationPiece(); // Deux rotations supplémentaires annulent la première
          PieceActuelle->RotationPiece();
      }
  }
