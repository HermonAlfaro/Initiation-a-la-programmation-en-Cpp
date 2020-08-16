#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
	nombre = 10 * nombre + chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{

	ajouter_chiffre_droit(nombre, repetitions_chiffre);
	ajouter_chiffre_droit(nombre, chiffre);
		
}

int lire_et_dire(int nombre)
{
	//cout << "nombre : " << nombre << endl;
	//cout << "___________________" << endl;
	
	int resultat(0);
	int ref_chiffre(separer_chiffre_gauche(nombre));
	int chiffre;
	int rep(1);
		
	while (nombre>0)
	{
		//cout << "nombre : " << nombre << endl;
		//cout << "ref chiffre : " << ref_chiffre << endl;
		//cout << "rep : " << rep << endl;
		//cout << "resultat : " << resultat << endl;
		
		//cout << "___________________" << endl;
		
		chiffre = separer_chiffre_gauche(nombre);
		
		if (chiffre==ref_chiffre)
		{
			rep += 1;
		}
		
		else
		{
			dire_chiffre(resultat, rep, ref_chiffre);
			ref_chiffre = chiffre;
			rep = 1;
		}
				
	}
	
	dire_chiffre(resultat, rep, ref_chiffre);
	
		
	return resultat;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
