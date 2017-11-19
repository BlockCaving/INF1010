//
// Created by Gabriel Bernard on 17-09-12.
//

#include "GroupeImage.h"
#include <iterator>
#include <algorithm>
#include "Foncteur.h"

using namespace std;

//*****************************************************************************************
//		CODE FOURNIS
//*****************************************************************************************

GroupeImage::GroupeImage() {};

GroupeImage::GroupeImage(const GroupeImage& groupe) : images_(groupe.images_) {}

GroupeImage::~GroupeImage() {};

GroupeImage& GroupeImage::operator=(const GroupeImage &groupe) {
	images_.clear();

	//copy tout les element du groupe passé en parametre à partir du debut de la liste attribut images_
	copy(groupe.images_.begin(), groupe.images_.end(), images_.begin());

	auto pos = groupe.images_.begin();
	auto fin = groupe.images_.end();
	//parcours chque element de la liste et surprime celui qui correspond à l'objet passe en parametre (par incrementation de l'itérateur)
	//aurait pu etre fait par un copy mais le sujet oblige insert => copy(pos, fin, images_.begin());
	for (; pos != fin; pos++) {
		images_.insert(pos, *pos);
	}
	return *this;
}

bool GroupeImage::ajouterImage(Image* image) {
	if (find(images_.begin(), images_.end(), image) != images_.end()) {					//parcours la liste et si on trouve l'image passé en paramtetre
		std::cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;
		return false;
	}
	else {			//sinon on l'ajoute
		images_.push_back(image);
		std::cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
		return true;
	}
}
	

bool GroupeImage::retirerImage(const std::string& nom) {
	int old_size = images_.size();
	auto it = remove_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));			//parcours toute la liste et remove si une image a le meme nom que le parametre du foncteur
	images_.erase(it, images_.end());
	//si on a retirer une image
	if (images_.size() != old_size)
		return true;
	else
		return false;
}

void GroupeImage::afficherImages(ostream& os) const {

	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;
	//parcours et affiche chaque element de la liste attribut images_ par increment de l'iterateur
	auto pos = images_.begin();
	auto fin = images_.end();
	for (; pos != fin; pos++) {
		os << *(*pos) << "--------------------------------------------------" << endl;
	}
}


/*A MODIFIER*/
Image* GroupeImage::obtenirImage(unsigned int indiceImage) const {
	return *next(images_.begin(), indiceImage);			//place l'itérateir a l'indice passé en parametre
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
	//parcours et affiche chaque element de la liste passé en parametre par increment de l'iterateur
	auto pos = groupeImage.images_.begin();
	auto fin = groupeImage.images_.end();
	for (; pos != fin; pos++) {
		os << *(*pos) << "--------------------------------------------------" << endl;
	}
	return os;
}

unsigned int GroupeImage::obtenirNombreImages() const {
	return images_.size();
}

void GroupeImage::toutEnregistrer() {
	//Save une image
	auto saveImage = [](Image* image) {
		string nom = "../Ensemble d'images/" + image->obtenirTypeEnString()
			+ "/" + image->obtenirNomImage();
		cout << "Sauvegarde de " << nom << endl;
		image->sauvegarderImage(nom);
	};
	//save toutes les image
	//pour chaque element de la liste, on applique la fonction défint ci dessus
	for_each(images_.begin(), images_.end(), saveImage);
}

//*****************************************************************************************
//		CODE NON FOURNIS
//*****************************************************************************************

//*****************************************************************************************
//Nom: obtenirImageParIndex
//Action: methode qui retourne un pointeurver l'image du groupe correspondant à l'index passé en parametre
//int index
//Retrun: Image*
//*****************************************************************************************
Image* GroupeImage::obtenirImageParIndex(int index) 
{
	auto it = images_.begin();
	advance(it, index);					//avance l'itérateur de la liste attribut images au n ieme élément passé en paramentre
	return  *it;
}


//*****************************************************************************************
//Nom: retournerIntensiteMoyenne
//Action: methode qui retourne un decimal entre 0 et 1 represantant la moyenne de l'intensité de image du groupe
//Parametre:- void
//Retrun: double
//*****************************************************************************************
double GroupeImage::obtenirIntensiteMoyenne(){

	double intensiteSomme = 0;
	//Caclul de la somme des intensitées
	auto pos = images_.begin();
	auto fin = images_.end();
	//parcours l'ensemble des éléments de la liste et somme leurs intensité moyenne par increment de l'itérateur
	for (; pos != fin; pos++) {
		intensiteSomme +=(*pos)->obtenirIntensiteMoyenne();
	}
	return intensiteSomme / (double)images_.size();			//divise par le nombre d'image pour avoir la moyyen du gorupe
}


//*****************************************************************************************
//Nom: obtenirTailleMoyenne
//Action: methode constante qui retourne un decimal represantant la moyenne de la taille de chaque image du groupe
//Parametre:- void
//Retrun: double
//*****************************************************************************************
double GroupeImage::obtenirTailleMoyenne() {
	
	unsigned int taille = 0;
	//Caclul de la somme des tailles

	auto pos = images_.begin();
	auto fin = images_.end();
	//parcours l'ensemble des éléments de la liste et somme leur taille moyenne par increment de l'itérateur
	for (; pos != fin; pos++) {
		taille += (*pos)->obtenirTaille();
	}
	return taille / (double)images_.size();			//divise par le nombre d'image pour avoir la moyyen du gorupe
}