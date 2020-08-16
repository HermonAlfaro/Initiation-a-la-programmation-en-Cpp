#include <iostream>
#include <cmath>
using namespace std;
/* Fonctions
fonction (en programmation)
fonction = portion de programme réutilisable ou importante en soi
caracterisée par:
 		un corps : la portion de programme a réutiliser au mettre en évidence
		un nom : par lequel on désignera cette fonction
 		des parametres : ensemble de variables extérieures a la fonction
						 dont le corps dépend pour fonctionner
		un type et une valeur de retour : ce que la fonction renvoie au 
										  rest du programme
L'utilisation de la fonction dans une autre partie du programme se nomme un appel de la fonction
3 facettes :
	Résumé / Contrat (prototype) type nom(type1 id_param1, ..., typeN id_paramN);
 Création / Construction (définition) double f(double a, double b) {}
 Utilisation (appel) z = f(2*u, v+3)

Passage des arguments:
	par valeur :  copie de l'argument -> les modificarions a l'interiur
				  ne sont pas répercutées a l'exterieur
				 ex: f(int x)
	par référence : référence sur l'objet associé -> modification alors répercute
 				 	ex: f(int& x)

Fonctions sans valeur de retour: void f(int x) {}
le commande return est optionnelle dans ce cas-la

Arguments par défault (doit {etre dans le prototype): int x = 5;

La surchange de fonctions :
* 	En C++, il est pissible de définir plusieurs fonctions de meme nom 
* 	si ces fonctions n'ont pas les memes listes de parametres : nombre ou 
* 	types de parametres différents
* 
* 	Tres utile pour écrire des fonctions 'sensibles' au type de leurs arguments
* 	c'est-a-dire des functions correspondant a des traitements de meme nature mais 
* 	s'appliquant a des entités de types différents (signature)
* 
* 	ca marche : int f(int x); int f(double x)
*	ca ne marche pas: int f(int x); double f(int x) 
* 					  int f(int x); int f(int x, int y=4)
 
 
 */




// prototype
double moyenne(double x, double y);	

int main()
{
	double x(1);
	double y(3);
	
	// appel
	cout << moyenne(x, y) << endl;
	
	return 0;
}

// définition
double moyenne(double x, double y)
{
	return (x + y) /2.;
}




