#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
   
   
  if ((debut < 0 or debut > 24) or (fin <0 or fin > 24)) 
  { 
    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
  }
  
  
  else if (debut == fin)
  {
	cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
  }
  
  
  else if (debut > fin)
  {
	cout << "Bizarre, le début de la location est après la fin ..." << endl;
  } 
  
  
	
  else 
  {
	int dur1(0);
	int dur2(0);
    cout << "Vous avez loué votre vélo pendant" << endl;
    
    if (debut < 7 and fin <= 7)
    {
		dur1 = fin - debut;
	}
	
	if (debut < 7 and fin > 7 and fin <=17)
    {
		dur1 = 7 - debut;
		dur2 = fin -7;
	}
	
	if (debut < 7 and fin > 17)
    {
		dur1 = (7 - debut) + (fin - 17);
		dur2 = 10;
	}
	
	if (debut >= 7 and debut <17 and fin > 7 and fin <= 17)
    {
		dur2 = fin - debut;
	}
	
	if (debut >= 7 and debut <17 and fin > 17)
    {
		dur2 = 17 - debut;
		dur1 = fin -17;
	}
	
	if (debut >= 17 and fin > 17)
    {
		dur1 = fin - debut;
	}
	
	if (dur1 > 0)
	{
		cout << dur1 << " heure(s) au tarif horaire de 1"
			<< " franc(s)" << endl;
	}
	
	if (dur2 > 0)
	{
		cout << dur2 << " heure(s) au tarif horaire de 2"
			<< " franc(s)" << endl;
	}
    
    cout << "Le montant total à payer est de " << (dur1 * 1 + dur2 * 2)
         << " franc(s)." << endl;
  }

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
