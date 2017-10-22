#include "PixelBN.h"

// Constructeur par defaut
PixelBN::PixelBN() {
	donnee_ = false;
}

// Constructeur par parametres
PixelBN::PixelBN(bool p) {
	donnee_ = p;
	type_ = NoireBlanc;
}

//Destructeur
PixelBN::~PixelBN() {
}

// Accesseur
bool PixelBN::obtenirDonnee() const {
	return donnee_;
}

//*********** OPERATEURS *********//
//*****************************************************************************************
//Nom: == 
//Action: compare deux pixels et retrun true si ils sont identiques
//*****************************************************************************************
bool PixelBN::operator==(const PixelBN& pixel) const {
	if (pixel.donnee_ == donnee_)
		return true;
	else
		return false;
}

//*********** Methodes *********//
//*****************************************************************************************
//Nom: convertirPixelGris
//Action: retrourne 255 pour un pixel blanc, 0 pour un pixel noir
//Parametre:- void
//Retrun: unchar
//*****************************************************************************************
unchar PixelBN::convertirPixelGris() const{
	if (donnee_)
		return 255;
	else
		return 0;
}

//*****************************************************************************************
//Nom: convertirPixelCouleur
//Action: retrourne  un pointeur vers un tableau de trois unchar de valeur 255 pour un pixel blanc,et de valeur 0 pour un pixel noir
//Parametre:- void
//Retrun: unchar*
//*****************************************************************************************
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