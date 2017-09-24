/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: Septembre 2017
 * Auteur: Claude GAGNE - Steven NICOULEAU
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
	for (int i = 0; i < 9; i++) {						//boucle créant 9 pixels rouges
		pixelRouge[i] = Pixel(255, 0, 0);
	};

	//2-Creez 9 pixels verts (0,255,0)
	for (int j = 0; j < 9; j++) {						//boucle créant 9 pixels verts
		pixelVert[j] = Pixel(0, 255, 0);
	};

	//3- Creez une image de taille 3*3 
	Image img1 = Image("IMAGE1", 3 , 3);
	
	//4- Ajouter à l'image créée à l'étape 3 les pixels rouges

	int cpt = 0; //parcours le tableau de pixel rouge
	for (unsigned int k = 0; k < img1.getNombrePixelHauteur(); k++) {			// parcourt toute l'image
		for (unsigned int l = 0; l < img1.getNombrePixelLargeur(); l++){		// pour la remplir avec les pixels rouges
			img1.ajouterPixel(pixelRouge[cpt], k, l);
			cpt++;
		};	
	};

	//5- Creez une deuxième image de taille 3*3 
	Image img2 = Image("IMAGE2", 3, 3);

	//6- Ajouter à l'image créées à l'étape 3 les pixels verts

	cpt = 0; //parcours le tableau de pixel vert
	for (unsigned int m = 0; m < img2.getNombrePixelHauteur(); m++) {			// parcourt toute l'image
		for (unsigned int n = 0; n < img2.getNombrePixelLargeur(); n++) {		// pour la remplir avec les pixels verts
			img2.ajouterPixel(pixelVert[cpt], m, n);
			cpt++;
		};
	};

	//7- Creez un groupe d'image avec une capacite de 3
	GroupImage groupe1 = GroupImage("Rouge et Verte", 3);

	//8- Ajoutez les deux images crées precédament au groupe
	groupe1.ajouterImage(img1);
	groupe1.ajouterImage(img2);

	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	Image imgModif1 = groupe1.obtenirImage(0);				//passe par imgModif1 car obtenirImage() est une const
	imgModif1.augmenterTeintePixel(1, 1, 50, 'B');			//elle ne peut donc pas modifier d'attribut
	
	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	imgModif1.augmenterTeintePixel(1, 1, -255, 'R');
	
	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités  
	Image imgModif2 = groupe1.obtenirImage(1);
	imgModif2.augmenterTeintePixel(2, 1, 100, 'B');

	//12- Affichez les images de ce groupe
	cout << "*** Groupe d'images de type: " << groupe1.obtenirType() << " avec teinte modifiee ***" << endl;
	groupe1.afficherImages();
	
	//13- Doublez la taille de la premiere image du groupe en largeur	
	groupe1.doublerTailleImageEnLargeur(0);

	//14- Doublez la taille de la deuxieme image du groupe en hauteur
	groupe1.doublerTailleImageEnHauteur(1);
	
	//15- Afficher cette image 
	cout << "*** Seconde image avec taille modifiee ***" << endl;
	groupe1.obtenirImage(1).afficherImage();
	
	//Désalocation de la mémoire
	img1.~Image();
	img2.~Image();
	groupe1.~GroupImage();
	
	system("pause");
	return 0;
}