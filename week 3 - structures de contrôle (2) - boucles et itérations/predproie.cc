#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Complèter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales

  
  do
  {
	cout << "Combien de renards au départ (>= 2) ? ";
	cin >> renards_i;
  }
  while (renards_i<2);
  
  
  do
  {
	cout << "Combien de lapins au départ  (>= 5) ? ";
	cin >> lapins_i;
  }
  while (lapins_i<5);
  
  // ===== PARTIE 2 =====
  // Première simulation

  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
  
  double nb_lapins(lapins_i);
  double nb_renards(renards_i);
  
  for (int i(1); i <= duree; ++i)
  {
	  double taux_lapins;
	  double taux_renards;
	  
	  
	  taux_lapins = (1.0 + taux_croissance_lapins 
								 - taux_attaque*nb_renards);
	  taux_renards = (1.0 + taux_attaque * nb_lapins
								   * taux_croissance_renards - 
								   taux_mortalite);
	  nb_lapins *= taux_lapins;
	  nb_renards *= taux_renards;
	  
	  if (nb_lapins<0)
	  {
		  nb_lapins = 0;
	  }
	  
	  cout << "Après " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;
   }
	  

  // ===== PARTIE 3 =====
  // Variation du taux d'attaque
  cout << endl;

  double taux_attaque_d;
  do
  {
	cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
	cin >> taux_attaque_d;
  }
  while (taux_attaque_d<0.5 or taux_attaque_d>6.);
  taux_attaque_d /= 100.;

  double taux_attaque_f;
  do
  {
	cout << "taux d'attaque à la fin  en % (entre " << taux_attaque_d * 100.;
	cout << " et 6) ? ";
	cin >> taux_attaque_f;
  }
  while (taux_attaque_f<taux_attaque_d*100. or taux_attaque_f>6.);
  taux_attaque_f /= 100.;

  for (double t(taux_attaque_d); t < taux_attaque_f; t+= 1./100.)
  {
	
	///////////////////////////////////////////////////////////////
	cout <<  endl << "***** Le taux d'attaque vaut "<< t * 100 << "%" <<  endl;
  
	int real_duree(duree);
	int mois(0);
	
	double nb_lapins(lapins_i);
	double nb_renards(renards_i);
	
	bool voie_extinction_lapins(false);
	bool voie_extinction_renards(false);
	
	bool remonte_lapins(false);
	bool remonte_renards(false);
	
	bool extinction_lapins(false);
	bool extinction_renards(false);
	
	do
	{
		
		double taux_lapins;
		double taux_renards;
	  
	  
		taux_lapins = (1.0 + taux_croissance_lapins 
								 - t*nb_renards);
		taux_renards = (1.0 + t* nb_lapins
								   * taux_croissance_renards - 
								   taux_mortalite);
		nb_lapins *= taux_lapins;
		nb_renards *= taux_renards;
		
		if (nb_lapins<5)
		{
			voie_extinction_lapins = true;
		}
		
		if (nb_renards<5)
		{
			voie_extinction_renards = true;
		}
		
		if (nb_lapins>=5 and voie_extinction_lapins)
		{
			remonte_lapins = true;	
		}
		
		if (nb_renards>=5 and voie_extinction_renards)
		{
			remonte_renards = true;	
		}
		
	
		if (nb_lapins<2)
		{
			nb_lapins = 0;
			extinction_lapins = true;
		}
	  
		if (nb_renards<2)
		{
			nb_renards = 0;
			extinction_renards = true;
		}
		
		
		if (nb_lapins==0 and nb_renards==0)
		{
			real_duree=mois;
		}
		
		mois += 1;
		real_duree = mois;
		
	  
	}
	while (mois < duree and (nb_lapins!=0 or nb_renards!=0));
  
  
	cout << "Après " << real_duree << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;
  
	if (voie_extinction_renards)
	{
		cout << "Les renards ont été en voie d'extinction" << endl;  
	}
  
	if (remonte_renards)
	{
		cout << "mais la population est remontée ! Ouf !" << endl;  
	}
  
	if (extinction_renards)
	{
		cout << "et les renards ont disparu :-(" << endl;
	}
  
	if (voie_extinction_lapins)
	{
		cout << "Les lapins ont été en voie d'extinction" << endl;  
	}
    
	if (remonte_lapins)
	{
		cout << "mais la population est remontée ! Ouf !" << endl;  
	}
	
	if (extinction_lapins)
	{
		cout << "et les lapins ont disparu :-(" << endl;
	}
  
	if (not voie_extinction_renards and 
		not remonte_renards and
		not extinction_renards and
		not voie_extinction_lapins and 
		not remonte_lapins and
		not extinction_lapins)
	{
		cout << "Les lapins et les renards ont des populations stables." << endl;
	}

  
	  
  }
	   


  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
