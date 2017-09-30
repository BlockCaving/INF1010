
#include "Image.h"
#include <iostream>
#include "Const.h"

using namespace std;

//Construceur par defaut
Image::Image():nomImage_("Image Vide"),nombrePixelEnHauteur_(1),nombrePixelEnLargeur_(1)
{
	pixels_ = new Pixel*[1];
	pixels_[0] = new Pixel[1];
}

//Constructeur par copie
Image::Image(const Image& imageCopie) :
	nomImage_(imageCopie.nomImage_), nombrePixelEnHauteur_(imageCopie.nombrePixelEnHauteur_),		//shallow copie
	nombrePixelEnLargeur_(imageCopie.nombrePixelEnLargeur_), pixels_(nullptr)
{
	pixels_ = new Pixel*[nombrePixelEnLargeur_];					//deep copie
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		pixels_[i] = imageCopie.pixels_[i];
	}
}

//Constructeur par parametre
Image::Image(const string& nomImage, unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur) :nomImage_(nomImage),
nombrePixelEnHauteur_(nombrePixelHauteur), nombrePixelEnLargeur_(nombrePixelLargeur)
{
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	}
}

//Destructeur
Image::~Image()
{
	/*
	for(unsigned int i = 0; i < nombrePixelEnHauteur_; i++){
		delete[] pixels_[i];
	}
	delete[] pixels_;
	nombrePixelEnHauteur_ = 0;
	nombrePixelEnLargeur_ = 0;
	pixels_ = nullptr;
	*/
}

//Mutateur
void Image::modifierNomImage(const string & nomImage) {
	nomImage_ = nomImage;
}

//Accesseur
unsigned int Image::obtenirNombrePixelHauteur() const {
	return nombrePixelEnHauteur_;
}

unsigned int Image::obtenirNombrePixelLargeur() const {
	return nombrePixelEnLargeur_;
}

string Image::obtenirNomImage() const {
	return nomImage_;
}

Pixel Image::obtenirPixel(unsigned int positionLargeur, unsigned int positionHauteur) const {
	if (positionLargeur < nombrePixelEnLargeur_ && positionHauteur < nombrePixelEnHauteur_)		//test de l'indice
		return pixels_[positionHauteur][positionLargeur];
}

//*********** OPERATEURS *********//
//*****************************************************************************************
//Nom: << 
//Action: affiche une image
//fonciton globale
//*****************************************************************************************
ostream& operator<<(ostream& o, const Image& image) {
	o << "Affichage de l'image :  " << image.nomImage_.c_str() << endl;

	//ergonomie
	o << "      " << char(218) << char(196);
	for (unsigned int m = 0; m < image.nombrePixelEnLargeur_; m++) {
		o << char(196);
	}
	o << char(196) << char(191) << endl;

	for (unsigned int i = 0; i < image.nombrePixelEnHauteur_; i++) {
		//ergonomie
		o  << "      " << char(179) << " ";
		for (unsigned int j = 0; j < image.nombrePixelEnLargeur_; j++) {
			o << image.pixels_[i][j];										//affiche le pixel pointé par les index
		}
		o << " " << char(179) << "\n\r";
	}

	//ergonomie
	o << "      " << char(192) << char(196);
	for (unsigned int l = 0; l < image.nombrePixelEnLargeur_; l++) {
		o << char(196);
	}
	o << char(196) << char(217) << endl;
	return o;
}


//*****************************************************************************************
//Nom: == 
//Action: Compare deux image et retourne true si elle sont identiques
//*****************************************************************************************
bool Image::operator==(const Image& image) {
	unsigned int nombrePixelIdentique = 0;

	//si meme nom et meme nobre de pixels en hauteur et en largeur
	if (nomImage_ == image.nomImage_ && nombrePixelEnHauteur_ == image.nombrePixelEnHauteur_ && nombrePixelEnLargeur_ == image.nombrePixelEnLargeur_) {
		for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
			for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++) {
				if (pixels_[i][j] == image.pixels_[i][j]) {			//comparaison des pixels
					nombrePixelIdentique++;							//++ si les pixels comparés sont identiques
				}
			}
		}
		//si le nombre de pixels identique est egal au nombre de pixels de l'image le images sont identiques
		if (nombrePixelIdentique == (nombrePixelEnHauteur_ * nombrePixelEnLargeur_))
			return true;
		else
			return false;
	}
	else
		return false;
}

