#include "PixelBN.h"


PixelBN::PixelBN() {
	donnee_ = false;
}

PixelBN::PixelBN(bool p) {
	donnee_ = p;
}

PixelBN::~PixelBN() {}

unchar PixelBN::convertirPixelGris() {
    if(donnee_) {
        return VALEUR_MAX_PIXEL;
    } else {
        return VALEUR_MIN_PIXEL;
    }
}

bool PixelBN::convertirPixelBN() {
	return donnee_;
}

Pixel* PixelBN::retournerUneCopieProfonde() {
	PixelBN *copie = new PixelBN(donnee_);
	return copie;
}

bool PixelBN::obtenirDonnee() {
	return donnee_;
}

unchar PixelBN::retournerR() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

unchar PixelBN::retournerG() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

unchar PixelBN::retournerB() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

void PixelBN::mettreEnNegatif() {
    donnee_ = !donnee_;
}

//*****************************************************************************************
//		CODE NON FOURNIS
//*****************************************************************************************

//*****************************************************************************************
//Nom: estMajoriteRouge
//Action: methode constante qui retourne true si le pixel est à majorite rouge.
//Parametre:- void
//Retrun: bool
//*****************************************************************************************
bool PixelBN::estMajoriteRouge() const {
	return false;									//un pixel noir ou blanc ne peut pas etre a majorité rouge
}

//*****************************************************************************************
//Nom: estMajoriteVert
//Action: methode constante qui retourne true si le pixel est à majorite vert.
//Parametre:- void
//Retrun: bool
//*****************************************************************************************
bool PixelBN::estMajoriteVert() const {
	return false;									//un pixel noir ou blanc ne peut pas etre a majorité vert
}

//*****************************************************************************************
//Nom: estMajoriteBleu
//Action: methode constante qui retourne true si le pixel est à majorite bleu.
//Parametre:- void
//Retrun: bool
//*****************************************************************************************
bool PixelBN::estMajoriteBleu() const {
	return false;									//un pixel noir ou blanc ne peut pas etre a majorité bleu
}

//*****************************************************************************************
//Nom: retournerIntensiteMoyenne
//Action: methode constante qui retourne un decimal soit 0 soit 1 represantant l'intensité moyenne
//Parametre:- void
//Retrun: double
//*****************************************************************************************
double PixelBN::retournerIntensiteMoyenne() const {
	if (donnee_) {
		return 1;					//si pixel blanc
	}
	else {
		return 0;					//si pixel noir
	}
}