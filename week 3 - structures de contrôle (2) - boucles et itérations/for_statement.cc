#include <iostream>
using namespace std;

int main()
{
	cout << "Table de multiplication par 5" << endl;
	// boucle for: quand le nombre de répetitions est connu avant d'entre dans la boucle
	// for(déclaration_et_initialisation; condition; incrémentation) {bloc}
	for(int i(1); i <= 10; ++i)
	{
		cout << "5 multiplie par " << i <<" vaut " << 5 * i << endl;  
	}
	
	for(int p(0); p < 10; p += 2)
	{
		// corps
		cout << p << endl;
	}
	
	for(int k(10); k > 0; --k)
	{
		// corp
		cout << k << endl;
	}
	// if la condition est toujour vrai, la boucle for n'arrete pas
	
	
	
	return 0;
}
