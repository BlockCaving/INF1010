
#include "GroupImage.h"
#include <iostream>
#include <vector>


using namespace std;

GroupImage::GroupImage():nombreImages_(1),capaciteImages_(1) {
	images_.push_back(new Image());
}

GroupImage::~GroupImage() {
	for (unsigned int i = 0; i < nombreImages_; i++) {
		delete images_[i];
	}
	images_.clear();
	capaciteImages_ = 0;
	nombreImages_ = 0;
}

GroupImage::GroupImage(const string & type,unsigned int capaciteImages): type_(type), capaciteImages_(capaciteImages) {
	for (unsigned int i = 0; i < capaciteImages_; i++) {
		images_.push_back(new Image());
	}
	nombreImages_ = 0;
}

void GroupImage::modifierType(const string & type) {
	type_ = type;
}

string GroupImage::obtenirType() const{
	return type_;
}

unsigned int GroupImage::obtenirNombreImages() const {
	return nombreImages_;
}

void GroupImage::ajouterImage(const Image& image) {
	bool flagErreur = false;								//= true si l'image ajouté a le nom d'une image du groupe
	for (unsigned int i = 0; i <= nombreImages_; i++) {
		if (*images_[i] == image.obtenirNomImage()) {
			flagErreur = true;
		}
	}
	if ((nombreImages_ < capaciteImages_) && (flagErreur==false)) {		
		*images_[nombreImages_] = image;
		nombreImages_++;					//update nombreImages_
		cout << image.obtenirNomImage().c_str() << " a bien ete ajoute" << endl;
	}
	else 
		cout << "Erreur le nom de l'image est deja utilise ou la capacite du groupe est depasse!";
}

void GroupImage::afficherImages() const {

	cout << "*********************************************" << endl;
	cout << "Affichage des images du groupe :  ";
	cout << obtenirType().c_str() << endl;
	cout << "*********************************************"<< endl;
	
	for (unsigned int i = 0; i < nombreImages_; i++) {
		cout << *images_[i];
		cout << "---------------------------------------------" << endl;
	}
	cout << endl;
}

Image GroupImage::obtenirImage(unsigned int indiceImage) const {
	return *images_[indiceImage];
}

void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	(*images_[indiceImage]).doublerTailleEnLargeur();
}

void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	(*images_[indiceImage]).doublerTailleEnHauteur();
}
 