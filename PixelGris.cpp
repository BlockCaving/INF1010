#include "PixelGris.h"

PixelGris::PixelGris() {
	donnee_ = 0;
}
// Constructeur par parametre
PixelGris::PixelGris(unsigned int donnee) {
	donnee_ = donnee;
	type_ = NuanceDeGris;
}

//Destructeur
PixelGris::~PixelGris() {
}

// Accesseur
unsigned int PixelGris::obtenirDonnee() const {
	return donnee_;
}

//*********** OPERATEURS *********//
//*****************************************************************************************
//Nom: == 
//Action: compare deux pixels et retrun true si ils sont identiques
//*****************************************************************************************
bool PixelGris::operator==(const PixelGris& pixel) const {
	if (pixel.donnee_ == donnee_)
		return true;
	else
		return false;
}

//*********** Methodes *********//
//*****************************************************************************************
//Nom: convertirPixelBN
//Action: retrourne true si donnee_ > 127, false sinon
//Parametre:- void
//Retrun: bool
//*****************************************************************************************
bool PixelGris::convertirPixelBN() const {
	if (donnee_ > 127)
		return true;
	else
		return false;
}

//*****************************************************************************************
//Nom: convertirPixelGris
//Action: retrourne un pointeur vers un tableau de 3 unchar de valeur donnee_
//Parametre:- void
//Retrun: unchar*
//*****************************************************************************************
unchar* PixelGris::convertirPixelCouleur() const {
	unchar rgb[3] = { donnee_, donnee_, donnee_ };
	return rgb;
}