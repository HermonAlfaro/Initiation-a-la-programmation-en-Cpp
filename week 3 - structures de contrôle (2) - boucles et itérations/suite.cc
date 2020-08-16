#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
	for (int i(debut); i <= fin; ++i)
	{
		// valeur initiale
		int n0(i);
		
		// nombre d'operations
		int k(0);
		
		do
		{
			if (n0%3==0)
			{
				n0 += 4;
			}
		
			else if (n0%4==0)
			{
				n0 /= 2;
			}
			else 
			{
				n0 -= 1;
			}
		k += 1;
		}
		while (n0!=0);
		cout <<  i << " -> " << k << endl;
	}

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
