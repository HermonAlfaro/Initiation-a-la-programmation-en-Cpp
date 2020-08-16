#include <iostream>
#include <cmath> // bibliotheque standard du C++
using namespace std; // permet d'utiliser cout et endl plutot que std::cout, std::endl

 
int main()
{
	// variables: type identificateur(valeur_initiale);
	int n(4);
	int n_carre;
	double x(1.0);
	int p(1), q(1);
	
	// affectations. nom_de_variable = expression; 
	// L'expression peut etre une valeur littérale ou une formule, mais avec le meme type 
	n_carre = n * n;
	
	double x4(1e-3); // 0.001
	
	// déclaration de constantes: const type identificateur(valeur_initiale);
	const double vitesse_de_la_lumiere(299792.458);
	
	
	// math
	double angle;
	double s;
	
	angle = 10*3.14159 / 180;
	s = sin(angle);
	
	
	cout << "Entrez une valeur por n" << endl;
	cin >> n;
	cout << "La variable n contient " << n << "." << endl;
	
	cout << "Sin(angle)" << s << endl;
	
	cout << "La variable n contient " << n << "." << endl;
	cout << "Le double de " << n << " est " << 2*n << endl;
	cout << n_carre << endl;
	cout << x << endl;
	cout << p << endl;
	cout << q << endl;
	cout << vitesse_de_la_lumiere << endl;
	
	
	
	
	
	
	return 0;
}
