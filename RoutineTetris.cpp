
#include "RoutineTetris.h" // Include the header file


RoutineTetris::RoutineTetris() {
  partieEnCours.InitialiserJeuEtEcran();
  bouton.InitialiserBouton();
  partieEnCours.GenererPieces(); //On genère la première pièce de notre jeu
}

void RoutineTetris::PartieTetris() {
  

  while (partieEnCours.GetFinDePartie() == false) { //La partie continue
    partieEnCours.AfficherJeu();
    partieEnCours.GravitePiece();

    //Vérification Bouton pour pièce tournée
    
    if (bouton.getEtatBouton() == 1) {
      partieEnCours.TournerPiece();
    }
  
    
    //Verification si déplacement latéral de la piece 
    if (joystick.obtenirDirection() == -1) {
      partieEnCours.DeplacementLateral(1);

    } 
    else if (joystick.obtenirDirection() == 1) { //Par rapport au branchement du bouton il est plus convenient d'inverser gauche et droite

      partieEnCours.DeplacementLateral(-1);

    }

    //On vérifie si il y a une ligne pleine
    partieEnCours.GetGrillePartie().VerifierLignePleine();

    //Delay permettant d'ajuster la vitesse de jeu
    delay(5);
    }
    //On sort du while, la partie est finie
    partieEnCours.TerminerPartie();


  }




RoutineTetris::~RoutineTetris() {
  
}
