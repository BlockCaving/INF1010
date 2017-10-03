#include "PixelBN.h"

// Constructeur par defaut
PixelBN::PixelBN() {
	donnee_ = false;
}

// Constructeur par parametres
PixelBN::PixelBN(bool p) {
	donnee_ = p;
}

PixelBN::~PixelBN() {

}

unchar PixelBN::convertirPixelGris() const{
	if (donnee_)
		return 255;
	else
		return 0;
}

unchar* PixelBN::convertirPixelCouleur() const {
	if (donnee_) {
		unchar rgb[3] = { 255,255,255 };
		return rgb;
	}
	else {
		unchar rgb[3] = { 0,0,0 };
		return rgb;
	}
}

bool PixelBN::operator==(const PixelBN& pixel) const {
	if (pixel.donnee_ == donnee_)
		return true;
	else
		return false;
}
// Accesseur
bool PixelBN::obtenirDonnee() const {
    // Todo
    return true;
}