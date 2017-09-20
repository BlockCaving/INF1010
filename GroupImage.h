#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H
#include "Image.h"

using namespace std;


class GroupImage
{
public:
	GroupImage();
	GroupImage(const string &type, unsigned int capaciteImages);
	~GroupImage();
	
	string obtenirType() const;
	Image obtenirImage(unsigned int indiceImage) const;
	unsigned int obtenirNombreImages() const;

	void modifierType(const string &type);
	void doublerTailleImageEnLargeur(unsigned int indiceImage);
	void doublerTailleImageEnHauteur(unsigned int indiceImage);
	void ajouterImage(const Image &image);
	void afficherImages() const;
	
private:
	string type_;
	unsigned int nombreImages_;
	unsigned int capaciteImages_;
	Image* images_;
};

#endif