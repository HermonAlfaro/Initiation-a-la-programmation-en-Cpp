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
	Maison& maison;
	
};

void affiche(Personne personne);


int main()
{
	Maison m1({"Case siempre viva 123"});
	Maison m2({"270 rue saint jacques"});
	
	
	Personne hermon = {"Hermon", m1};
	Personne cata = {"Cata", m2};
	Personne vale = {"Vale", m2};
	Personne fabio = {"Fabio", m1};
	Personne daniel = {"Daniel", m1};
	Personne fran = {"Fran", m2};
	
	
	vector<Personne> personnes({hermon, cata, vale, fabio, daniel, fran});
	
	for(auto& p :  personnes)
	{
		affiche(p);
	}

	return 0;
}

void affiche(Personne personne)
{
	cout << personne.nom << " habite " << personne.maison.adresse << endl;
	
}
