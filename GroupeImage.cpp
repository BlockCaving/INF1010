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
	bool egal = 0;
	remove_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));
}

void GroupeImage::afficherImages(ostream& os) const {

	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;

	Iterator pos = images_.begin();
	Iterator fin = images_.end();
	for (pos; pos != fin; pos++) {
		os << *(*pos) << "--------------------------------------------------" << endl;
	}
	os << endl;
}

Image* GroupeImage::obtenirImage(unsigned int indiceImage) const {
	Iterator pos = images_.begin();
	return **(pos + indiceImage);
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

	Iterator pos = groupeImage.images_.begin();
	Iterator fin = groupeImage.images_.end();
	for (pos; pos != fin; pos++) {
		os << *(*pos) << "--------------------------------------------------" << endl;
	}
	os << endl;
	return os;
}

unsigned int GroupeImage::obtenirNombreImages() const {
	return images_.size();
}

void GroupeImage::toutMettreEnNB() {
	Iterator pos = images_.begin();
	Iterator fin = images_.end();
	for (pos; pos != fin; pos++) {
		**pos.convertirBN();
	}
}
void GroupeImage::toutMettreEnGris() {
	Iterator pos = images_.begin();
	Iterator fin = images_.end();
	for (pos; pos != fin; pos++) {
		**pos.convertirGris();
	}
}

void GroupeImage::toutMettreEnCouleur() {
	Iterator pos = images_.begin();
	Iterator fin = images_.end();
	for (pos; pos != fin; pos++) {
		**pos.convertirCouleur();
	}
}

void GroupeImage::toutMettreEnNegatif() {
	Iterator pos = images_.begin();
	Iterator fin = images_.end();
	for (pos; pos != fin; pos++) {
		**pos.mettreEnNegatif();
	}
}

void GroupeImage::toutEnregistrer() {
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

Image* GroupeImage::obtenirImageParIndex(int index)
{
	auto it = images_.begin();
	advance(it, index);
	return  *it;
}

double GroupeImage::obtenirIntensiteMoyenne(){
}
double GroupeImage::obtenirTailleMoyenne();