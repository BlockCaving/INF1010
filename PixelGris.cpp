#include "PixelGris.h"


//*****************************************************************************************
//		CODE FOURNIS
//*****************************************************************************************

PixelGris::PixelGris() {}

PixelGris::PixelGris(unsigned int donnee) {
	donnee_ = testPixel(donnee);
}

PixelGris::PixelGris(unchar donnee): donnee_(donnee) {}

PixelGris::~PixelGris() {}


bool PixelGris::convertirPixelBN() {
    if (donnee_ > 127) {
        return true;
    } else {
        return false;
    }
}

unchar PixelGris::convertirPixelGris() {
    return donnee_;
}

Pixel* PixelGris::retournerUneCopieProfonde() {
    PixelGris* copie = new PixelGris(donnee_);
    return copie;
}

unchar PixelGris::retournerR() const {
    return (unchar) donnee_;
}

unchar PixelGris::retournerG() const {
    return (unchar) donnee_;
}

unchar PixelGris::retournerB() const {
    return (unchar) donnee_;
}

void PixelGris::mettreEnNegatif() {
    donnee_ = -donnee_;
}

unchar PixelGris::obtenirDonnee() const {
    return donnee_;
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
bool PixelGris::estMajoriteRouge() const {
	return false;									//un pixel gris ne peut pas etre a majorité rouge
}

//*****************************************************************************************
//Nom: estMajoriteVert
//Action: methode constante qui retourne true si le pixel est à majorite vert.
//Parametre:- void
//Retrun: bool
//*****************************************************************************************
bool PixelGris::estMajoriteVert() const {
	return false;									//un pixel gris ne peut pas etre a majorité vert
}

//*****************************************************************************************
//Nom: estMajoriteBleu
//Action: methode constante qui retourne true si le pixel est à majorite bleu.
//Parametre:- void
//Retrun: bool
//*****************************************************************************************
bool PixelGris::estMajoriteBleu() const {
	return false;									//un pixel gris ne peut pas etre a majorité bleu
}

//*****************************************************************************************
//Nom: retournerIntensiteMoyenne
//Action: methode constante qui retourne un decimal entre 0 et 1 represantant l'intensité moyenne
//Parametre:- void
//Retrun: double
//*****************************************************************************************
double PixelGris::retournerIntensiteMoyenne() const {
	return donnee_/255.0;					//resultat entre 0 et 1
}