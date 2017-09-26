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
#include <vector>

using namespace std;

/*
TODO : Veuillez répondre aux question ici
1)
2)
3)
*/

int main()
{

	vector <Pixel> pixelRouge;
	vector <Pixel> pixelVert;

	//1- Creez 9 pixels rouge  (255,0,0)	 
	for (int i = 0; i < 9; i++) {						//boucle créant 9 pixels rouges 
		pixelRouge.push_back(Pixel(255, 0, 0));
	};
	
		//2-Creez 9 pixels verts (0,255,0) 
	for (int j = 0; j < 9; j++) {						//boucle créant 9 pixels verts 
		pixelVert.push_back(Pixel(0, 255, 0));
	};
	

	//3- Creez une image de taille 3*3 
	Image img1("IMAGE 1", 3, 3);

	//4- Ajouter à l'image créées à l'étape 3 les pixels rouges
 	int cpt = 0; //parcours le tableau de pixel rouge 
	for (unsigned int k = 0; k < img1.obtenirNombrePixelLargeur(); k++) {			// parcourt toute l'image 
		for (unsigned int l = 0; l < img1.obtenirNombrePixelHauteur(); l++) {		// pour la remplir avec les pixels rouges 
			img1.ajouterPixel(pixelRouge[cpt], k, l);
			cpt++;

		}
	}

	//5- Creez une deuxième image de taille 3*3 
	Image img2("IMAGE 2", 3, 3);
	
	//6- Ajouter à l'image créées à l'étape 3 les pixels verts
	cpt = 0; //parcours le tableau de pixel rouge 
	for (unsigned int k = 0; k < img2.obtenirNombrePixelLargeur(); k++) {			// parcourt toute l'image 
		for (unsigned int l = 0; l < img2.obtenirNombrePixelHauteur(); l++) {		// pour la remplir avec les pixels rouges 
			img2.ajouterPixel(pixelVert[cpt], k, l);
			cpt++;

		}
	}
	
	//7- Creez un groupe d'image avec une capacite de 3
	GroupImage groupe1("GROUPE 1", 3);

	cout << (img1 == img2);
	cout << (img1 == img1);


	//8- Ajoutez les deux images crées precédament au groupe
	
	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	 
	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	
	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités  
	
	//12- Afficher le groupe d'image
	
	//13- Supprimer la premiere image du groupe d'image
	
	//14- Afficher le groupe d'image
	
	cout << endl;
	system("Pause");
	return 0;
}