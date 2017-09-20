#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
public:
	//Constructeur par default
	Pixel();
	//Constructeur par paramètre
	Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu);
	//Destructeur 
	//~Pixel();   pas necessaire car pas de pointeur

	//Acesseur
	unsigned int getTauxRouge() const;
	unsigned int getTauxVert() const;
	unsigned int getTauxBleu() const;

	//Mutateur
	void modifierTeinteRouge(int incrementRouge);
	void modifierTeinteVert(int incrementVert);
	void modifierTeinteBleu(int incrementBleu);

	//Methodes
	void afficherPixel() const;

private:
	unsigned int tauxRouge_ ;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};

#endif