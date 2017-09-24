/**************************************************
* Titre: Travail pratique #1 - Image.h
* Date: Septembre 2017
* Auteur: Claude GAGNE - Steven NICOULEAU
**************************************************/
#ifndef IMAGE_H
#define IMAGE_H
#include "Pixel.h"
#include<iostream>
using namespace std;

class Image
{
public:
	//Constructeur par default
	Image();
	//Constructeur par parametre
	Image(const string& nomImage, unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur);
	//Destructeur
	~Image();

	// Accesseurs
	string getNomImage() const;
	unsigned int getNombrePixelLargeur() const;
	unsigned int getNombrePixelHauteur() const;
	Pixel obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const;

	//Mutateur
	void modifierNomImage(const string & nomImage);

	//Methodes
	void doublerTailleEnLargeur();
	void doublerTailleEnHauteur();
	void augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur);
	void afficherImage() const;
	void ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur);

private :
	//Attributs
	string nomImage_;
	unsigned int nombrePixelEnHauteur_;
	unsigned int nombrePixelEnLargeur_;
	Pixel** pixels_;
};

#endif