#include "GroupImage.h"

// Constructeur par défaut
GroupImage::GroupImage() {
	type_ = "";
	nombreImages_ = 0;
	capaciteImages_ = 0;
	images_ = new Image[capaciteImages_];
}

// Constructeur par paramètre
GroupImage::GroupImage(const string &type, unsigned int capaciteImages) {
	type_ = type;
	capaciteImages_ = capaciteImages;
	nombreImages_ = 0;
	images_ = nullptr;
	images_ = new Image[capaciteImages];
}

// Destructeur
GroupImage::~GroupImage() {
	delete [] images_;
	images_ = nullptr;
}

//Accesseurs
string GroupImage::obtenirType() const {
	return type_;
}
unsigned int GroupImage::obtenirNombreImages() const {
	return nombreImages_;
}
Image GroupImage::obtenirImage(unsigned int indiceImage) const {
	return images_[indiceImage];
}

//Mutateur
void GroupImage::modifierType(const string &type) {
	type_ = type;
}

//******** Méthodes **********//

void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnLargeur();
}
void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnHauteur();
}


void GroupImage::ajouterImage(const Image &image) {
	//if (nombreImages_ < capaciteImages_) {
		images_[nombreImages_] = image;
		nombreImages_++;
	//}
	//else
	//{
	//	cout << "Le groupe d'image est plein!";
	//}
}

void GroupImage::afficherImages() const{
	for (unsigned int i = 0; i < nombreImages_; i++) {
		images_[i].afficherImage();
	}
}