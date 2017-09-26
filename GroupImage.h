#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H
#include "Image.h"
#include <vector>

using namespace std;


class GroupImage
{
public:
	GroupImage(); // A modifier l'implementation
	~GroupImage(); // A modifier l'implementation


	// Constructeur à supprimer pour TP2
	GroupImage(const string &type, unsigned int capaciteImages);

	void modifierType(const string &type);
	string obtenirType() const;

	// Modifier cette méthode par Image* obtenirImage(unsigned int indiceImage) const;
	Image obtenirImage(unsigned int indiceImage) const;


	// Méthode à supprimer pour TP2
	unsigned int obtenirNombreImages() const;

	// Méthode à modifier avec void ajouterImage(Image* &image);
	void ajouterImage(const Image &image);
	//  ajouter la methode pour retirer une image en donnant
	//son nom en paramètre

	// Méthode à modifier avec void afficherImages(ostream& os)
	void afficherImages() const;


	void doublerTailleImageEnLargeur(unsigned int indiceImage);

	void doublerTailleImageEnHauteur(unsigned int indiceImage);


	// Ajouter les opérateurs 

private:

	string type_;

	// Attributs à mdifier 
	unsigned int nombreImages_;
	unsigned int capaciteImages_;
	vector <Image*> images_;

};

#endif