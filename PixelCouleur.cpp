#include "PixelCouleur.h"

// Constructeur par defaut
PixelCouleur::PixelCouleur() {
	donnee_[R] = 0;
	donnee_[G] = 0;
	donnee_[B] = 0;
}

// Constructeur par parametre
PixelCouleur::PixelCouleur(const unchar& r, const unchar& g, const unchar& b) {
	donnee_[R] = r;
	donnee_[G] = g;
	donnee_[B] = b;
	type_ = Couleur;
}

//Destructeur
PixelCouleur::~PixelCouleur() {
}

// Accesseurs
unchar PixelCouleur::retournerR() const {
	return donnee_[R];
}

unchar PixelCouleur::retournerG() const {
	return donnee_[G];
}

unchar PixelCouleur::retournerB() const {
	return donnee_[B];
}

//Mutateur
void PixelCouleur::modifierTeinteRouge(unchar d) {
	donnee_[R] = d;
}

void PixelCouleur::modifierTeinteVert(unchar d) {
	donnee_[G] = d;
}
void PixelCouleur::modifierTeinteBleue(unchar d) {
	donnee_[B] = d;
}

//*********** OPERATEURS *********//
//*****************************************************************************************
//Nom: == 
//Action: compare deux pixels et retrun true si ils sont identiques
//*****************************************************************************************
bool PixelCouleur::operator==(const PixelCouleur& pixel) const {
	if (pixel.donnee_[R] == donnee_[R] && pixel.donnee_[G] == donnee_[G] && pixel.donnee_[B] == donnee_[B]) {
		return true;
	}
	else
	{
		return false;
	}
}


//*********** Methodes *********//
//*****************************************************************************************
//Nom: convertirPixelBN
//Action: retrourne true si la moyenne des trois teinte du pixels est supérieur à 127
//Parametre:- void
//Retrun: bool
//*****************************************************************************************
bool PixelCouleur::convertirPixelBN() const {
	if (((donnee_[R] + donnee_[G] + donnee_[B]) / 3) > 127) {
		return true;
	}
	else
		return false;
}

//*****************************************************************************************
//Nom: convertirPixelGris
//Action: retrourne la moyenne des trois teinte du pixels
//Parametre:- void
//Retrun: unchar
//*****************************************************************************************
unchar PixelCouleur::convertirPixelGris() const {
	return ((donnee_[R] + donnee_[G] + donnee_[B]) / 3);
}
