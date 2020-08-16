#include <iostream>
#include <vector>
using namespace std;

typedef size_t Position;
typedef vector<int> Sequence;

struct SousSequence {
  Position debut;
  Position fin;
  int somme;
};

// PROTOTYPES
SousSequence tranche_max_1(Sequence a);
SousSequence tranche_max_2(Sequence a);
SousSequence tranche_max_3(Sequence a);
void affiche(SousSequence s, Sequence a);

// ----------------------------------------------------------------------
int main()
{
  /* ATTENTION, Les initialisations ci-dessous ne sont valables qu'en C++11.
   * Si vous compilez en C++98, utilisez des push_back();
   */
  Sequence seq = { 11, 13, -4, 3, -26, 7, -13, 25, -2, 17, 5, -8, 1 };
  // Sequence seq = { -3, -4, -1, -2, -3 };
  // Sequence seq = { -1, -4, -3, -2, -3 };
  // Sequence seq = { 3, 4, 1, 2, -3 };
  // Sequence seq = { 3, 4, 1, 2, 3 };
  // Sequence seq = { 3, -1, -1, -1, 5 };
  // Sequence seq = { -5, -4, 1, 1, 1 };

  affiche(tranche_max_1(seq), seq);
  affiche(tranche_max_2(seq), seq);
  affiche(tranche_max_3(seq), seq);

  return 0;
}

/* ======================================================================
 * Recherche la sous-sequence de somme maximale dans une sequence.
 *   L'algorithme utilisé ici est l'algorithe naïf de complexité cubique.
 * Entree : la sequence où chercher
 * Sortie : la sous-séquence de somme maximale
 * ====================================================================== */
SousSequence tranche_max_1(Sequence a)
{
  SousSequence rep = { 0, 0, 0 };
  if (a.size() != 0) {
    rep.somme = a[0];
    for (Position debut(0); debut < a.size(); ++debut) {
      for (Position fin(debut); fin < a.size(); ++fin) {
        int somme(0);
        for (Position p(debut); p <= fin; ++p) {
          somme += a[p];
        }
        if (somme > rep.somme) {
          rep.debut = debut;
          rep.fin   = fin;
          rep.somme = somme;
        }
      }
    }
  }
  return rep;
}

/* ======================================================================
 * Recherche la sous-sequence de somme maximale dans une sequence.
 *   L'algorithme utilisé ici est l'algorithe naïf de complexité quadratique.
 * Entree : la sequence où chercher
 * Sortie : la sous-séquence de somme maximale
 * ====================================================================== */
SousSequence tranche_max_2(Sequence a)
{
  SousSequence rep = { 0, 0, 0 };
  if (a.size() != 0) {
    rep.somme = a[0];
    for (Position debut(0); debut < a.size(); ++debut) {
      int somme(0);
      for (Position fin(debut); fin < a.size(); ++fin) {
        somme += a[fin];
        if (somme > rep.somme) {
          rep.debut = debut;
          rep.fin   = fin;
          rep.somme = somme;
        }
      }
    }
  }
  return rep;
}

/* ======================================================================
 * Recherche la sous-sequence de somme maximale dans une sequence.
 *   L'algorithme utilisé ici est l'algorithe linéaire
 * Entree : la sequence où chercher
 * Sortie : la sous-séquence de somme maximale
 * ====================================================================== */
SousSequence tranche_max_3(Sequence a)
{
  SousSequence rep = { 0, 0, 0 };
  if (a.size() != 0) {
    rep.somme = a[0];
    int somme(0);
    Position debut(0);
    for (Position fin(0); fin < a.size(); ++fin) {
      somme += a[fin];

      if (somme > rep.somme) {
        rep.debut = debut;
        rep.fin   = fin;
        rep.somme = somme;
      }
      if (somme <= 0) {
        debut = fin + 1;
        somme = 0;
      }
    }
  }
  return rep;
}

// ----------------------------------------------------------------------
void affiche(SousSequence s, Sequence seq)
{
  cout << "La tranche maximale est ";
  for (Position i(s.debut);  i <= s.fin; ++i)
    cout << seq[i] << ", ";
  cout << endl << "de somme " << s.somme << endl;
}
