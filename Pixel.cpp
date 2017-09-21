#include "Pixel.h"
#include "Const.h"
#include <iostream>
using namespace std;

// Constructeur par défaut.
Pixel::Pixel() {
	tauxRouge_ = 0;
	tauxVert_ = 0;
	tauxBleu_ = 0;
}

// Constructeur par paramètre.
Pixel::Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu) {
	tauxRouge_ = tauxRouge;
	tauxVert_ = tauxVert;
	tauxBleu_ = tauxBleu;
}

// Accesseur attributs
unsigned int Pixel::getTauxRouge() const {
	return tauxRouge_;
}
unsigned int Pixel::getTauxVert() const {
	return tauxVert_;
}
unsigned int Pixel::getTauxBleu() const {
	return tauxBleu_;
}

//****** Méthodes *******//

//modifie la teinte de rouge
void Pixel::modifierTeinteRouge(int incrementRouge) {
	if (((tauxRouge_ + incrementRouge) > MIN_CONCENTRATION_COULEUR) && ((tauxRouge_ + incrementRouge) < MAX_CONCENTRATION_COULEUR)) {
		tauxRouge_ = tauxRouge_ + incrementRouge;
	}
	else if (tauxRouge_ + incrementRouge <= MIN_CONCENTRATION_COULEUR) {
		tauxRouge_ = MIN_CONCENTRATION_COULEUR;
	}
	else {
		tauxRouge_ = MAX_CONCENTRATION_COULEUR;
	}
}

//modifie la teinte de vert
void Pixel::modifierTeinteVert(int incrementVert) {
	if ((tauxVert_ + incrementVert > MIN_CONCENTRATION_COULEUR) && (tauxVert_ + incrementVert < MAX_CONCENTRATION_COULEUR))
		tauxVert_ = tauxVert_ + incrementVert;
	else if (tauxVert_ + incrementVert < MIN_CONCENTRATION_COULEUR)
		tauxVert_ = MIN_CONCENTRATION_COULEUR;
	else
		tauxVert_ = MAX_CONCENTRATION_COULEUR;
}

//modifie la teinte de bleu
void Pixel::modifierTeinteBleu(int incrementBleu) {
	if (((tauxBleu_ + incrementBleu) > MIN_CONCENTRATION_COULEUR) && ((tauxBleu_ + incrementBleu) < MAX_CONCENTRATION_COULEUR)) {
		tauxBleu_ = tauxBleu_ + incrementBleu;
	}
	else if ((tauxBleu_ + incrementBleu) < MIN_CONCENTRATION_COULEUR) {
		tauxBleu_ = MIN_CONCENTRATION_COULEUR;
	}
	else {
		tauxBleu_ = MAX_CONCENTRATION_COULEUR;
	}
}

//affiche la couleur du pixel
void Pixel::afficherPixel() const {
	if ((tauxRouge_ > 0) && (tauxBleu_ == 0) && (tauxVert_ == 0)) {
		cout << "R";
	}
	else if ((tauxBleu_ > 0) && (tauxRouge_ == 0) && (tauxVert_ == 0)) {
		cout << "B";
	}
	else if ((tauxVert_ > 0) && (tauxBleu_ == 0) && (tauxRouge_ == 0)) {
		cout << "G";
	}
	else {
		cout << "X";
	}
}