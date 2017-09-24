/**************************************************
* Titre: Travail pratique #1 - GroupImage.h
* Date: Septembre 2017
* Auteur: Claude GAGNE - Steven NICOULEAU
**************************************************/

#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H
#include "Image.h"

using namespace std;


class GroupImage
{
public:
	//Constructeur par defaut
	GroupImage();
	//Constructeur par param�tre
	GroupImage(const string &type, unsigned int capaciteImages);
	//Destructeur
	~GroupImage();
	
	//Accesseurs
	string obtenirType() const;
	Image obtenirImage(unsigned int indiceImage) const;
	unsigned int obtenirNombreImages() const;
	
	//Mutateur
	void modifierType(const string &type);

	//M�thodes
	void doublerTailleImageEnLargeur(unsigned int indiceImage);
	void doublerTailleImageEnHauteur(unsigned int indiceImage);
	void ajouterImage(const Image &image);
	void afficherImages() const;
	
private:
	//Attribut
	string type_;
	unsigned int nombreImages_;
	unsigned int capaciteImages_;
	Image* images_;
};

#endif