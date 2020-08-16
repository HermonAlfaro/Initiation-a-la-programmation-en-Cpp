#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int main()
{
// les trois coefficients
double a0(0.0);
double a1(0.0);
double a2(0.0);
cout << "Entrez a2, puis a1, puis a0 :" << endl;
cin >> a2 >> a1 >> a0;
// calculs intermédiaires
const double Q((3.0 * a1 - a2*a2) / 9.0);
const double R((9.0 * a2 * a1 - 27.0 * a0 - 2.0 * a2*a2*a2) / 54.0);
const double D(Q*Q*Q + R*R);
double S;
double T;
// solutions
double z1;
double z2;
double z3;
if (D < 0.0) { // test du déterminant
// cas de trois racines réelles
T = acos( R / sqrt(-Q*Q*Q) );
z1 = 2.0 * sqrt(-Q) * cos(T/3.0) - a2 / 3.0;
z2 = 2.0 * sqrt(-Q) * cos( (T+2.0*M_PI) / 3.0 ) - a2 / 3.0;
z3 = 2.0 * sqrt(-Q) * cos( (T+4.0*M_PI) / 3.0 ) - a2 / 3.0;
cout << "Trois racines ( " << z1 << " , " << z2
<< " , " << z3 << " )" << endl;
} else {
// cas de moins de trois racines réelles
// calcul de S
double s(R+sqrt(D));
if (s == 0.0) { S = 0.0; }
else if (s < 0.0) { S = -pow(-s, 1.0/3.0); }
else if (s > 0.0) { S = pow( s, 1.0/3.0); }
// calcul de T
s = R - sqrt(D);
if (s == 0.0) { T = 0.0; }
else if (s < 0.0) { T = -pow(-s, 1.0/3.0); }
else if (s > 0.0) { T = pow( s, 1.0/3.0); }
// calcul des solutions
z1 = -a2 / 3.0 + S + T;
if ((D == 0.0) and (S+T != 0.0)) {
z2 = -a2 / 3.0 - (S + T) / 2.0;
cout << "Deux racines..." << endl
<< " l'une simple : " << z1 << endl
<< " l'autre double : " << z2 << endl;
cout << "(pour info D = " << D << ")" << endl;
} else {
cout << "Une seule racine : " << z1 << endl;
}
}
return 0;
}
