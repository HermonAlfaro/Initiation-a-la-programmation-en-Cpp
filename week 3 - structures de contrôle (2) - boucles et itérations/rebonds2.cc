#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// constants 
	// accéleration gravitationnelle
	double g(9.81);
	
	// hateur initiale
	double H0;
	
	// coefficient de rebond
	double eps;
	
	// hauteur finale
	double h_fin;
	
	// demande de valeurs
	cout << "Hauteur initiale H0 : ";
	cin >> H0;
	
	cout << "Coefficient de rebond eps : ";
	cin >> eps;
	
	cout << "Hauteur finale desiree : ";
	cin >> h_fin;
	
	// variables
	double v(sqrt(2 * H0 * g));
	double v1;
	double h1;
	int NBR(0);
	
	
	do 
	{
		v1 = eps * v;
		h1 = (v1 * v1) / (2 * g);
		v = v1;
		
		NBR += 1;
	}
	while (h1 > h_fin);
	
	cout << "Nombre de rebonds : " << NBR << endl; 
	
	return 0;
}
