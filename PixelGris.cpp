#include "PixelGris.h"

PixelGris::PixelGris() {
	donnee_ = 0;
}
// Constructeur par parametre
PixelGris::PixelGris(unsigned int donnee) {
	donnee_ = donnee;
}

PixelGris::~PixelGris() {

}

bool PixelGris::convertirPixelBN() const {
	if (donnee_ > 127)
		return true;
	else
		return false;
}

unchar* PixelGris::convertirPixelCouleur() const {
	unchar rgb[3] = { donnee_, donnee_, donnee_ };
	return rgb;
}

bool PixelGris::operator==(const PixelGris& pixel) const {
	if (pixel.donnee_ == donnee_)
		return true;
	else
		return false;
}
// Accesseur
unsigned int PixelGris::obtenirDonnee() const {
    return donnee_;
}