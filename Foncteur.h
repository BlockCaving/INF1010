#ifndef  FONCTEUR
#define  FONCTEUR

#include "GroupeImage.h"
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 3

class FoncteurEgalImages
{
public:
	FoncteurEgalImages(Image* image) {
		image_ = image;
	}
	~FoncteurEgalImages() {}

	//retrun true si l'attribut pointeur images_ est le meme que le pointeur passé en paametre  
	bool FoncteurEgalImages::operator() (Image* imageAComparer) const {
		if (*image_ == *imageAComparer)
			return true;
		else
			return false;
	}

private:
	Image* image_;
};

class FoncteurImagesDeMemeNom
{
public:
	FoncteurImagesDeMemeNom(const std::string& nom) {
		nom_ = nom;
	}
	~FoncteurImagesDeMemeNom() {};

	//retrun true si le nom de l'image est le meme que celui passé en parametre
	bool operator() ( Image* image) const {
		if (nom_ == image->obtenirNomImage())
			return true;
		else
			return false;
	}

private:
	std::string nom_;
};

class FoncteurObtenirTailleImage
{
public:
	FoncteurObtenirTailleImage() {}
	~FoncteurObtenirTailleImage() {}
	//donne la taille de l'image 
	unsigned int operator() (const Image* image) const {
		return image->obtenirTaille();
	}
};


class FoncteurMettreEnGris
{
public:
	FoncteurMettreEnGris() {}
	~FoncteurMettreEnGris() {}

	//convertis l'image en gris
	void operator() (Image* image) {
		image->convertirGris();
	}

};

class FoncteurMettreEnCouleur
{
public:
	FoncteurMettreEnCouleur() {}
	~FoncteurMettreEnCouleur() {}

	//convertis l'image en couleur
	void operator() (Image* image) {
		image->convertirCouleur();
	}

};

class FoncteurMettreEnBN
{
public:
	FoncteurMettreEnBN() {}
	~FoncteurMettreEnBN() {}

	//convertis l'image en noir et blanc
	void operator() (Image* image) {
		image->convertirBN();
	}

};

class FoncteurMettreEnNegatif
{
public:
	FoncteurMettreEnNegatif() {}
	~FoncteurMettreEnNegatif() {}

	//convertis l'image en negatif
	void operator() (Image* image) {
		image->mettreEnNegatif();
	}

};

class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() {
	}

	FoncteurGenerateurNombresAlea(unsigned int min, unsigned int max) {
		min_ = min;
		max_ = max;
	}

	~FoncteurGenerateurNombresAlea() {}

	//génére un nombe aleatoire compris entre min_ et max_
	unsigned int operator() () const {
		int r = std::rand();
		r = (r %  max_ + min_);

		if (r >= min_ && r<max_)
			return r;
	}

private:
	unsigned int min_;
	unsigned int max_;
};


#endif;