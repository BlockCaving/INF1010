#include "Image.h"
#include <iostream>
using namespace std;

// Constructeur par défaut
Image::Image() {
	nomImage_ ="";
	nombrePixelEnHauteur_ = 0;
	nombrePixelEnLargeur_ = 0;
	pixels_ = nullptr; 
}

// Constructeur par paramètre
Image::Image(const string& nomImage, unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur) {
	nomImage_ = nomImage;
	nombrePixelEnHauteur_ = nombrePixelHauteur;
	nombrePixelEnLargeur_ = nombrePixelLargeur;
	
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i=0; i < nombrePixelEnHauteur_; i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	};
}

// Destructeur
Image::~Image() {
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		delete pixels_[i];
		pixels_[i] = nullptr;
	};
}

// Acceseurs
string Image::getNomImage() const {
	return nomImage_;
}
unsigned int Image::getNombrePixelLargeur() const {
	return nombrePixelEnLargeur_;
}
unsigned int Image::getNombrePixelHauteur() const {
	return nombrePixelEnHauteur_;
}

// Muttateurs
void Image::modifierNomImage(const string & nomImage) {
	nomImage_ = nomImage;
}

//*********** Methodes *********//

// Doubler taille
void Image::doublerTailleEnLargeur() {
	nombrePixelEnLargeur_ = 2 * nombrePixelEnLargeur_;
}
void Image::doublerTailleEnHauteur() {
	nombrePixelEnHauteur_ = 2 * nombrePixelEnHauteur_;
}
// Augmenter teinte pixel.
void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur) {
	if (couleur == 'G') 
		pixels_[positionHauteur][positionLargeur].modifierTeinteVert(increment);
	if (couleur == 'R') 
		pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(increment);
	if (couleur == 'B') 
		pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(increment);
}

void Image::afficherImage() const
{
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++){
			pixels_[i][j].afficherPixel();
		};
		cout << "\n\r";
	};
}

void Image::ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur)
{
	pixels_[positionLargeur][positionHauteur] = pixel;
}

Pixel Image::obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const {
	return pixels_[positionLargeur][positionHauteur];
}
