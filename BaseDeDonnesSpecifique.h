#ifndef BASE_DE_DONNES_SPECIFIQUE
#define BASE_DE_DONNES_SPECIFIQUE

#include "BaseDeDonnesGenerique.h"
#include "GroupeImage.h"
#include "Image.h"
#include "Foncteur.h"

class BaseDeDonnesSpecifique: public BaseDeDonnesGenerique<Image,GroupeImage>
{
public:
	bool AssocierImage(GroupeImage* groupe, Image* image) {			//associe des images a un groupe et à la base de donné dans l'attribut listeImage_
		ajouter(image);
		return groupe->ajouterImage(image);							//ajoute aussi les image au groupe
	};

	bool EnleverImage(GroupeImage* groupe, const std::string& nomImage) {
		supprimerImage(FoncteurImagesDeMemeNom(nomImage));			//suprime les image de la base de donné et du groupe passé en parametre
		return groupe->retirerImage(nomImage);
	};

	friend std::ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase) {

		os << endl;
		//affiche le contenu de la base de donné en donnant le nombre de groupe ainsi que le nombre d'image
		os << "Contenu: " << dataBase.listGroupeImage_.size() << " groupes d'images et " << dataBase.listImage_.size() << " images" << endl;

		//affiche le nom de toute les image de la database
		if (dataBase.listImage_.begin() != dataBase.listImage_.end())
			os << "Images: " << endl;
		auto displayNomImage = [](Image* image) { cout << "	- " << image->obtenirNomImage() << endl; };
		//pour chaque element de la liste, on effectue le fonction lambda défénit ci dessus
		for_each(dataBase.listImage_.begin(), dataBase.listImage_.end(), displayNomImage);

		os << "**************************************************" << endl << endl;	
		
		return os;
	};
};
#endif
