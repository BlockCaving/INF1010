//
// Created by Gabriel Bernard on 17-09-12.
//

#include "GroupeImage.h"
#include <iterator>
#include <algorithm>
#include "Foncteur.h"

using namespace std;

GroupeImage::GroupeImage() {};

GroupeImage::GroupeImage(const GroupeImage& groupe) : images_(groupe.images_) {}

GroupeImage::~GroupeImage() {};

GroupeImage& GroupeImage::operator=(const GroupeImage &groupe) {
	images_.clear();
	copy(groupe.images_.begin(), groupe.images_.end(), images_.begin());

	return *this;
}

bool GroupeImage::ajouterImage(Image* image) {
	if (find(images_.begin(), images_.end(), image) != images_.end()) {
		std::cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;
		return false;
	}
	else {
		images_.push_back(image);
		std::cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
		return true;
	}
}
	

bool GroupeImage::retirerImage(const std::string& nom) {
	remove_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));
}

void GroupeImage::afficherImages(ostream& os) const {

	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;
	copy(images_.begin(), images_.end(), ostream_iterator<Image*>(cout, "----------------------------")); // Reste à voir le delimiter avec ou sans endl
}

Image* GroupeImage::obtenirImage(unsigned int indiceImage) const {
	return *next(images_.begin(), indiceImage);
}

GroupeImage& GroupeImage::operator+=(Image* image)
{
	ajouterImage(image);
	return *this;
}

GroupeImage& GroupeImage::operator-=(Image* image)
{
	retirerImage(image->obtenirNomImage());
	return *this;
}


std::ostream& operator<<(std::ostream& os, const GroupeImage& groupeImage)
{
	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;

	copy(groupeImage.images_.begin(), groupeImage.images_.end(), ostream_iterator<Image*>(cout, "----------------------------"));
	return os;
}

unsigned int GroupeImage::obtenirNombreImages() const {
	return images_.size();
}

void GroupeImage::toutMettreEnNB() {
	for_each(images_.begin(), images_.end(), FoncteurMettreEnBN());
}
void GroupeImage::toutMettreEnGris() {
	for_each(images_.begin(), images_.end(), FoncteurMettreEnGris());
}

void GroupeImage::toutMettreEnCouleur() {
	for_each(images_.begin(), images_.end(), FoncteurMettreEnCouleur());
}

void GroupeImage::toutMettreEnNegatif() {
	for_each(images_.begin(), images_.end(), FoncteurMettreEnNegatif());
}

void GroupeImage::toutEnregistrer() {
	
	for_each(images_.begin(), images_.end(), []
	cout << endl;
	Iterator pos = images_.begin();
	Iterator fin = images_.end();
	for (pos; pos != fin; pos++) {
		Image* image = **pos;
		string nom = "./Ensemble d'images/" + image->obtenirTypeEnString()
			+ "/" + image->obtenirNomImage();
		cout << "Sauvegarde de " << nom << endl;
		**pos->sauvegarderImage(nom);
	}
}

Image* GroupeImage::obtenirImageParIndex(int index) //Similaire a obtenirImage... ligne 50
{
	auto it = images_.begin();
	advance(it, index);
	return  *it;
}

double GroupeImage::obtenirIntensiteMoyenne(){
}
double GroupeImage::obtenirTailleMoyenne();