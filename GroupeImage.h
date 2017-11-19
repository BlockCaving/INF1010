//
// Created by Gabriel Bernard on 17-09-12.
//

#ifndef TP3_GROUPEIMAGE_H
#define TP3_GROUPEIMAGE_H

#include <list>
#include <string>
#include "Image.h"

class GroupeImage {
public:
    GroupeImage();

    // Constructeur par copie
    GroupeImage(const GroupeImage& groupe);

    ~GroupeImage();

	Image* obtenirImage(unsigned int indiceImage) const;

    // Partie à ajouter et à modifier
    bool ajouterImage(Image* image);
    bool retirerImage(const std::string& nom);

    void afficherImages(std::ostream& os) const; // Partie a modifier

    // Surcharge d'operateurs
    GroupeImage& operator=(const GroupeImage& groupe);
    GroupeImage& operator+=(Image* image);
    GroupeImage& operator-=(Image* image);
    friend std::ostream& operator<<(std::ostream& os, const GroupeImage& image);

    unsigned int obtenirNombreImages() const;
	void toutEnregistrer();

	// TP5
	Image* obtenirImageParIndex(int index);
	double obtenirIntensiteMoyenne();
	double obtenirTailleMoyenne();

	// A implementer dans ce fichier
	template<typename PredicatUnaire>
	void appliquerFoncteurUnaire(PredicatUnaire& foncteur) const {
		for_each(images_.begin(), images_.end(), foncteur);					//pour chaque element de laliste parcourue, on applique le foncteur
	}

	template<typename PredicatUnaire>
	void supprimerElements(PredicatUnaire& foncteur) {
		auto it = remove_if(images_.begin(), images_.end(), foncteur);		//on retire chaque élément de la liste parcourue pour lequelle le foncteur est vrai
		images_.erase(it, images_.end());
	};


private:
	std::list<Image*> images_;

};


#endif //TP3_GROUPEIMAGE_H
