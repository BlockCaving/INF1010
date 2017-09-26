
#include "Pixel.h"
#include <iostream>
#include "Const.h"

using namespace std;

Pixel::Pixel() : tauxRouge_(0),tauxVert_(0),tauxBleu_(0)
{
}


Pixel::~Pixel()
{
}

Pixel::Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu) :
	tauxRouge_(tauxRouge), tauxVert_(tauxVert), tauxBleu_(tauxBleu)
{
}


unsigned int Pixel::obtenirTauxRouge() const {
	return tauxRouge_;
}
unsigned int Pixel::obtenirTauxVert() const {
	return tauxVert_;
}
unsigned int Pixel::obtenirTauxBleu() const {
	return tauxBleu_;
}

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




void Pixel::afficherPixel() const
{
	if (tauxVert_ == 0 && tauxBleu_ == 0 &&  tauxRouge_!=0) {
		cout << 'R';

	}
	else if (tauxRouge_ == 0 && tauxBleu_ == 0 && tauxVert_ != 0) {
		cout << 'G';

	}
	else if (tauxRouge_ == 0 && tauxVert_ == 0 && tauxBleu_ != 0) {
		cout << 'B';

	}
	// Optionnel, si on veut distinguer colore et completement noir
	/*
	else if (tauxRouge_ == 0 && tauxVert_ == 0 && tauxBleu_ == 0){
		cout <<'O';
	}
	*/
	else {
		cout << 'Q';
	}
}

ostream& operator<<(ostream& o, const Pixel& pixel) {
	if (pixel.obtenirTauxVert() == 0 && pixel.obtenirTauxBleu() == 0 && pixel.obtenirTauxRouge() != 0) {
		return o << "R";

	}
	else if (pixel.obtenirTauxVert() != 0 && pixel.obtenirTauxBleu() == 0 && pixel.obtenirTauxRouge() == 0) {
		return o << 'G';

	}
	else if (pixel.obtenirTauxVert() == 0 && pixel.obtenirTauxBleu() != 0 && pixel.obtenirTauxRouge() == 0) {
		return o << 'B';

	}
	// Optionnel, si on veut distinguer colore et completement noir
	/*
	else if (tauxRouge_ == 0 && tauxVert_ == 0 && tauxBleu_ == 0){
	cout <<'O';
	}
	*/
	else {
		return o << 'Q';
	}
}

bool Pixel::operator==(const Pixel& pixel) {
	if (tauxRouge_ == pixel.tauxRouge_ && tauxVert_ == pixel.tauxVert_ && tauxBleu_ == pixel.tauxBleu_) {
		return true;
	}
	else
	{
		return false;
	}
}

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