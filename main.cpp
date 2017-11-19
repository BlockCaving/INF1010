
#ifndef PAUSE
    #ifdef _WIN32
        #include <Windows.h>
        #define PAUSE system("PAUSE")
    #else
        #include <unistd.h>
        #define PAUSE sleep(0)
    #endif
#endif /* PAUSE */

#include <iostream>
#include <string>

#include "GroupeImage.h"
#include <queue>
#include "BaseDeDonnesSpecifique.h"
#include "Foncteur.h"
#include <functional>
#include <ctime>

using namespace  std;

int main() {

	//init rand()
	std::srand(std::time(0));

	// Chemin vers les images
	string cheminLoad = "../Ensemble d'images/Originale/";
	// Nom des 9 images dans un tableau de string
	string image[9] = { "Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "Monkey.bmp","WiC.bmp","Sloth.bmp","Green.bmp" };

	// Creer un conteneur de type QUEUE et ajouter les images dans la queue
	cout << "**************************************************" << endl;
	cout << "Creation de la file de travail" << std::endl;
	cout << "**************************************************" << endl << endl;


	queue<Image*> queue1;
	for (unsigned int i = 0; i < 9; i++) {
		Image* img = new Image(cheminLoad + image[i], Couleurs);
		queue1.push(img);																//push chaque image du tableau image[i] dans le queue
	}


	//Creez 3 GroupeImage
	GroupeImage* groupe1 = new GroupeImage();
	GroupeImage* groupe2 = new GroupeImage();
	GroupeImage* groupe3 = new GroupeImage();

	// Creez un objet de type BaseDeDonnesSpecifique et ajoutez les 3 groupes a la base de donnes
	BaseDeDonnesSpecifique base1 = BaseDeDonnesSpecifique();
	base1.ajouter(groupe1);
	base1.ajouter(groupe2);
	base1.ajouter(groupe3);

	/*Faites repartir les elements de la queue de maniere uniforme et sequentielle dans les groupe
	 Vous devez avoir la composition suivante :
		groupe 1 a les images 0,3,6
		groupe 2 a les images 1,4,7
		groupe 3 a les images 2,5,8
	 ATTENTION : la repartition doit se faire dans une seule boucle ET vous devez utiliser les fonctions de l'objet de base de donnes
	 NB: La methode pop() de queue<> ne retourne pas l'element de la structure
	*/

	cout << "**************************************************" << endl;
	cout << "CHARGEMENT DES IMAGES\n\n";
	
	//Votre implementation ici
	for (unsigned int i = 0; i < 9; i = i + 3) {
		base1.AssocierImage(groupe1, new Image(cheminLoad + queue1.front()->obtenirNomImage(), Couleurs));			//rempli la base et le groupe1
		queue1.pop();																								//vide la file pour passer à l'image suivante
		base1.AssocierImage(groupe2, new Image(cheminLoad + queue1.front()->obtenirNomImage(), Couleurs));			//rempli la base et le groupe2
		queue1.pop();																								//vide la file pour passer à l'image suivante
		base1.AssocierImage(groupe3, new Image(cheminLoad + queue1.front()->obtenirNomImage(), Couleurs));			//rempli la base et le groupe3
		queue1.pop();																								//vide la file pour passer à l'image suivante
	}

	cout << "**************************************************" << endl;
	cout << "AFFICHAGE DE LA BASE DE DONNEES\n";
	// Afficher la base de donnes au complet

	cout << base1;

	// Pour chaque groupe, generez un nombre aleatoire. Le nombre aleatoire doit toujours donner un index valide
	// ET appliquez les modifications suivantes aux images obtenues avec le nombre aleatoire
	//GROUPE 1 - Mettre en negatif
	FoncteurGenerateurNombresAlea fonctalea = FoncteurGenerateurNombresAlea(0, 3);					//constructeur par parametre du foncteur
	int aleaGroupe1 = fonctalea();																	//generation du nombre pour le groupe 1
	groupe1->obtenirImageParIndex(aleaGroupe1)->mettreEnNegatif();

	//GROUPE 2 - Mettre en gris
	int aleaGroupe2 = fonctalea();																	//generation du nombre pour le groupe 2
	groupe2->obtenirImageParIndex(aleaGroupe2)->convertirGris();

	//GROUPE 3 - Mettre en noir et blanc
	int aleaGroupe3 = fonctalea();																	//generation du nombre pour le groupe 3
	groupe3->obtenirImageParIndex(aleaGroupe3)->convertirBN();

	/*
	 *TRAITEMENT DE GROUPE 1
	 *Calculer l'intensite moyenne des images du groupe 1 et l'afficher
	 */

	cout << "**************************************************" << endl;
	cout << "CALCUL DE LA MOYENNE \n\n";
	//Votre implementation ici

	double intensiteMoyenneGroupe1 = groupe1->obtenirIntensiteMoyenne();
	cout << "Intensite moyenne du groupe 1: " << intensiteMoyenneGroupe1 << endl;
	cout << "MOYENNES DES IMAGES DANS LA BASE DE DONNES: \n";

	// Trouver toutes les images avec une intensite moyenne plus petite que la valeur trouve et
	// afficher leur nom et leur moyenne
	// ATTENTION : Faire ceci avec une boucle for intelligente 

	auto liste = base1.obtenirListImages();

	for (auto image : liste) {
		if (image->obtenirIntensiteMoyenne() < intensiteMoyenneGroupe1)								//si l'intensite de l'image est > a la moyenne du groupe
			cout << image->obtenirNomImage() << " avec moyenne de " << image->obtenirIntensiteMoyenne() << endl;			//affiche la moyenne
	}
	cout << "**************************************************" << endl << endl;
	cout << "**************************************************" << endl;
	cout << "CALCUL DE LA TAILLE \n\n";
	//Votre implementation ici
	/*
	 *TRAITEMENT DE GROUPE 2
	 * Calculer la taille moyenne des images dans le groupe 2 et afficher l'afficher
	 */
	double tailleMoyenneGroupe2 = groupe2->obtenirTailleMoyenne();
	cout << "Taille moyenne du groupe 2: " << tailleMoyenneGroupe2 << endl;

	// Afficher le nombre d'images dans la base de donnes
	cout << "Nombre d'images totales dans la base de donnes " << base1.obtenirListImages().size() << endl;

	// Trouver et afficher le nombre d'images qui ont une taille plus grande que la moyenne calculee
	// Utiliser les fonctions std::bind et std::placeholders pour effectuer le travail

	int nbrImageTailleSuperieurMoyenne = 0; 
	FoncteurObtenirTailleImage foncteurTaille;

	//Un exemple de supprimerElements 
	//suprimme tout éléments du groupe 2 ayant une taille supérieur a la moyenne
	groupe2->supprimerElements(
		std::bind(
			//Générer un opérateur > pour les entiers
			greater<int>(),
			//Le bind ci-dessous permet d'appeler la méthode obtenirTaile de la
			//Image* passée en argument du foncteur lors des appels de ce dernier dans supprimerElements
			std::bind(foncteurTaille, std::placeholders::_1), 
			tailleMoyenneGroupe2
			)
		);


	// Calculer le nombre d'images avec une taille superieure a la taille moyenne
	// ASTUCE: utilisez la STL et les fonctions de decompte conditionel

	nbrImageTailleSuperieurMoyenne = count_if(liste.begin(), liste.end(), std::bind(greater<int>(),std::bind(foncteurTaille, std::placeholders::_1),tailleMoyenneGroupe2));

	// Afficher le nombre d'images dans la base de donnes avec une taille plus grande que la moyenne
	cout << "Nombre d'images dont la taille est plus grande que la moyenne " << nbrImageTailleSuperieurMoyenne << endl;
	
	cout << "**************************************************" << endl << endl;


	/*
	 *TRAITEMENT DU GROUPE 3
	 *
	 *Mettre tout les images du groupe 3 en noir et blanc et sauvegarder
	 *ATTENTION : Vous devez utiliser la fonction generique "appliquerFoncteurUnaire"  demandee dans au TP5 et non une boucle sur les elements
	 */

	cout << "**************************************************" << endl;
	cout << "CONVERSION EN NOIR ET BLANC " << endl << endl;
	// Votre implementation ici
	groupe3->appliquerFoncteurUnaire(FoncteurMettreEnBN());
	groupe3->toutEnregistrer();

	cout << "**************************************************" << endl << endl;


    // Permet d'afficher le contenu de la console
    PAUSE;
    // Fin du programme
    return 0;
}