#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct Maison
{
	string adresse;
};

struct Personne
{
	string nom;
	Maison* maison;
	
};

void affiche(Personne personne);


int main()
{
	Maison m1({"270 Rue Saint Jacques"});
	Maison m2({"3775 Francisco Bilbao"});
	
	

	Personne cata = {"Cata", &m2};
	Personne vale = {"Vale", &m2};
	Personne hermon = {"Hermon", &m1};
	Personne fabio = {"Fabio", &m1};
	Personne daniel = {"Daniel", &m1};
	Personne fran = {"Matheus", &m1};
	
	vector<Personne> personnes({cata, vale, hermon, fabio, daniel, fran});
	
	for(auto& p :  personnes)
	{
		affiche(p);
	}
	
	// demenage
	hermon.maison = &m2;
	cout << endl;
	cout << "Hermon a retourne au Chili " << endl;
	cout << endl;
	
	for(auto& p :  personnes)
	{
		affiche(p);
	}

	return 0;
}

void affiche(Personne personne)
{
	cout << personne.nom << " habite " << (*personne.maison).adresse << endl;
	
}
