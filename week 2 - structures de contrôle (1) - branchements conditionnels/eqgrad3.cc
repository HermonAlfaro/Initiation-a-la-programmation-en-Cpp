#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
	// coefficients equation
	double a2(0.);
	double a1(0.);
	double a0(0.);
	
	cout << "a2 : ";
	cin >> a2;
	
	cout << "a1 : ";
	cin >> a1;
	
	cout << "a0 : ";
	cin >> a0;
	
	// intermediate values
	const double Q((3.* a1 - (a2 * a2))/9.);
	const double R((9. * a2 * a1 - 27. * a0 - 2 * a2*a2*a2) / 54.);
	const double D(Q*Q*Q + R*R);
	double S;
	double T;
	
	//sols
	double z1;
	double z2;
	double z3;

	
	
	if (D<0.0)
	{
		T = acos(R/sqrt(-Q*Q*Q));
		z1 = 2*sqrt(-Q)*cos(T/3.) - a2/3.;
		z2 = 2*sqrt(-Q)*cos((T + 2.0*M_PI)/3.0) - a2/3.;
		z3 = 2*sqrt(-Q)*cos((T + 4.0*M_PI)/3.) - a2/3.;
		
		cout << "3 racines : " << endl; 
		cout << z1 << endl;
		cout << z2 << endl;
		cout << z3 << endl;  
	}
	
	else
	{
		if (R + sqrt(D)==0.0){S = 0.0;}
		else if (R + sqrt(D) < 0.0) {S = - pow(-R - sqrt(D),1.0/3.0);}
		else {S = pow(R + sqrt(D),1.0/3.0);}
		
		if (R- sqrt(D)==0.0){T=0.0;}
		else if (R - sqrt(D) < 0.0) {T = - pow(-R + sqrt(D),1.0/3.0);}
		else {T = pow(R - sqrt(D),1.0/3.0);}
		
		
		z1 = (S+T - a2/3.);
		if ((D==0.0) and (S+T != 0.0))
		{
			z2 = -(S+T)/2. -a2/3.;
			cout << "2 racines : " << endl;
			cout << z1 << endl;
			cout << z2 << endl;
		
		}
		else
		{
			cout << "1 racine : " << endl;
			cout << z1 << endl;
		}
	}
	
	
	
	
	

	return 0;
}
