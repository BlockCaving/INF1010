/**************************************************
* Titre: Travail pratique #1 - Image.cpp
* Date: Septembre 2017
* Auteur: Claude GAGNE - Steven NICOULEAU
**************************************************/

#include "Image.h"
#include <iostream>
#include <string>
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
	
	//création de l'image par tableau dynamique de pointeur
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i=0; i < nombrePixelEnHauteur_; i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	};
}

// Destructeur
Image::~Image() {
	//destruction de tout les pointeur
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
Pixel Image::obtenirPixel(unsigned int positionLargeur, unsigned int positionHauteur) const {
	return pixels_[positionHauteur][positionLargeur];
}

// Muttateurs
void Image::modifierNomImage(const string & nomImage) {
	nomImage_ = nomImage;
}

//*********** Methodes *********//

//*****************************************************************************************
//Nom: doublerTailleEnLargeur
//Action: double la taille en largeur
//Parametre: - void
//Retrun: void
//*****************************************************************************************
void Image::doublerTailleEnLargeur() {

	for (unsigned int j = 0; j < nombrePixelEnHauteur_; j++) {
		// Stockage la lignes de l'image et son contenu
		Pixel *pixelsTmp = pixels_[j];
		//creation des colones suplementaire
		pixels_[j] = new Pixel[nombrePixelEnLargeur_ * 2];
		// Copie des colonnes de l'ancienne image sur la nouvelle.
		for (unsigned int i = 0; i < nombrePixelEnLargeur_; i++) {
				//recuperation des pixels de l'anciene image
				pixels_[j][i] = pixelsTmp[i];
		};
		//suprime le pointeur servant de buffer
		delete pixelsTmp;
		pixelsTmp = nullptr;
	};
	//mise a jour du nombre de pixel en largeur
	nombrePixelEnLargeur_ = nombrePixelEnLargeur_ * 2;
}

//*****************************************************************************************
//Nom: doublerTailleEnHauteur
//Action: double la taille en hauteur
//Parametre: - void
//Retrun: void
//*****************************************************************************************
void Image::doublerTailleEnHauteur() {
	// Stockage temporaire de l'image.
	Pixel **pixelsTmp = pixels_;
	// Création d'une nouvelle image hauteur * 2.
	pixels_ = new Pixel*[nombrePixelEnHauteur_ * 2];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_ * 2; i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	};

	// Copie de l'image stocké temporairement sur la nouvelle image.
	for (unsigned int j = 0; j < nombrePixelEnHauteur_; j++) {
		for (unsigned int i = 0; i < nombrePixelEnLargeur_; i++) {
			pixels_[j][i] = pixelsTmp[j][i];
		};
		//supression des pointeurs du stockage temporaire
		delete pixelsTmp[j];
		pixelsTmp[j] = nullptr;
	};
	nombrePixelEnHauteur_ = 2 * nombrePixelEnHauteur_;
}
//*****************************************************************************************
//Nom: augmenterTeintePixel
//Action: augmente la teinte d'un pixel
//Parametre:- unsigned int positionLargeur
//			- unsigned int positionHauteur
//			- int  increment
//			- char couleur
//Retrun: void
//*****************************************************************************************
void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur) {
	if (couleur == 'G') 
		pixels_[positionHauteur][positionLargeur].modifierTeinteVert(increment);
	if (couleur == 'R') 
		pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(increment);
	if (couleur == 'B') 
		pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(increment);
}

//*****************************************************************************************
//Nom: afficherImage
//Action: affiche une image
//Parametre:- void
//Retrun: void
//*****************************************************************************************
void Image::afficherImage() const
{
	//ergonmie
	cout << nomImage_ <<": "<<char(218)<< char(196)<< char(196) << char(196) << char(196) << char(196) << char(191);
	cout << "        " <<endl;
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		//ergonmie
		cout << "        "<<char(179)<<" ";
		for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++){
			pixels_[i][j].afficherPixel();
		};
		//ergonmie
		cout << " "<<char(179)<<"\n\r";
	};
	//ergonmie
	cout << "        "<< char(192) << char(196) << char(196) << char(196) << char(196) << char(196)<< char(217) <<endl;
}

//*****************************************************************************************
//Nom: ajouterPixel
//Action: ajoute un pixel aux position passée en parametre
//Parametre:- Pixel & pixel
//			-unsigned int positionLargeur
//			- unsigned int positionHauteur
//Retrun: void
//*****************************************************************************************
void Image::ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur)
{
	pixels_[positionHauteur][positionLargeur] = pixel;
}