//*****************************************************************************************
//Nom: == 
//Action: Compare le nom de deux image et retourne true si ils sont identiques
//*****************************************************************************************
bool Image::operator==(string nomImage) {
	if (nomImage_ == nomImage)
		return true;
	else
		return false;
}

//*****************************************************************************************
//Nom: == 
//Action: Compare le nom de deux image et retourne true si ils sont identiques (sens inversé)
//fontion globale
//*****************************************************************************************
bool operator==(string nomImage, const Image& image) {
	if (nomImage == image.nomImage_)
		return true;
	else
		return false;
}

//*****************************************************************************************
//Nom: =
//Action: assigne les attribut d'une image a une autre
//fontion globale
//*****************************************************************************************
Image& Image:: operator=(const Image& image) {
	if (this != &image) {									// empeche la destruction du pointeur si img1=img1
		nomImage_ = image.nomImage_;
		nombrePixelEnHauteur_ = image.nombrePixelEnHauteur_;
		nombrePixelEnLargeur_ = image.nombrePixelEnLargeur_;
		delete[] pixels_;									// evite le double pointage
		for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
			pixels_[i] = image.pixels_[i];
		}
	}
	return *this;											//retourne l'objet déréférencé
}

//*********** Methodes *********//

//*****************************************************************************************
//Nom: ajouterPixel
//Action: ajoute un pixel aux position passée en parametre
//Parametre:- Pixel & pixel
//			-unsigned int positionLargeur
//			- unsigned int positionHauteur
//Retrun: bool
//*****************************************************************************************
bool Image::ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur) {
	if (positionLargeur >= nombrePixelEnLargeur_ || positionHauteur >= nombrePixelEnHauteur_) {
		return false;
	}
	else {
		pixels_[positionHauteur][positionLargeur] = pixel;
		return true;
	}
}

//*****************************************************************************************
//Nom: doublerTailleEnHauteur
//Action: double la taille en hauteur
//Parametre: - void
//Retrun: void
//*****************************************************************************************
void Image::doublerTailleEnHauteur(){
	nombrePixelEnHauteur_ *= 2;

	Pixel** imageTemp = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0;i < nombrePixelEnHauteur_ / 2;i++) {
		imageTemp[i] = pixels_[i];
	}

	for (unsigned int i = nombrePixelEnHauteur_ / 2;i < nombrePixelEnHauteur_;i++) {
		imageTemp[i] = new Pixel[nombrePixelEnLargeur_];
	}	

	//delete[] pixels_;
	pixels_ = imageTemp;
	imageTemp = nullptr;
}

//*****************************************************************************************
//Nom: doublerTailleEnLargeur
//Action: double la taille en largeur
//Parametre: - void
//Retrun: void
//*****************************************************************************************
void Image::doublerTailleEnLargeur() {
	nombrePixelEnLargeur_ *= 2;

	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		Pixel* colonneImage = new Pixel[nombrePixelEnLargeur_];
		for (unsigned int j = 0;j < nombrePixelEnLargeur_ / 2; j++) {
			colonneImage[j] = pixels_[i][j];
		}
		delete[] pixels_[i];
		pixels_[i] = colonneImage;
	}
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
	if (positionLargeur < nombrePixelEnLargeur_ && positionHauteur < nombrePixelEnHauteur_) {
		if (couleur == 'R') {
			pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(increment);
		}
		if (couleur == 'G') {
			pixels_[positionHauteur][positionLargeur].modifierTeinteVert(increment);
		}
		if (couleur == 'B') {
			pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(increment);
		}
	}
}