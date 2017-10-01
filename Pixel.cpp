
#include "Pixel.h"
#include <iostream>
#include "Const.h"

using namespace std;

//Constructeur par défaut
Pixel::Pixel() : tauxRouge_(0),tauxVert_(0),tauxBleu_(0)
{
}

//Detructeur
Pixel::~Pixel()
{
}

//Construcuteur par paramètre
Pixel::Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu) :
	tauxRouge_(tauxRouge), tauxVert_(tauxVert), tauxBleu_(tauxBleu)
{
}

//Acceseur
unsigned int Pixel::obtenirTauxRouge() const {
	return tauxRouge_;
}
unsigned int Pixel::obtenirTauxVert() const {
	return tauxVert_;
}
unsigned int Pixel::obtenirTauxBleu() const {
	return tauxBleu_;
}

//*********** OPERATEURS *********//
//*****************************************************************************************
//Nom: << 
//Action: affiche un pixel
//fonciton globale
//*****************************************************************************************
ostream& operator<<(ostream& o, const Pixel& pixel) {
	unsigned int tauxR = pixel.obtenirTauxRouge();
	unsigned int tauxV = pixel.obtenirTauxVert();
	unsigned int tauxB = pixel.obtenirTauxBleu();

	if ((tauxV == 0) && (tauxB == 0) && (tauxR != 0)) {
		return o << "R";

	}
	else if ((tauxV != 0) && (tauxB == 0) && (tauxR == 0)) {
		return o << 'G';

	}
	else if ((tauxV == 0) && (tauxB != 0) && (tauxR == 0)) {
		return o << 'B';

	}
	// Optionnel, si on veut distinguer colore et completement noir
	/*
	else if (tauxR == 0 && tauxV == 0 && tauxB == 0){
	cout <<'O';
	}
	*/
	else {
		return o << 'Q';
	}
}


//*****************************************************************************************
//Nom: == 
//Action: compare deux pixel et retourne true si ils sont identiques
//*****************************************************************************************
bool Pixel::operator==(const Pixel& pixel) {
	if (tauxRouge_ == pixel.tauxRouge_ && tauxVert_ == pixel.tauxVert_ && tauxBleu_ == pixel.tauxBleu_) {
		return true;
	}
	else
	{
		return false;
	}
}

//*****************************************************************************************
//Nom: == 
//Action: compare un pixel avec une couleur et retourne true si est de cette couleur
//*****************************************************************************************
bool Pixel::operator==(char charac) {
	if (charac == 'R' && tauxVert_ == 0 && tauxBleu_ == 0 && tauxRouge_ != 0) {
		return true;

	}
	else if (charac == 'V' && tauxRouge_ == 0 && tauxBleu_ == 0 && tauxVert_ != 0) {
		return true;

	}
	else if (charac == 'B' && tauxRouge_ == 0 && tauxVert_ == 0 && tauxBleu_ != 0) {
		return true;

	}
	else
	{
		return false;
	}
}

//*****************************************************************************************
//Nom: == 
//Action: compare un pixel avec une couleur et retourne true si est de cette couleur (sens inversé)
//fonction globale
//*****************************************************************************************
bool operator==(char charac, const Pixel& pixel) {
	if (charac == 'R' && pixel.obtenirTauxVert() == 0 && pixel.obtenirTauxBleu() == 0 && pixel.obtenirTauxRouge() != 0) {
		return true;

	}
	else if (charac == 'V' && pixel.obtenirTauxVert() != 0 && pixel.obtenirTauxBleu() == 0 && pixel.obtenirTauxRouge() == 0) {
		return true;

	}
	else if (charac == 'B' && pixel.obtenirTauxVert() == 0 && pixel.obtenirTauxBleu() != 0 && pixel.obtenirTauxRouge() == 0) {
		return true;

	}
	else {
		return false;
	}
}

//****** Méthodes *******//

//*****************************************************************************************
//Nom: modifierTeinteRouge
//Action: modifie la teinte de rouge
//Parametre: - int incrementRouge pour augmenter au diminuer la teinte de rouge
//Retrun: Void
//*****************************************************************************************
void Pixel::modifierTeinteRouge(int incrementRouge) {
	if (incrementRouge < 0) {
		if (abs(incrementRouge) >= tauxRouge_) {
		    tauxRouge_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxRouge_ -= incrementRouge;
		}
	}
	else {
		unsigned int temp = tauxRouge_ + incrementRouge;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxRouge_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxRouge_ = temp;
		}
	}
}

//*****************************************************************************************
//Nom: modifierTeinteVert
//Action: modifie la teinte de vert
//Parametre: - int incrementRouge pour augmenter au diminuer la teinte de vert
//Retrun: Void
//*****************************************************************************************

void Pixel::modifierTeinteVert( int incrementVert) {
	if (incrementVert < 0) {
		if (abs(incrementVert) >= tauxVert_) {
		    tauxVert_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxVert_ -= incrementVert;
		}
	}
	else {
		unsigned int temp = tauxVert_ + incrementVert;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxVert_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxVert_ = temp;
		}
	}
}

//*****************************************************************************************
//Nom: modifierTeinteBleu
//Action: modifie la teinte de Bleu
//Parametre: - int incrementBleu pour augmenter au diminuer la teinte de Bleu
//Retrun: Void
//*****************************************************************************************
void Pixel::modifierTeinteBleu( int incrementBleu) {
	if (incrementBleu < 0) {
		if (abs(incrementBleu) >= tauxBleu_) {
		    tauxBleu_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxBleu_ -= incrementBleu;
		}
	}
	else {
		unsigned int temp = tauxBleu_ + incrementBleu;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxBleu_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxBleu_ = temp;
		}
	}
}