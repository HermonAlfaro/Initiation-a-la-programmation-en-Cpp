#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Carte;

struct Position
{
	size_t i; //ligne
	size_t j; // col
};

bool binaire(Carte const& carte);
void affiche(Carte const& carte);
bool verifie_et_modifie(Carte& carte);
double longueur_cloture(Carte const& carte, double echelle = 2.5);
	


int main()
{
	/*
	Carte carte = {{1,0, 1},
				   {1, 0},
				   {0,1},
				   {1, 0, 0,1},
				   {0},
				   {},
				   {0,0,1,0,1,1,0,0,0,1,1,1,0}};
	*/
	Carte carte = {{1,1,1},
				   {1,1,1},
				   {1,1,1}
			   };
	
	//cout << binaire(carte) << endl;
	//affiche(carte);
	
	//verifie_et_modifie(carte);
	//affiche(carte);
	 double longueur(longueur_cloture(carte));
	
	cout << "cloture : " << longueur << endl; 

	return 0;
}

bool binaire(Carte const& carte){
	for (auto& ligne : carte)
	{
		for (auto& value : ligne)
		{
			if (value!= 0 and value!=1)
			{
				return false;
			}
		}
		
	}
	
	return true;
}

void affiche(Carte const& carte){
	for (auto& ligne : carte)
	{
		for (auto& value : ligne)
		{
			cout << value;
		}
		cout << endl;
	}

	cout << "----" << endl;
}

bool verifie_et_modifie(Carte& carte){
	
	vector<Position> etangs;
	
	// numero de lineas
	size_t n_lignes(carte.size());
	
	// REVISAR DESPUES
	// fila vacia
	if(n_lignes==0){return true;}
	
	for (size_t i(0); i<n_lignes; ++i)
	{
		size_t n_colonnes(carte[i].size());
		
		// REVISAR DESPUES
		// columna no vacia
		if (n_colonnes>=1)
		{
			
			for(size_t j(0); j<n_colonnes; ++j)
			{
				int gauche(0);
				int droite(0);
				
				if(carte[i][j]!=0 and carte[i][j]!=1){
					cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
					return false;
				}
				
				Position actual_pos({i,j});
				
				/////// suma a la derecha y a la izquierda
				for(size_t k(0);k<j;++k){gauche+=carte[i][k];}
				for(size_t k(n_colonnes);k>j;--k){droite+=carte[i][k];}
				//////////////////////////////////////////////
				
				if(carte[i][j]==0 and gauche>=1 and droite>=1){etangs.push_back(actual_pos);}
			}
		}	
	}
	
	for (auto& e : etangs)
	{
		carte[e.i][e.j] = 1;
	}
	
	return true;	
}


double longueur_cloture(Carte const& carte, double echelle){
	
	int count(0);
	
	// cantidad de líneas
	size_t n_lignes(carte.size());
	
	// no vacio
	if (n_lignes>=1)
	{
		for(size_t i(0); i<n_lignes; ++i)
		{
			// cantidad de columnas
			size_t n_colonnes(carte[i].size());
			
			// cantidad columnas fila anterior
			size_t n_colonnes_ant;
			if(i==0){n_colonnes_ant=0;}
			else{n_colonnes_ant = carte[i-1].size();}
			
			// cantidad columnas fila siguiente
			size_t n_colonnes_pos;
			if(i==n_lignes-1){n_colonnes_pos=0;}
			else{n_colonnes_pos = carte[i+1].size();}

			// no vacio
			if(n_colonnes>=1)
			{
				for(size_t j(0); j<n_colonnes; ++j)
				{
					//////////////////////////////////////////////////
					int gauche(-1);
					int sur(-1);
					int droite(-1);
					int sous(-1);
					
					// si j-1 esta fuera de rango
					if((j-1)<0){gauche=0;}
					else{gauche=carte[i][j-1];}
					
					// si j+1 esta fuera de rango
					if ((j+1)>=n_colonnes){droite=0;}
					else{droite=carte[i][j+1];}
					
					///////////////////////////////////////////////////
					// si i - i esta fuera de rango
					if((i-1)<0 or j>=n_colonnes_ant){sur=0;}
					else{sur=carte[i-1][j];}
					
					// si i+1 esta fuera de rango
					if((i+1)>=n_lignes or j>=n_colonnes_pos){sous=0;}
					else{sous=carte[i+1][j];}
	
					///////////////////////////////////////////////////
					if (gauche==0){count+=1;}
					if (sur==0){count+=1;}
					if (droite==0){count+=1;}
					if (sous==0){count+=1;}
					//////////////////////////////////////////////////
					
				}
				
				
			}
		}
	}
		
	
	
	return count * echelle;
}
