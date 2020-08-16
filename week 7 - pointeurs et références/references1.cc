#include <iostream>
using namespace std;

struct Maison {
  string adresse;
};

struct Personne {
  string nom;
  Maison& home;
};

void affiche(const Personne& p) {
  cout << p.nom << " habite " << p.home.adresse << endl;
}

int main()
{
  Maison m1 = { "12 rue du chateau" };
  Personne p1 = { "Pierre", m1 };
  Personne p2 = { "Paul"  , m1 };

  Maison m2 = { "13 rue du chateau" };
  Personne p3 = { "Steve", m2 };
  Personne p4 = { "Sofia", m2 };

  affiche(p1);  affiche(p2);
  affiche(p3);  affiche(p4);

  return 0;
}
