#include <iostream>
using namespace std;

int demander_nombre(int a, int b)
{
  /* échange les arguments s'ils n'ont pas été donnés dans *
   * le bon ordre.                                         */
  if (a > b) { int tmp(b); b=a; a=tmp; }

  int res;
  do {
    cout << "Entrez un nombre entier compris entre "
         << a << " et " << b <<" : ";
    cin >> res;
  } while ((res < a) or (res > b));

  return res;
}

int main () {
  double valeur1(3.14159265358);
  double valeur2(1.42857142857);
  double valeur3(-12.344556667);
  double* choix(0);

  switch (demander_nombre(1,3)) {
  case 1: choix = &valeur1; break;
  case 2: choix = &valeur2; break;
  case 3: choix = &valeur3; break;
  }

  cout << "Vous avez choisi " << *choix << endl;

  return 0;
}
