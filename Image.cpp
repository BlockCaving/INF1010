#include "Image.h"
#include "PixelCouleur.h"
#include "PixelBN.h"
#include "PixelGris.h"
#include <iostream>
#include <sstream>

using namespace std;

Image::Image() {
	cheminVersImageOriginale_ = "";
	nomDuFichier_ = "";
	pixels_ = nullptr;
	hauteur_ = 0;
	largeur_ = 0;
	taille_ = 0;
	typeImage_ = Couleurs ;
}

Image::~Image() {
	for (unsigned int i = 0; i < taille_; i++) {
		delete pixels_[i];
		pixels_[i] = nullptr;
	}
}

// Constructeur par parametres
Image::Image(const string& cheminDuFichier, const TypeImage& type)
        : typeImage_(type), cheminVersImageOriginale_(cheminDuFichier), pixels_(nullptr) {
	for (int i = cheminVersImageOriginale_.size(); i > 0; i--)
	{	
		if (cheminVersImageOriginale_[i] == '/')
		{
			nomDuFichier_ = cheminVersImageOriginale_.substr(i + 1, cheminVersImageOriginale_.size());
			break;
		}
	}


    lireImage(cheminVersImageOriginale_, typeImage_);
    if(pixels_ == nullptr) {
        cerr << "Erreur lors de la lecture de l'image." << endl;
    }
}

//Constructeur par copie
Image::Image(const Image& image)
	: typeImage_(image.typeImage_), nomDuFichier_(image.nomDuFichier_), cheminVersImageOriginale_(image.cheminVersImageOriginale_), pixels_(nullptr),
	hauteur_(image.hauteur_), largeur_(image.largeur_), taille_(image.taille_){
	
	//pixels_ =       voir tp2
	for (unsigned int i = 0; i<taille_; i++)
		pixels_[i] = image.pixels_[i];

}

