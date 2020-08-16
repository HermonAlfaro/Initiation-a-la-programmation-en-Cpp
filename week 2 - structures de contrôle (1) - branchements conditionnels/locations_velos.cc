#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de d�but de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compl�ter le code � partir d'ici
   *****************************************************/
   
   
  if ((debut < 0 or debut > 24) or (fin <0 or fin > 24)) 
  { 
    cout << "Les heures doivent �tre comprises entre 0 et 24 !" << endl;
  }
  
  
  else if (debut == fin)
  {
	cout << "Bizarre, vous n'avez pas lou� votre v�lo bien longtemps !" << endl;
  }
  
  
  else if (debut > fin)
  {
	cout << "Bizarre, le d�but de la location est apr�s la fin ..." << endl;
  } 
  
  
	
  else 
  {
	int dur1(0);
	int dur2(0);
    cout << "Vous avez lou� votre v�lo pendant" << endl;
    
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
    
    cout << "Le montant total � payer est de " << (dur1 * 1 + dur2 * 2)
         << " franc(s)." << endl;
  }

  /*******************************************
   * Ne rien modifier apr�s cette ligne.
   *******************************************/

  return 0;
}
