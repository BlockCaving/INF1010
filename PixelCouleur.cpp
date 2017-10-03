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
}

PixelCouleur::~PixelCouleur() {

}

bool PixelCouleur::convertirPixelBN() const {
	if ((donnee_[R] + donnee_[G] + donnee_[B]) / 3 > 127) {
		return true;
	}
	else
		return false;
}

unchar PixelCouleur::convertirPixelGris() const {
	return (donnee_[R] + donnee_[G] + donnee_[B]) / 3;
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

bool PixelCouleur::operator==(const PixelCouleur& pixel) const {
	if (pixel.donnee_[R] == donnee_[R] && pixel.donnee_[G] == donnee_[G] && pixel.donnee_[B] == donnee_[B]) {
		return true;
	}
	else
	{
		return false;
	}
}