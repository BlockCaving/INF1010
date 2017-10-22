//
// Nom du fichier: main.cpp
// Contenu : execution du programme principal
// Date de modification : 27 septembre 2017
//

// Si plateforme windows
#ifdef _WIN32 
    #include <Windows.h>
    #define PAUSE system("PAUSE")
// S'il s'agit d'une plateforme UNIX
#else
    #include <unistd.h>
    #define PAUSE sleep(0)
#endif

#include <iostream>
#include <string>
#include "Pixel.h"
#include "GroupeImage.h"
#include "Image.h"
#include "PixelBN.h"
#include "PixelCouleur.h"
#include "PixelGris.h"
#include "TypeImage.h"
#include "TypePixel.h"

using namespace std;

int main() {
	
	// Chemin vers les images
    string cheminLoad = "../Ensemble d'images/Originale/";
	// Nom des 6 images dans un tableau de string
    string image[6] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "WiC.bmp"};

	// Creer un groupe d'image
	cout << "**************************************************" << endl;
	cout << "Creation du groupe d'image" << endl;
	cout << "**************************************************" << endl << endl;
	
	PixelCouleur test = PixelCouleur(60, 60, 60);
	cout << test.convertirPixelBN() << endl;
	cout << test.convertirPixelGris() << endl;

	GroupeImage groupe1 = GroupeImage();

	// Ajouter toutes les images au groupe en tant qu'image couleurs
	for (int i = 0; i < 6; i++) {
		Image* img = new Image(cheminLoad + image[i], Couleurs);
		groupe1 += img;
	}

	groupe1.retirerImage("Breaking - Bad.bmp");

	// Afficher le contenu du groupe d'image
	cout << groupe1;

	// Convertir toutes les images en couleurs
	groupe1.toutMettreEnCouleur();

	// Enregistrer toutes les images convertie
	groupe1.toutEnregistrer("../Ensemble d'images/");

	// Convertir toutes les images en Nuance de Gris
	groupe1.toutMettreEnGris();

	// Enregistrer toutes les images grises
	groupe1.toutEnregistrer("../Ensemble d'images/");

	// Convertir toutes les images en Noir et Blanc
	groupe1.toutMettreEnNB();

	// Enretisgrer toutes les images
	groupe1.toutEnregistrer("../Ensemble d'images/");

	// Permet d'afficher le contenu de la console
	PAUSE;

	// Fin du programme
    return 0;
	
}