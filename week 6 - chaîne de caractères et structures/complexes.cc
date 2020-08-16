#include <iostream>
using namespace std;

struct Complexe {
  double x;
  double y;
};

// Solution simple
void affiche(Complexe z) 
{
  cout << "(" << z.x << "," << z.y << ")";

  // autre solution :  cout << z.x << "+" << z.y << "i";
}

// Solution plus complexe mais plus élégante
void affiche2(Complexe z)
{
  if ((z.x == 0.0) and (z.y == 0.0)) {
    cout << "0";
    return;
  }

  if (z.x != 0.0) {
    cout << z.x;
    if (z.y > 0.0)
      cout << "+";
  }
  if (z.y != 0.0) {
    if ((z.x == 0.0) and (z.y == -1.0))
      cout << "-";
    else if (z.y != 1.0)
      cout << z.y;
    cout << "i";
  }
}

Complexe addition(Complexe z1, Complexe z2)
{
  return { z1.x + z2.x, z1.y + z2.y };
}

Complexe soustraction(Complexe z1, Complexe z2)
{
  return { z1.x - z2.x, z1.y - z2.y };
}

Complexe multiplication(Complexe z1, Complexe z2)
{
  return { z1.x * z2.x - z1.y * z2.y ,
           z1.x * z2.y + z1.y * z2.x };
}

Complexe division(Complexe z1, Complexe z2)
{
  const double r(z2.x*z2.x + z2.y*z2.y);
  return { (z1.x * z2.x + z1.y * z2.y) / r ,
	   (z1.y * z2.x - z1.x * z2.y) / r };
}

int main()
{
  Complexe un = { 1.0, 0.0 };
  Complexe i  = { 0.0, 1.0 };

  affiche(un); cout << " + "; affiche(i); cout << " = ";
  Complexe j(addition(un, i));
  affiche(j); cout << endl;

  affiche(i); cout << " * "; affiche(i); cout << " = ";
  affiche(multiplication(i,i)); cout << endl;

  affiche(j); cout << " * "; affiche(j); cout << " = ";
  Complexe z(multiplication(j,j));
  affiche(z); cout << endl;

  affiche(z); cout << " / "; affiche(i); cout << " = ";
  affiche(division(z,i)); cout << endl;

  z= { 2.0, -3.0 };
  affiche(z); cout << " / "; affiche(j); cout << " = ";
  affiche(division(z,j)); cout << endl;

  return 0;
}
