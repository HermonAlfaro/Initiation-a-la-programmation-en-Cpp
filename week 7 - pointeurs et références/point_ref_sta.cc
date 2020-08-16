#include <iostream>
#include <memory> // pour les pointeurs intellogents en C++11
using namespace std;


int main()
{
	/* Pointeurs: servent a:
	1- Référence: Pertmettre a plusieurs portions de code de partager des objects
	2- Généricité: Povoir choisir des éléments non connus a priori (au moment de la programmation)
	3- Allocation dynamique: manipuler des objets dont la durée de vie dépase la portée
	*/
	
	/* 1- REFERENCES : étique sur une variable
	 type& nom_reference(identificateur)
	 Doit absolument etre initialisée 
	 Ne peut pas etre liée qu'a un seul objet
	 Ne peut pas etre référencée (non int &&) et on ne peut donc pas faire de tableau de références
	  
	 ex: int val(1);
		 int& x(val); -> alias, i et j sont la meme, case mémoire
	
	 ex2: int i(3);
		  const int& j(i);
		 -> de i on peutx changer la valeur, mais pas de j
	
	 ex3: int i(3)
		  int& j(i)
		  int& k(j) -> Une autre référence de i
	 */
	 
	 /* Les variables pointeurs: une variable contenant une adresse
	  
	// ex:
	
	déclarer un pointeur
	p.ex. int* ptr;
	
	affecter un pointeur
	p.ex. ptr = &x;
	
	allouer un pointeur ptr
	p.ex. ptr = new int(123);
	
	libérer un pointeur ptr
	p.ex delete ptr; ->libérer l'adresse pointée par le pointeur
	
	copier un pointeur
	p.ex p1 = p2;
	
	annuler/effacer in pointeur ptr
	p1 = nullptr;
 
	// déclaration: type* identificateur
	ex: int* ptr -> déclare une variable ptr qui pointe sur une valeur de type int
	
	L'initialisation d'un ponteur se fait selon la syntaxe:
	type* identificateur(adresse);
	ex: int* ptr(nullptr); -> ne pointe vers rien
	    int* ptr(&i);
	    int* ptr(new int(33));

	& :  retourne l'adresse mémoire de la valeur d'une variable
	si x est de type type, &x est de type type* (pointeur sur type)
	
	int x(3);
	int* px(nullptr);
	px = &x; -> adresse de x
	 
	* : retourne la valeur pointée par une variable pointeur
	si px est de type type*, (*px) est la valeur de type type pointée par px
	
	int x(3); //x est de type entier
	int* px(nullptr); // px est un pointeur sur entier
	 
	px = &x; // px pointe sur la variable x
	cout << *px // affiche la valeur pointee par px : x
	<< endl;
	*/
	
	/* Confusions
	 type& id :  référence sur une variable id dans le passage par référence d'une fonction
	 &id : adresse de la variable id (par exemple en affectation d'un pointeur)
	  
	 type* id :  déclare une variable id comme un pointeur sur un type de base type
	 *id : (ou is est un pointeur) représente le contenu de l'endroit pointé par id 
	 */
	 
	 /* Pointeurs : allocation dynamique
	  2 facons d'allocation:
	   - int v; -> allocation statique (a la compilation)
	   - vector v; v.push_back(3); -> allocation dynamique (a l'execution)
	   
	   Pour les pointeurs, l'aalocation dynamique permet de réserver de la memoire
	   indépendament de toute variable: on pointe directement sur une zone
	   mémoire plutot que sur une variable existante
	  
	  2 operateurs
	  new : alluer dynamiquement de la mémoire
	  delete :  libérer dynam de la mémoire
	  
	  pointeur = new type;
	  int* px;
	  px = new int;
	  
	  pointeur = new type(valeur);
	  int* px;
	  px = new int(3);
	   
	  delete pointeur;
	   
	   
	  CONSEILS:
		- Initialisez toujours les pointeurs (nullptr si nécessaire);
		- Faire suivre tous les delete de l'instruction pointeur = nullptr;
		-Toute zone mémoire alouée par un new doit impérativement etre libérée par un 
		delete correspondant;
		
	  ex:
	  int* px(nullptr); // déclaration d'un pointeur sans acune référence
	  px = new int; // allocation dynamique -> réserve un espace de la mémoire pour garder une variable de type int
	  *px = 20; // utilise l'espace réservé pour allouer 20
	  cout << *px << endl; -> print ce qui habite sur l'espace réservé, en utilisant son adresse pour l'identifier
	  delete px; --> efface ce qui avait sur l'espace réservé
	  px = nullptr; --> efface l'adresse qui était contenu dans px
	  
	  
	  Segmentation fault :
	  - aucune mémoire n'a été réversée
	  ex:
	  int* px;
	  *px = 20;  // Erreur : px n'a pas été alloué
	  */
	  
	  /* Pointeurs intelligents (1/2) #include<memory>
	   - unique_ptr : pointent sur une zone mémoire n'ayant qu'un seul pointeur (seul propriétaire)
			ne peut etre copié, mais peut etre déplace,  transmis plus loin
			pour delete par nous meme avant du garbage collection on peut utiliser ptr.reset();
			unique_ptr<int> p2(new int(3));
			non: unique_ptr<int> p1(p2);
			
	   - shared_ptr : zone mémoire partagée par plusieurs endroits du code
	   - weak_ptr : presque comme un shared_ptr, mais peut avoir été détruit par ailleurs
	   
	    
	   
	   
	   
	   */
	
	
	
	return 0;
}
