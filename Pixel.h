#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
using namespace std;

class Pixel
{
public:
	Pixel();
	~Pixel();

	Pixel(unsigned int tauxRouge,unsigned int tauxVert, unsigned int tauxBleu);

	void modifierTeinteRouge( int incrementRouge);
	void modifierTeinteVert( int incrementVert);
	void modifierTeinteBleu(int incrementBleu);

	unsigned int obtenirTauxRouge() const;
	unsigned int obtenirTauxVert() const;
	unsigned int obtenirTauxBleu() const;

	//Operateur
	friend ostream& operator<<(ostream& o, const Pixel& pixel);
	bool operator==(const Pixel& pixel);
	bool operator==(char charac);
	friend bool operator==(char charac, const Pixel& pixel);

private:
	unsigned int tauxRouge_ ;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};

#endif