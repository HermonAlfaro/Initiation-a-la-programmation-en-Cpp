#include <iostream>
#include <cmath>
using namespace std;

// if (cond) {instructions} else {instructions}
// Opérateurs logiques : and (aussi &&), or (ausii ||), not(cond) (aussi !(cond))
// variables bololéen: bool name(cond), valeurs: true and false et les opérateus logiques

// Résolution de polynomes de degré 2
int main() 
{
	double a(0.0);
	double b(0.0);
	double c(0.0);
	
	cout << "Entrez une valeur non nulle pour a :";
	cin >> a;
	if (a==0.0) 
	{
		// cerr est comme cout, mais pour les messages d'erreur.
		cerr << "Erreur : a est null :-(" << endl;
		return 1; // on quitte le programme !
	}
	cout << "Entrez une valeur pour b:";
	cin >> b;
	cout << "Entrez une valeur pour c:";
	cin >> c;
	
	// déterminant
	double delta(b * b - 4.0 * a * c);
	
	if (delta < 0.0)
	{
		cout << "Pas de solutions réelles." << endl;
	}
	else if (delta > 0.0)
	{
		cout << "Deux solutions : " << (-b-sqrt(delta))/(2.0*a)
			 << " et " << (-b+sqrt(delta))/(2.0*a) << endl;	
	}
	else
	{
			cout << "Une solution unique : " << -b/(2.0*a) << endl;
	}

	
	return 0;
}
 
