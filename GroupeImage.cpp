#include <iostream>
#include "GroupeImage.h"


using namespace std;

//Constructeur par defaut
GroupeImage::GroupeImage() {};

//Acesseur
unsigned int GroupeImage::obtenirNombreImages() const {
	return (unsigned int)images_.size();
}

// Fonction qui ajoute une image au vecteur si elle n'est pas presente
bool GroupeImage::ajouterImage(Image* image) {
    for (unsigned int i = 0; i <  images_.size(); i++)
    {
        if (image->obtenirNomImage() == *(images_[i]))
        {
            cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;
            return false;
        }
    }
    images_.push_back(image);
    std::cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
    return true;
}

// Fonction qui retire une image au vecteur si elle est presente
bool GroupeImage::retirerImage(const std::string& nom) {
    for (unsigned int i = 0; i < images_.size(); i++)
    {
        if (*(images_[i]) == nom)
        {
            images_[i] = images_.back();
            images_.pop_back();
            cout << nom << " a bien ete retire" << endl;
            return true;
        }
    }
    return false;
}

// Fonction qui permet de retourner une des images du vecteur
Image* GroupeImage::obtenirImage(unsigned int indiceImage) const {
    return images_[indiceImage];
}

// Fonction qui converti toute les image d'un groupe en image Noir et Blanc
void GroupeImage::toutMettreEnNB(void) {
	for (int i = 0; i < images_.size(); i++) {
		images_[i]->convertirNB();
	}
}

// Fonction qui converti toute les image d'un groupe en image Gris
void GroupeImage::toutMettreEnGris(void) {
	for (int i = 0; i < images_.size(); i++) {
		images_[i]->convertirGris();
	}
}
// Fonction qui converti toute les image d'un groupe en image Couleur
void GroupeImage::toutMettreEnCouleur(void) {
	for (int i = 0; i < images_.size(); i++) {
		images_[i]->convertirCouleur();
	}
}
// Fonction qui enregistre toute les image dans le bon sous répertoir en fonction de son type
// Parametre: string& path (chemin d'acces au repertoire d'ensemble d'image)
void GroupeImage::toutEnregistrer(const std::string& path) {
	string type = "";
	string nom = "";
	cout <<"\n\r";
	cout << "\n\r";

	//parcours toute les images
	for (int i = 0; i < images_.size(); i++) {
		//determine le lieu de sauvegarde
		type = images_[i]->obtenirTypeEnString();
		nom = images_[i]->obtenirNomImage();
		string pathImage = path + type + "/" + nom;
		images_[i]->sauvegarderImage(pathImage);
		cout << "Sauvegarde de " + pathImage + "\n\r";
	}
	cout << "\n\r";
	cout << "\n\r";
}

// Surcharge de l'operateur += qui ajoute une image au vecteur
GroupeImage& GroupeImage::operator+=(Image* image)
{
    ajouterImage(image);
    return *this;
}

// Surcharge de l'operateur -= qui retire une image au vecteur
GroupeImage& GroupeImage::operator-=(Image* image)
{
    retirerImage(image->obtenirNomImage());
    return *this;
}

// Surcharge de l'operateur de flux de sortie
ostream& operator<<(ostream& os, const GroupeImage& groupeImage)
{
    os << endl;
    os << "**************************************************" << endl;
    os << "Affichage des images du groupe :  " << endl;
    os << "**************************************************" << endl << endl;
    
    for  (unsigned int j= 0; j < groupeImage.images_.size(); j++) {
        os << *groupeImage.images_[j] << "--------------------------------------------------" << endl;
    }
    
    os << endl;

    return os;
}