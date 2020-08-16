#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
	bool resultat(false);
	if (c=='.' or 
		c=='R' or
		c=='G' or
		c=='B' or
		c=='C' or
		c=='Y' or
		c=='M')
	{
		resultat=true;
	}
	
	return resultat;
}

// ======================================================================
bool verifier(char c, char& r, int& score)
{
	bool resultat(false);
	if (c==r)
	{
		score += 1;
		r = 'x';
		resultat = true;
	}
	
	return resultat;
	
}

// ======================================================================
void apparier(char c, char& r1, char& r2, char& r3, int& score)
{
	bool match(false);
	
	match = verifier(c, r1, score);
	
	if (!match)
	{
		match = verifier(c, r2, score);
	}
	
	if (!match)
	{
		match = verifier(c, r3, score);
	}
	
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
	
	// bool bien placee
	bool c1_bp(false);
	bool c2_bp(false);
	bool c3_bp(false);
	bool c4_bp(false);
	
	// count
	int nb_total(4);
	int nb_bp(0);
	int nb_mp(0);
	int nb_m(0);
	
	
	// verifier bien placees
	c1_bp = verifier(c1, r1, nb_bp);
	c2_bp = verifier(c2, r2, nb_bp);
	c3_bp = verifier(c3, r3, nb_bp);
	c4_bp = verifier(c4, r4, nb_bp);
	
	
	// verifier mal placee
	if (!c1_bp)
	{
		apparier(c1, r2, r3, r4,nb_mp); 
	}
	
	if (!c2_bp)
	{
		apparier(c2, r1, r3, r4,nb_mp); 
	}
	
	if (!c3_bp)
	{
		apparier(c3, r1, r2, r4,nb_mp); 
	}
	
	if (!c4_bp)
	{
		apparier(c4, r1, r2, r3,nb_mp); 
	}
	
	nb_m = nb_total - nb_bp - nb_mp;
	
	afficher(nb_bp, '#');
	afficher(nb_mp, '+');
	afficher(nb_m, '-');
	
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
	bool resultat(false);
	
	if (c1==r1 and c2==r2 and c3==r3 and c4==r4)
	{
		resultat = true;
	}
	
	return resultat;
}

// ======================================================================
void jouer(int max_coups=8)
{
	// coups
	int coups(1);
	
	// references
	char r1(tirer_couleur());
	char r2(tirer_couleur());
	char r3(tirer_couleur());
	char r4(tirer_couleur());
		
	// couleurs
	char c1('.');
	char c2('.');
	char c3('.');
	char c4('.');
	
	// gagne
	bool a_gagne(gagne(c1, c2, c3, c4, r1, r2, r3, r4));
	
	while (!a_gagne and coups<=max_coups)
	{
		c1 =lire_couleur();
		c2 = lire_couleur();
		c3 = lire_couleur();
		c4 = lire_couleur();
		
		afficher_coup(c1, c2, c3, c4, r1, r2, r3, r4);
		
		a_gagne = gagne(c1, c2, c3, c4, r1, r2, r3, r4);
		coups += 1;
		
	}
	
	if (a_gagne)
	{
		message_gagne(coups-1);
	}
	
	else
	{
		message_perdu(r1, r2, r3, r4);
	}

}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
