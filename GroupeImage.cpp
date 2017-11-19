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
	int old_size = images_.size();
	auto it = remove_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));
	images_.erase(it, images_.end());
	if (images_.size() != old_size)
		return true;
	else
		return false;
}

void GroupeImage::afficherImages(ostream& os) const {

	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;
	auto pos = images_.begin();
	auto fin = images_.end();
	for (; pos != fin; pos++) {
		os << *(*pos) << "--------------------------------------------------" << endl;
	}
	//copy(groupeImage.images_.begin(), groupeImage.images_.end(), ostream_iterator<Image*>(os, "\n\r"));
}



/*A MODIFIER*/
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
	auto pos = groupeImage.images_.begin();
	auto fin = groupeImage.images_.end();
	for (pos; pos != fin; pos++) {
		os << *(*pos) << "--------------------------------------------------" << endl;
	}
	//copy(groupeImage.images_.begin(), groupeImage.images_.end(), ostream_iterator<Image*>(os, "\n\r"));
	return os;
}

unsigned int GroupeImage::obtenirNombreImages() const {
	return images_.size();
}

/*/
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
*/

/* a implementer ??*/
/*
std::list<Image*> GroupeImage::obtenirListImage() const { 
	return images_;
}
*/

void GroupeImage::toutEnregistrer() {
	//Save une image
	auto saveImage = [](Image* image) {
		string nom = "./Ensemble d'images/" + image->obtenirTypeEnString()
			+ "/" + image->obtenirNomImage();
		cout << "Sauvegarde de " << nom << endl;
		image->sauvegarderImage(nom);
	};
	//save toutes les image
	for_each(images_.begin(), images_.end(), saveImage);
}

Image* GroupeImage::obtenirImageParIndex(int index) //Similaire a obtenirImage... ligne 50
{
	auto it = images_.begin();
	advance(it, index);
	return  *it;
}

double GroupeImage::obtenirIntensiteMoyenne(){

	double intensiteSomme = 0;
	//Caclul de la somme des intensitées
	auto pos = images_.begin();
	auto fin = images_.end();
	for (pos; pos != fin; pos++) {
		intensiteSomme +=(*pos)->obtenirIntensiteMoyenne();
	}
	return intensiteSomme / (double)images_.size();
}

double GroupeImage::obtenirTailleMoyenne() {
	
	unsigned int taille = 0;
	//Caclul de la somme des tailles

	auto pos = images_.begin();
	auto fin = images_.end();
	for (pos; pos != fin; pos++) {
		taille += (*pos)->obtenirTaille();
	}
	return taille / (double)images_.size();
}

template<typename PredicatUnaire>
void GroupeImage::appliquerFoncteurUnaire(PredicatUnaire& froncteur) const {
	for_each(images_.begin(), images_.end(), froncteur);
}

template<typename PredicatUnaire>
void GroupeImage::supprimerElements(PredicatUnaire& froncteur) {
	auto it = remove_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));
	images_.erase(it, images_.end());
}