#ifndef BASE_DE_DONNES_SPECIFIQUE
#define BASE_DE_DONNES_SPECIFIQUE

#include "BaseDeDonnesGenerique.h"
#include "GroupeImage.h"
#include "Image.h"
#include "Foncteur.h"

class BaseDeDonnesSpecifique: public BaseDeDonnesGenerique<Image,GroupeImage>
{
public:
	bool AssocierImage(GroupeImage* groupe, Image* image) {
		groupe->ajouterImage(image);
		ajouter(image);
	};

	bool EnleverImage(GroupeImage* groupe, const std::string& nomImage) {
		groupe->retirerImage(nomImage);
		//Voir precision sujet
		supprimerImage(FoncteurImagesDeMemeNom(nomImage));
	};

	friend std::ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase) {

		os << endl;
		os << "Contenu: " << dataBase.listGroupeImage_.size() << " groupes d'images et " << dataBase.listImage_.size() << " images" << endl;
		
		//affiche le contenu de tout les groupes de la database
		auto displayGroup = [](GroupeImage* group) {
			cout << "Groupe: " << endl;
			for (unsigned int i = 0; i < group->obtenirNombreImages(); i++)
				cout << "		- " << group->obtenirImageParIndex(i)->obtenirNomImage() <<endl;
		};
		for_each(dataBase.listGroupeImage_.begin(), dataBase.listGroupeImage_.end(), displayGroup);

		//affiche le om de toute les image de la database
		if (dataBase.listImage_.begin() != dataBase.listImage_.end())
			os << "Images: " << endl;
		auto displayNomImage = [](Image* image) { cout << "		- " << image->obtenirNomImage() << endl; };
		for_each(dataBase.listImage_.begin(), dataBase.listImage_.end(), displayNomImage);

		os << "**************************************************" << endl << endl;	
		return os;
	};
};
#endif
