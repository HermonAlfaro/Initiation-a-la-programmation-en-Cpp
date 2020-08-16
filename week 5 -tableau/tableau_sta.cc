#include <iostream>
#include <vector>
using namespace std;


int main()
{
	// 5 facons d'initialiser un tableau dynamique:
	
	// vide : vector<type> identificateur;
	vector<int> tab_vide;
	
	// avec un ensemble de valeurs initiales : vector<type> identificateur({val1, val2, ...});
	vector<int> tab_ensemble({20,35,26,38,22});
	
	// avec une taille initiale donnée et tous les éléments << nuls >> : vector<type> identificateur(taille);
	vector<int> tab_taille(5);
	
	// avec une taille initiale donnée et tous les éléments a un meme valeur donnée : vector<type> ident(taille, valeur);
	vector<int> tab_taille_valeur(5,1);
	
	// avec une copie d'un autre tableau : vector<int> inden2(iden1);
	vector<int> tab2(tab_vide);
	
	// Affectation globale d'un tableau :  tableau2 = tableau1 (copie de tout tableau1 dans tableau2)
	vector<int> tab1({1, 2, 3});
	vector<int> tab3;
	tab3 = tab1;
	
	/* Acces direct aux éléments d'un tableau
	 le (i+1)eme élément d'un tableau tab es référencé par : tab[i]
	 les indices correspondant aux éléments d'un tableau de taille t varient entre 0 et (T-1)
	 il n'y a pas de controle de débordement
	 */
	
	/*Itérations : 
	 * C++11 : for (auto element : tableau) {} // ne modifie pas les éléments du tableau
	 * c++11 : for (auto& element : tableau) [] // peut modifier les éléments du tableau
	 * for(size_t i(0); i < TAILLE; ++i) {}	
	 * examples :
	*/
	vector<int> ages(5);
	
	for(auto& age : ages)
	{
		cout <<" Age de l'employé suivant?";
		cin >> age;
	}
	
	cout << "Age des employés : " <<endl;
	for(auto age: ages)
	{
		cout << "  " << age << endl;
	}
	
	// type size_t es un type de int toujours positif
	for(size_t i(0); i < ages.size(); ++i)
	{
		cout << " Age de l'employé " << i + 1 << " ? ";
		cin >> ages[i];
	}
	
	// affectation de tous les éléments a la valeur 1.2
	tab = vector<double>(tab.size(), 1.2)
	
	
	// fonctions spécifiques vector : nom_de_tableau.nom_de_function(arg1, arg2, ...);
	/*
	 * .size : taille
	 * .front : 1er élément
	 * .back : dernier élément
	 * .empty :  true si vide
	 * .clear :  syoorune toues les éléments de tableau. Paa de retour
	 * .pop_back : supprime le dernier élément de tableau. Pas de retour
	 * .push_back(val) : ajoute un nouvel élément de valeur val a la fin de tableau. Pas de retour 
	 */ 
	vector<double> mesures;
	size_t nombre_de_mesures(0);
	
	nombre_de_mesures = mesures.size();
	
	// les tableux multidimensionnels
	//vector<vector<int>> table(5, vector<int>(6));
	/* C++11 : vector<vector<int>> tableau()
	 * { {0, 1, 2, 3, 42},
	 * 	 {4, 5, 6 },
	 * {7, 8},
	 * {9, 0, 1 }
	 * }
	 * );
	 */
	 
	 /* Moins de C++11 : vector<vector<int> > tableau()
	 * { {0, 1, 2, 3, 42},
	 * 	 {4, 5, 6 },
	 * {7, 8},
	 * {9, 0, 1 }
	 * }
	 * ); 
	 */
	
	 
	 
	// table[i] est donc un vector<int>
	// table[i][j] sera alors le (j+1)-ieme élément de ce tableau
	
	
	 
	
	
	
	return 0;
}
