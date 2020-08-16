#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <array>
using namespace std;

// type enum : enum Type {nom_val_1, nom_val_2,...}
	enum Couleur {vide, rouge, jaune};
	// ex: Couleur element(vide); element==rouge -> false, element==vide -> vide

// tableau
	typedef array<array<Couleur, 7>, 6> Grille; 
	// ex: grille[2][3] = jaune


// prototypes des fonctions
void initialise(Grille& grille);
void affiche(const Grille& grille);
bool joue(Grille& grille, size_t colone, Couleur couleur); 
void demande_et_joue(Grille& grille, Couleur couleur_joueur);
bool est_ce_gagne(const Grille& gille, Couleur couleur_joueur); 
unsigned int compte(const Grille& grille, 
					size_t ligne_depart, size_t colonne_depart,
					int dir_ligne, int dir_colonne);
bool pleine(const Grille& grille);

int main()
{

	
	Grille grille;
	initialise(grille);
	
	Couleur couleur_joueur(jaune);
	
	bool gagne(false);
	do
	{
		demande_et_joue(grille, couleur_joueur);
		affiche(grille);
		
		gagne = est_ce_gagne(grille, couleur_joueur);
		
		// on change la couleur pour la couleur de l'autre joueur
		if (couleur_joueur==jaune)
		{
			couleur_joueur = rouge;
		}
		else
		{
			couleur_joueur=jaune;
		}
	} while(not gagne and not pleine(grille));
	
	
	if (gagne)
	{
		if (couleur_joueur==jaune)
		{
			cout << "Le joueur 0 a gagne !" << endl;
		}
		else
		{
			cout << "Le joueur X a gagne !" << endl;
		}
	}
	
	else
	{
		cout <<"Match null!" << endl;
	} 
	 
	 
	return 0;
}

void initialise(Grille& grille)
{
	for (auto &line : grille)
	{
		for(auto &kase : line) 
		{
			kase = vide;
		}
	}	
}

void affiche(const Grille& grille)
{
	/*
	 '-' pour vide, 
	 '0' pour rouge, 
	 'X' pour jaune.
	*/
	
	for (auto &line : grille)
	{
		for(auto &kase : line) 
		{
			if (kase==vide)
			{
				cout << ' ';
			}
			
			else if (kase==rouge)
			{
				cout << '0';
			}
			
			else
			{
				cout << 'X';
			}
			cout << "|";
			
		}
		cout << " |";
		cout << endl;
	}
	
	cout << "=";
	for(size_t i(1); i <=grille[0].size(); ++i)
	{
		cout << "=" << i;
	}
	cout << "==";
	
	cout << endl << endl;
}

bool joue(Grille& grille, size_t colonne, Couleur couleur)
{
	// colonne invalide -> on ne joue pas
	if ((colonne >= grille[0].size()))
	{
		return false;
	}
	
	// colonne pleine -> on ne joue pas
	if (grille[0][colonne] != vide)
	{
		return false;
	}
	
	size_t ligne(grille.size()-1);
	while((ligne>0) and (grille[ligne][colonne]!=vide))
	{
		--ligne;
	}
	
	grille[ligne][colonne] = couleur;
	
	return true;
	
}

void demande_et_joue(Grille& grille, Couleur couleur_joueur)
{
	bool valide(false);
	while (not valide)
	{
		cout <<" Joueur ";
		if (couleur_joueur==jaune)
		{
			cout << 'X';
		}
		else
		{
			cout << '0';
		}
		cout << " entre un numéro de colonne" << endl;
		size_t colonne;
		cin >> colonne;
		--colonne; // Indice tableau
		
		bool valide(joue(grille, colonne, couleur_joueur));
		
		if(not valide)
		{
			cout <<" > Ce coup n'est pas valide" << endl;
		}
	}
}

bool est_ce_gagne(const Grille& grille, Couleur couleur_joueur)
{
	
	for(size_t ligne(0); ligne<grille.size(); ++ligne)
	{
		for(size_t colonne(0); colonne<grille[ligne].size(); ++colonne)
		{
			Couleur couleur_case(grille[ligne][colonne]);
			
			if (couleur_case==couleur_joueur)
			{
				const size_t ligne_max(grille.size() -4);
				const size_t colonne_max(grille[ligne].size() -4);
				
				if (
				// diag, vers le haut et la droite
				(ligne>=3 and colonne <= colonne_max and
				compte(grille, ligne, colonne, -1, +1)>=4)  or
				
				// horizontalement, vers la droite
				(colonne <= colonne_max and 
				compte(grille, ligne, colonne, 0, +1)>=4) or
				
				// en diagonale, vers le bas et la droite
				(ligne<= ligne_max and colonne <= colonne_max and
				compte(grille, ligne, colonne, +1, -1)>=4) or
				
				//verticalement, vers le bas
				(ligne <= ligne_max and
				compte(grille, ligne, colonne, +1, 0)>=4))
				{
					
					return true;
				}
			}
		}
		
	}
	return false;
}

unsigned int compte(const Grille& grille, 
					size_t ligne_depart, size_t colonne_depart,
					int dir_ligne, int dir_colonne)
{
	unsigned int compteur(0);
	
	size_t ligne(ligne_depart);
	size_t colonne(colonne_depart);
	
	while (ligne<grille.size() and colonne < grille[ligne].size() and grille[ligne][colonne] == grille[ligne_depart][colonne_depart])
	{
		++compteur;
		ligne   = ligne   + dir_ligne;
		colonne = colonne + dir_colonne;
		
	}
	
	return compteur;
	
}


bool pleine(const Grille& grille)
{
	for(auto& kase : grille[0])
	{
		if (kase==vide)
		{
			return false;
		}
	}
	return true;	
}


