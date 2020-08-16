#include <iostream>
#include <cmath>
using namespace std;

constexpr g(9.81);

int main()
{
	
	// hateur initiale
	double H0;
	do
	{
		cout << " H0 > 0 : ";
		cin >> H0;
	}
	while (H0 <= 0.0);
	
	// coefficient de rebond
	double eps;
	do
	{
		cout << "0 <= eps <= 1 :  ";
		cin >> eps;
	}
	while ((eps < 0.0) or (eps >= 1.0));
	
	// nombre de rebonds
	int NBR;
	do
	{
		cout << "Nombre de rebonds : ";
		cin >> NBR;
	}
	while (NBR < 0);
	
	// variables
	double v(sqrt(2 * H0 * g));
	
	double v1;
	double h1;
	
	for (int i(1); i <=NBR; ++i)
	{		
		v1 = eps * v;
		h1 = (v1 * v1) / (2 * g);
		
		v = v1;
	} 
	
	cout <<"Hateur finale : " << h1 << endl;
	
	return 0;
}
