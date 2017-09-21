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
	// Stockage des lignes de l'image.
	for (unsigned int j = 0; j < nombrePixelEnHauteur_; j++) {
		Pixel *pixelsTmp = pixels_[j];
		pixels_[j] = new Pixel[nombrePixelEnLargeur_ * 2];
		// Copie des colonnes de l'ancienne image sur la nouvelle.
		for (unsigned int i = 0; i < nombrePixelEnLargeur_ * 2; i++) {
			if (i < nombrePixelEnLargeur_) {
				pixels_[j][i] = pixelsTmp[i];
			}
			else {
				pixels_[j][i] = pixelsTmp[i - nombrePixelEnLargeur_];
			}
		}
	}
	nombrePixelEnLargeur_ = nombrePixelEnLargeur_ * 2;
}
void Image::doublerTailleEnHauteur() {
	// Stockage temporaire de l'image.
	Pixel **pixelsTmp = pixels_;
	// Création d'une nouvelle image hauteur * 2.
	pixels_ = new Pixel*[nombrePixelEnHauteur_ * 2];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_ * 2; i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	}
	// Copie de l'image précédente sur la nouvelle image.
	for (unsigned int j = 0; j < nombrePixelEnHauteur_ * 2; j++) {
		if (j < nombrePixelEnHauteur_) {
			for (unsigned int i = 0; i < nombrePixelEnLargeur_; i++) {
				pixels_[j][i] = pixelsTmp[j][i];
			}
		}
		else
		{
			for (unsigned int i = 0; i < nombrePixelEnLargeur_; i++) {
				pixels_[j][i] = pixelsTmp[j - nombrePixelEnHauteur_][i];
			}
		}
		}
	nombrePixelEnHauteur_ = 2 * nombrePixelEnHauteur_;
}
// Augmenter teinte pixel.
void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur) {
	if (couleur == 'G') 
		pixels_[positionHauteur - 1][positionLargeur - 1].modifierTeinteVert(increment);
	if (couleur == 'R') 
		pixels_[positionHauteur - 1][positionLargeur - 1].modifierTeinteRouge(increment);
	if (couleur == 'B') 
		pixels_[positionHauteur - 1][positionLargeur - 1].modifierTeinteBleu(increment);
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
	pixels_[positionHauteur][positionLargeur] = pixel;
}

Pixel Image::obtenirPixel(unsigned int positionLargeur, unsigned int positionHauteur) const {
	return pixels_[positionHauteur][positionLargeur];
}
