#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H
#include "Image.h"
#include <vector>

using namespace std;


class GroupImage
{
public:
	//Constructeur par defaut
	GroupImage();
	//Destructeur
	~GroupImage();
	// Constructeur par paremetre
	GroupImage(const string &type, unsigned int capaciteImages);

	//Mutateur
	void modifierType(const string &type);
	//Accesseur
	string obtenirType() const;
	Image* obtenirImage(unsigned int indiceImage) const;

	//Methode
	void ajouterImage(const Image &image);
	void retirerImage(const string nom);
	void doublerTailleImageEnLargeur(unsigned int indiceImage);
	void doublerTailleImageEnHauteur(unsigned int indiceImage);

	//Opérateurs 
	GroupImage& operator+=(const Image& image);
	GroupImage& operator-=(const Image& image);
	friend ostream& operator<<(ostream& o, const GroupImage& groupe);

private:
	//Attributs
	string type_; 
	unsigned int nombreImages_;
	unsigned int capaciteImages_;
	vector <Image*> images_;
};

#endif