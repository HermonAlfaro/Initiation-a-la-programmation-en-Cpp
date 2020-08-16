#include <iostream>
#include <vector>
#include <utility> // pour swap
using namespace std;

typedef int type_el;
typedef vector<type_el> Tableau;

void affiche(const Tableau&  tab)
{
  for (auto el : tab) cout << el << " ";
}

void tri_Shell(Tableau& tab)
{
  for (size_t k(tab.size()/2); k >= 1; k /= 2)
    for (size_t i(k+1); i <= tab.size(); ++i) {
      int j(i-k);
      while (j > 0) {
	if (tab[j-1] > tab[j+k-1]) {
	  swap(tab[j-1], tab[j+k-1]);
          affiche(tab); cout << endl;
	  j -= k;
	} else {
	  j = 0;
	}
      }
    }
}

int main()
{
  Tableau tab = { 3, 5, 12, -1, 215, -2, 17, 8, 3, 
                  5, 13, 18, 23, 5, 4, 3, 2, 1    };
  tab = { 5, 4, 1, 2, 3 };
  cout << "A trier  : "; affiche(tab); cout << endl;
  tri_Shell(tab);
  cout << "Résultat : "; affiche(tab); cout << endl;
  return 0;
}
