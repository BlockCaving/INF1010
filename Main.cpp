/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: Septembre 2017
 * Auteur: 
**************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
	Pixel pixelRouge[9];
	Pixel pixelVert[9];

	//1- Creez 9 pixels rouge  (255,0,0)	
	for (int i = 0; i < 9; i++) {
		pixelRouge[i] = Pixel(255, 0, 0);
		pixelRouge[i].afficherPixel();
	};
	cout << endl;
	//2-Creez 9 pixels verts (0,255,0)
	for (int j = 0; j < 9; j++) {
		pixelVert[j] = Pixel(0, 255, 0);
		pixelVert[j].afficherPixel();
	};
	cout << endl;
	//3- Creez une image de taille 3*3 
	Image img1 = Image("IMAGE1", 3 , 3);
	
	//4- Ajouter à l'image créée à l'étape 3 les pixels rouges
	
	int cpt = 0; //parcours le tableau de pixel rouge
	for (unsigned int k = 0; k < img1.getNombrePixelHauteur(); k++) {
		for (unsigned int l = 0; l < img1.getNombrePixelLargeur(); l++){
			img1.ajouterPixel(pixelRouge[cpt], k, l);
			cpt++;
		};	
	};
	img1.afficherImage();
	//5- Creez une deuxième image de taille 3*3 
	Image img2 = Image("IMAGE2", 3, 3);

	//6- Ajouter à l'image créées à l'étape 3 les pixels verts

	cpt = 0; //parcours le tableau de pixel vert
	for (unsigned int k = 0; k < img2.getNombrePixelHauteur(); k++) {
		for (unsigned int l = 0; l < img2.getNombrePixelLargeur(); l++) {
			img2.ajouterPixel(pixelVert[cpt], k, l);
			cpt++;
		};
	};
	img2.afficherImage();
	//7- Creez un groupe d'image avec une capacite de 3
	GroupImage groupe1 = GroupImage("Type 1", 3);

	//8- Ajoutez les deux images crées precédament au groupe
	cout << "Ajout image";
	cout << endl;
	groupe1.ajouterImage(img1);
	groupe1.ajouterImage(img2);
	
	cout << "Groupe image";
	cout << endl;
	groupe1.afficherImages();

	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	groupe1.obtenirImage(0).augmenterTeintePixel(1,1,50,'B');
	
	//img1.afficherImage();
	//groupe1.obtenirImage(0).afficherImage();
	//groupe1.afficherImages();
	//cout << groupe1.;

	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	
	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités  
	
	//12- Affichez les images de ce groupe
	
	//13- Doublez la taille de la premiere image du groupe en largeur	

	//14- Doublez la taille de la deuxieme image du groupe en hauteur

	//15- Afficher cette image 
	
	// Destructeur
	//img1.~Image();
	//img2.~Image();
	//groupe1.~GroupImage();
	
	system("pause");
	return 0;
}