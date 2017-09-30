#ifndef IMAGE_H
#define IMAGE_H
#include "Pixel.h"

#include<iostream>

using namespace std;

class Image
{
public:
	Image();
	~Image();
	Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur);

	// SI c'est nécessaire ajouter un constructeur par copie
	Image(const Image& imageCopie);

	//Accesseur
	unsigned int obtenirNombrePixelHauteur() const;
	unsigned int obtenirNombrePixelLargeur() const;
	string obtenirNomImage() const;

	//Mutateur
	void modifierNomImage(const string & nomImage);

	//Methodes
	void doublerTailleEnLargeur();
	void doublerTailleEnHauteur();
	bool ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur);
	Pixel obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const ;
	void augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur);

    // Opérateurs
	Image& operator=(const Image& image);
	friend ostream& operator<<(ostream& o, const Image& image);
	bool operator==(const Image& image);
	bool operator==(string nomImage);
	friend bool operator==(string nomImage, const Image& image);

private :
	//Attributs
	string nomImage_;
	unsigned int nombrePixelEnHauteur_;
	unsigned int nombrePixelEnLargeur_;
	Pixel** pixels_;
};

#endif