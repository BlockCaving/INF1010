/**************************************************
* Titre: Travail pratique #1 - GroupImage.cpp
* Date: Septembre 2017
* Auteur: Claude GAGNE - Steven NICOULEAU
**************************************************/

#include "GroupImage.h"
#include <iostream>
using namespace std;

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
	images_ = new Image[capaciteImages_];
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
//*****************************************************************************************
//Nom: doublerTailleImageEnLargeur
//Action: double la largeur de l'image dont l'indice est passé en parametre
//Parametre:- unsigned int indiceImage
//Retrun: void
//*****************************************************************************************
void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnLargeur();
}

//*****************************************************************************************
//Nom: doublerTailleImageEnHauteur
//Action: double la hauteur de l'image dont l'indice est passé en parametre
//Parametre:- unsigned int indiceImage
//Retrun: void
//*****************************************************************************************
void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnHauteur();
}

//*****************************************************************************************
//Nom: ajouterImage
//Action: ajoute l'image passé en en parametre dans le groupe d'image si la capcitée le permet
//Parametre:- Image &image
//Retrun: void
//*****************************************************************************************
void GroupImage::ajouterImage(const Image &image) {
	if (nombreImages_ < capaciteImages_) {
		images_[nombreImages_] = image;
		nombreImages_++;
	}
	else
		cout << "Le groupe d'image est plein!" <<endl;
}

//*****************************************************************************************
//Nom: afficherImages
//Action: affiche l'image qui appelle la methode
//Parametre:- void
//Retrun: void
//*****************************************************************************************
void GroupImage::afficherImages() const{
	for (unsigned int i = 0; i < nombreImages_; i++) {
		images_[i].afficherImage();
	}
}