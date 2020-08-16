#include <iostream>
#include <string>
#include <array>
using namespace std;


int main()
{
	// char identificateur ''
	// string identificateur "";
	/* operations:
	 + :  string + string, string + char
	 ==, !=
	 chaine[i] : (i+1)eme caractere (de type char)
	 chaine[0] : premier caractere
	 * chaine[taille - 1] : dernier caractere 
	 */ 
	/* FONCTIONS : nom_de_chaine.nom_de_fonction(arg1, arg2, ...)
	 .size() : taille (# caracteres)
	 .insert(position, chaine2) : insere a parit de la position (indice)
	  dans la chaine, la string chaine2
	 .replace(position, n, chaine2) :  remplace les n caracteres d'indice
	 position, position+1, ... position+(n-1) de chaien par la string chaine2
		ex: string example("abcd");
			example.replace(1,2, "1234"); - > "a1234d"
			example.replace(1,2, ""); - > "ad"
	  .find(souschaine) : l'indice dans chaine du 1er caractere de
	  l'occurrence la plus a gauche de la string souschaine
		ex : string example("baabbaab");
			 example.find("ab"); - > 2
	  .rfind(souschaine) : l'indice dans chaine du 1er caractere de
	  l'ocurrence la plus a droite de la string souschaine
		ex : string example(baabbaab");
		     example.rfind("ab") - > 6
	  Dans le cas ou les fonction find() et rfind() ne peuvent s'appliquer,
	  elles renvoient la valeur pr´définie string::npos
		ex : if (example.find("xy") != string::npos) ...
	  
	  .substr(depart, longueur) :  sous-chaine, de longueur et commencant a la pos
	  position depart
	 /*
	 ALIAS DE TYPES : typedef
		typedef type alias;
			ex :
			typedef vector<double> Vecteur;
			typedef vector<Vecteur> Matrice;
			Matrice rotation(3, Vecteur(3, 1.0));
	*/
	
	/*
	 STRUCTURES: struct identificateur {type var;... };
	 Une fois le type de la structure d´claré, on peut utiliser son nom 
	 comme tout autre type pour déclarer des variables:
		Nom_du_type nom_de_la_variable;
	 
	 Accéder aux champs : structure.champ
	 
	 
	 */
	 struct Date
	 {
		 int jour;
		 int mois;
		 int annee;
	 };
	 
	 struct Particule
	 {
		 array<double, 3> position;
		 array<double, 3> vitesse;
		 double masse;
		 double charge;
	 };
	 
	 Particule bosson;
	 
	 Date today = {1, 3, 2019}
	 // C++11
	 today = {2, 3, 2019} 
	  
	  
	  
	  
	  
	 
	 

	return 0;
}