Image& Image::operator=(const Image& image) {
	if (this != &image) {
		delete pixels_;
		cheminVersImageOriginale_ = image.cheminVersImageOriginale_;
		nomDuFichier_ = image.nomDuFichier_;
		hauteur_ = image.hauteur_;
		largeur_ = image.largeur_;
		taille_ = image.taille_;
		typeImage_ = image.typeImage_;
		for (unsigned int i =0 ; i<taille_; i++)
			pixels_[i] = image.pixels_[i];
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Image& image) {
	os << "Nom de l'image: " << image.obtenirNomImage().c_str() << endl;
	os << "Chemin de l'original: " << image.obtenirCheminDuFichier().c_str() << endl;
	os << "Taille de l'image: " << image.obtenirTaille() << " pixels" << endl;
	os << "Résolution de l'image: " << image.obtenirNombrePixelLargeur() << " x " << image.obtenirNombrePixelHauteur() << endl;
	os << "Type de l'image: " << image.obtenirTypeEnString().c_str() << endl;
	os << "---------------------------------------------" << endl;
    return os;
}

bool Image::operator==(const Image& image) {
    bool retour = true;

    if (image.obtenirNomImage() != nomDuFichier_ ||
        image.obtenirNombrePixelHauteur() != hauteur_ ||
        image.obtenirNombrePixelLargeur() != largeur_) {
        retour = false;
    }
    else {
        for(unsigned int i = 0; i < taille_; i ++) {
            if (image.pixels_[i] != pixels_[i]){
                return false;
            }
        }
    }

    return retour;
}

bool Image::operator==(const string& nom) {
    return(nomDuFichier_ == nom);
}

bool operator==(const string& nom,  Image& image) {
    return image == nom;
}

// Accesseurs
std::string Image::obtenirCheminDuFichier() const {
    return cheminVersImageOriginale_;
}

std::string Image::obtenirNomImage() const {
    return nomDuFichier_;
}

unsigned int Image::obtenirNombrePixelHauteur() const {
    return hauteur_;
}

unsigned int Image::obtenirNombrePixelLargeur() const {
    return largeur_;
}

unsigned int Image::obtenirTaille() const {
    return taille_;
}

TypeImage Image::obtenirType() const {
    return typeImage_;
}

// Muteateurs
void Image::changerNomImage(const std::string &nom) {
    nomDuFichier_ = nom;
}

//Conversion
void Image::convertirNB() {
	if (typeImage_ == Couleur) {
		for (unsigned int i = 0; i < taille_; i++)
		{
			PixelCouleur* pixelCouleur = static_cast<PixelCouleur*> (pixels_[i]);
			PixelBN* pixelNB = new PixelBN(pixelCouleur->convertirPixelBN());
			delete pixels_[i];
			pixels_[i] = pixelNB;
			delete pixelCouleur;
		}
	}
	else if (typeImage_ == Gris) {
		for (unsigned int i = 0; i < taille_; i++)
		{
			PixelGris* pixelGris = static_cast<PixelGris*> (pixels_[i]);
			PixelBN* pixelNB = new PixelBN(pixelGris->convertirPixelBN());
			delete pixels_[i];
			pixels_[i] = pixelNB;
			delete pixelGris;
		}
	}
	else
		cout << "Conversion impossible l'image est deja NB";
	
}
void Image::convertirGris() {
	if (typeImage_ == Couleur) {
		for (unsigned int i = 0; i < taille_; i++)
		{
			PixelCouleur* pixelCouleur = static_cast<PixelCouleur*> (pixels_[i]);
			PixelGris* pixelGris = new PixelGris(pixelCouleur->convertirPixelGris());
			delete pixels_[i];
			pixels_[i] = pixelGris;
			delete pixelCouleur;
		}
	}
	else if (typeImage_ == NB) {
		for (unsigned int i = 0; i < taille_; i++)
		{
			PixelBN* pixelNB = static_cast<PixelBN*> (pixels_[i]);
			PixelGris* pixelGris = new PixelGris(pixelNB->convertirPixelGris());
			delete pixels_[i];
			pixels_[i] = pixelGris;
			delete pixelNB;
		}
	}
	else
		cout << "Conversion impossible l'image est deja Gris";

}
void Image::convertirCouleur() {
	if (typeImage_ == Gris) {
		for (unsigned int i = 0; i < taille_; i++)
		{
			PixelGris* pixelGris = static_cast<PixelGris*> (pixels_[i]);

			unchar[] tableauRGB = pixelGris->convertirPixelCouleur();
			// A VOIR!!


			PixelCouleur* pixelCouleur = new PixelCouleur();
			delete pixels_[i];
			pixels_[i] = pixelCouleur;
			delete pixelCouleur;
			delete pixelGris;
		}
	}
	else if (typeImage_ == NB) {
		for (unsigned int i = 0; i < taille_; i++)
		{
			PixelBN* pixelNB = static_cast<PixelBN*> (pixels_[i]);
			PixelCouleur* pixelCouleur = new PixelCouleur();
			PixelCouleur pixelTmp = pixelNB->convertirPixelCouleur();
			pixelCouleur = &pixelTmp;
			delete pixels_[i];
			pixels_[i] = pixelNB;
			delete pixelCouleur; // a vérif.
			delete pixelNB;
		}
	}
	else
		cout << "Conversion impossible l'image est deja NB";

}
// Retourne le type de l'image en string
string Image::obtenirTypeEnString() const {
    /*
     * Retourne:
     *    Couleurs          -> TypeImage::Couleurs
     *    Nuances de Gris   -> TypeImage::Gris
     *    Noir et Blanc     -> TypeImage::NB
     */
    string type_en_string;
    switch(typeImage_) {
        case TypeImage::Couleurs:
            type_en_string = "Couleurs";
            break;
        case TypeImage::Gris:
            type_en_string = "Nuances de Gris";
            break;
        case TypeImage::NB:
            type_en_string = "Noir et Blanc";
            break;
    }
    return type_en_string;
}

// Lit une image .bmp avec encodage 24 bits et la stock dans pixels_
void Image::lireImage(const string& nomDuFichier, const TypeImage& type) {
    // Si pixels_ n'est pas nul, les pixels sont detruits
    if(pixels_ != nullptr) {
        unsigned int i;
        for(i = 0; i < taille_; i++) {
            delete pixels_[i];
            pixels_ = nullptr;
        }
        delete[] pixels_;
    }

    // Ouverture du stream entrant
    ifstream bmpIn(cheminVersImageOriginale_.c_str(), ios::in | ios::binary);

    // Si l'ouverture a echouee on quitte la fonction
    if(!bmpIn.is_open()) {
        cerr << "Erreur, le fichier " << nomDuFichier << " n'a pas pu etre ouvert." << endl;
        exit(9);
    }
    
    // Lecture de l'en-tete du fichier .bmp
    char info[54];

    bmpIn.read(info, 54);

    int offset = *(int*)&info[10];

    // Enregistrement des informations pertinentes
    largeur_ = *(unsigned int*)&info[18];
    hauteur_ = *(unsigned int*)&info[22];

    short bytes = *(short*)&info[28];

    // Verification de l'encodage de l'image
    if (bytes != 24) {
        cerr << "This bmp is a " << bytes << " and this program only supports 24 bytes bmp files" << endl;
        exit(10);
    }

    // Enregistrement de la taille
    taille_ = largeur_ * hauteur_;

    // Envoit du curseur aux donnees RGB
    bmpIn.seekg(offset);

    // Preparation a la lecture
    unsigned int x, y, pos = 0;
    char tmp[3];
    pixels_ = new Pixel*[taille_];
    unsigned int moyenne;
    // Lecture des donnees RGB de l'image
    for (y = 0; y < hauteur_; y++) {
        for (x = 0; x < largeur_; x++) {
            int indice = (hauteur_ - 1 - y) * largeur_ + x;
            // Lit les pixels du bmp en ordre b g r
            bmpIn.read(tmp, 3);
            switch(type) {
                case TypeImage::Couleurs:
                    pixels_[indice] = new PixelCouleur((unchar)tmp[2], (unchar)tmp[1], (unchar)tmp[0]);
                    break;
                case TypeImage::Gris:
                    moyenne = (unchar)tmp[Couleur::R] + (unchar)tmp[Couleur::G] + (unchar)tmp[Couleur::B];
                    moyenne /= 3;
                    pixels_[indice] = new PixelGris((unchar)moyenne);
                    break;
                case TypeImage::NB:
                    moyenne = (unchar)tmp[Couleur::R] + (unchar)tmp[Couleur::G] + (unchar)tmp[Couleur::B];
                    moyenne /= 3;
                    pixels_[indice] = new PixelBN(moyenne > 127);
                    break;
            }
            pos += 3;
        }
        while (pos % 4) {
            char tmp;
            bmpIn.read(&tmp, 1);
            pos += 1;
        }
    }

    // Fermeture du stream d'entre
    bmpIn.close();
 
}

// Ecriture de l'image sur disque
void Image::sauvegarderImage(const string &nomDuFichier) {

    // Ouverture d'un stream de sortie
    ofstream bmpOut(nomDuFichier.c_str(), ios::out | ios::binary);
    if(!bmpOut.is_open()) {
        cerr << "Erreur lors de la tentative d'ecriture du fichier." << endl;
        exit(12);
    }
    
    // Preparation a l'ecriture
    unsigned char *rgb = new unsigned char[taille_ * 3];
    unchar valeur;
    PixelBN* pbn;
    PixelGris* pg;

    // Creation d'un tableau comportant toutes les donnees de l'image
    for (unsigned int i = 0; i < taille_; i++) {
        switch (pixels_[i]->getType()) {
        case TypePixel::Couleur:
            rgb[i * 3] = (static_cast<PixelCouleur*> (pixels_[i]))->retournerR();
            rgb[i * 3 + 1] = (static_cast<PixelCouleur*> (pixels_[i]))->retournerG();
            rgb[i * 3 + 2] = (static_cast<PixelCouleur*> (pixels_[i]))->retournerB();
            break;
        case TypePixel::NoireBlanc:
            pbn = static_cast<PixelBN*> (pixels_[i]);
            if (pbn->obtenirDonnee()) {
                valeur = (unchar)VALEUR_MAX_PIXEL;
            }
            else {
                valeur = (unchar)VALEUR_MIN_PIXEL;
            }
            rgb[i * 3] = rgb[i * 3 + 1] = rgb[i * 3 + 2] = valeur;
            break;
        case TypePixel::NuanceDeGris:
            pg = static_cast<PixelGris*> (pixels_[i]);
            valeur = (unchar) pg->obtenirDonnee();
            rgb[i * 3] = rgb[i * 3 + 1] = rgb[i * 3 + 2] = valeur;
            break;
        }

    }

    // Ajout de l'en-tete de fichier et rearrangement au format .bmp
    unsigned char* output;
    size_t output_size = bitmap_encode_rgb(rgb, largeur_, hauteur_, &output);
    // Ecriture de l'image sur le disque
    bmpOut.write((char*)output, output_size);
    // Fermeture du descripteur de fichier
    bmpOut.close();
    // Liberation memoire
    delete[] rgb;
    delete[] output;
}