
#include "GroupImage.h"
#include <iostream>
#include <vector>
using namespace std;

//Constructeur par defaut
GroupImage::GroupImage():nombreImages_(1),capaciteImages_(1) {
	images_.push_back(new Image());
}

//Destructeur
GroupImage::~GroupImage() {
	for (unsigned int i = 0; i < nombreImages_; i++) {			//supression des pointeurs
		delete images_[i];
	}
	images_.clear();
	capaciteImages_ = 0;
	nombreImages_ = 0;
}

//Constructeur par parametre
GroupImage::GroupImage(const string & type,unsigned int capaciteImages): type_(type), capaciteImages_(capaciteImages) {
	for (unsigned int i = 0; i < capaciteImages_; i++) {
		images_.push_back(new Image());							//alloue de l'espace mémoire dans le vecteur
	}
	nombreImages_ = 0;
}

//Mutateur
void GroupImage::modifierType(const string & type) {
	type_ = type;
}

//Accesseur
string GroupImage::obtenirType() const{
	return type_;
}

Image* GroupImage::obtenirImage(unsigned int indiceImage) const {
	if (indiceImage<nombreImages_)
		return images_[indiceImage];
}


//*********** OPERATEURS *********//
//*****************************************************************************************
//Nom: << 
//Action: affiche les images du groupe
//*****************************************************************************************
ostream& operator<<(ostream& o, const GroupImage& groupe) {

	o << "Affichage des images du groupe :  ";
	o << groupe.obtenirType().c_str() << endl;
	o << "*********************************************" << endl;

	for (unsigned int i = 0; i < groupe.nombreImages_; i++) {
		o << *groupe.obtenirImage(i);
		o << "---------------------------------------------" << endl;
	}
	o << endl;
	return o;
}

//*****************************************************************************************
//Nom: +=
//Action: Ajoute une image au vecteur images_
//*****************************************************************************************
GroupImage& GroupImage::operator+=(const Image& image) {
	bool flagErreur = false;								//= true si l'image ajoutée a le nom d'une image du groupe
	for (unsigned int i = 0; i < nombreImages_; i++) {
		if (*images_[i] == image.obtenirNomImage()) {
			flagErreur = true;
		}
	}
	if ((nombreImages_ < capaciteImages_) && (flagErreur == false)) {
		*images_[nombreImages_] = image;
		nombreImages_++;					//update nombreImages_
		cout << image.obtenirNomImage().c_str() << " a bien ete ajoute" << endl;
	}
	else {
		cout << "Erreur le nom de l'image est deja utilise ou la capacite du groupe est depasse!";
	}
	return *this;
}
//*****************************************************************************************
//Nom: -=
//Action: Enlève une image du vecteur images_
//*****************************************************************************************
GroupImage& GroupImage::operator-=(const Image& image) {
	for (unsigned int i = 0; i < nombreImages_; i++) {
		if (*images_[i] == image) {
			images_[i] = images_[nombreImages_ - 1];
			images_.pop_back();
			nombreImages_--;							//update le nombre d'image
		}
	}
	return *this;
}


//*********** METHODES *********//

//*****************************************************************************************
//Nom: ajouterImage
//Action: ajoute l'image passé en en parametre dans le groupe d'image si la capcitée le permet
//Parametre:- const Image &image
//Retrun: void
//*****************************************************************************************
void GroupImage::ajouterImage(const Image& image) {
	bool flagErreur = false;								//= true si l'image ajoutée a le nom d'une image du groupe
	for (unsigned int i = 0; i < nombreImages_; i++) {
		if (*images_[i] == image.obtenirNomImage()) {
			flagErreur = true;
		}
	}
	if ((nombreImages_ < capaciteImages_) && (flagErreur==false)) {		
		*images_[nombreImages_] = image;
		nombreImages_++;					//update nombreImages_
		cout << image.obtenirNomImage().c_str() << " a bien ete ajoute" << endl;
	}
	else {
		cout << "Erreur le nom de l'image est deja utilise ou la capacite du groupe est depasse!";
	}
}

//*****************************************************************************************
//Nom: retirerImage
//Action: retire l'image dont le nom est passé en en parametre si elle est dans le groupe
//Parametre:- const string nom
//Retrun: void
//*****************************************************************************************
void GroupImage::retirerImage(const string nom) {
	bool flagImageDelete = false;						//true si l'image a été convenablement supprimée
	for (unsigned int i = 0; i < nombreImages_; i++) {
		if (*images_[i] == nom) {
			images_[i] = images_[nombreImages_-1];
			images_.pop_back();
			nombreImages_--;							//update le nombre d'image
			flagImageDelete = true;
		}
	}
	//Affichage
	if (flagImageDelete == true)
		cout << "L'Image "<< nom.c_str() <<" a bien ete supprime de " << type_.c_str() << endl <<endl;
	else
		cout << "L'Image " << nom.c_str() << " ne fait pas parti de " << type_.c_str() << endl <<endl;
}

//*****************************************************************************************
//Nom: doublerTailleImageEnLargeur
//Action: double la largeur de l'image dont l'indice est passé en parametre
//Parametre:- unsigned int indiceImage
//Retrun: void
//*****************************************************************************************
void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	if (indiceImage<nombreImages_)					//verification de l'indice
		(*images_[indiceImage]).doublerTailleEnLargeur();
}

//*****************************************************************************************
//Nom: doublerTailleImageEnHauteur
//Action: double la hauteur de l'image dont l'indice est passé en parametre
//Parametre:- unsigned int indiceImage
//Retrun: void
//*****************************************************************************************
void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	if (indiceImage<nombreImages_)				//verifiaction de l'indice
		(*images_[indiceImage]).doublerTailleEnHauteur();
}
 