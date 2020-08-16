#include <iostream>
using namespace std;

int main()
{
	// while: quand in ne connait pas d'avance combien de fois la boucle devra etre executée
	// condition testée apres de la boucle: do {corps} while (condition); -> affichera au moins une fois le corps
	// condition testée avant d'entre dans la boucle: while (condition) {} -> ca peut rien afficher
	
	int nombre_de_notes(0);
	do
	{
		cout <<"Entrez le nombre de notes:" <<endl;
		cin >> nombre_de_notes;
	}
	while (nombre_de_notes <= 0);
	
	return 0;
}
