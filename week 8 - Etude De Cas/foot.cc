#include <array>
#include <string>
#include <iostream>
using namespace std;

struct Equipe {
  string nom;
  int points;
  int marques;
  int encaisses;
};

struct Match {
  int prems;
  int deuz;
};

void swap(Equipe&, Equipe&);
bool meilleure(const Equipe&, const Equipe&);

int main()
{
  array<Match, 6> matchs =
    {
      {3, 1}, // Suisse - Croatie
      {2, 0}, // France - Angleterre
      {3, 0}, // Suisse - Angleterre
      {2, 1}, // France - Croatie
      {0, 1}, // Angleterre - Croatie
      {3, 2}  // Suisse - France
    };

  array<Equipe, 4> groupe2 =
    {
      { "Angleterre" , 0, 0, 0 }, // equipe 0
      { "Croatie"    , 0, 0, 0 }, // equipe 1
      { "France"     , 0, 0, 0 }, // equipe 2
      { "Suisse"     , 0, 0, 0 }, // equipe 3
    };

  // saisie des matchs
  for (auto match : matchs) {
    cout << groupe2[match.prems].nom << " - "
         << groupe2[match.deuz ].nom << " ? ";
    array<int, 2> score;
    cin >> score[0];
    cin >> score[1];

    // mise à jour des buts marqués/encaissés
    groupe2[match.prems].marques   += score[0];
    groupe2[match.prems].encaisses += score[1];
    groupe2[match.deuz ].marques   += score[1];
    groupe2[match.deuz ].encaisses += score[0];

    // affectation des points
    if (score[0] > score[1]) {
      groupe2[match.prems].points += 3; // 1er gagne
    } else if (score[0] < score[1]) { 
      groupe2[match.deuz ].points += 3; // 2e gagne
    } else {
      groupe2[match.prems].points += 1;     // match
      groupe2[match.deuz ].points += 1;     //   nul
    }
  }

  // affichage des résultats
  cout << endl << "Résultats : " << endl;
  for (auto equipe : groupe2) {
    cout << "  " << equipe.nom << " : "
         << equipe.points << " points, "
         << equipe.marques << " buts marqués, "
         << equipe.encaisses << " buts encaissés, "
         << "différence : "
         << equipe.marques - equipe.encaisses
         << endl;
  }

  // classement
  for (size_t i(0); i < groupe2.size()-1; ++i)
    for (size_t j(groupe2.size()-1); j > i; --j)
      if (meilleure(groupe2[j], groupe2[j-1]))
        swap(groupe2[j-1], groupe2[j]);

  // affichage du classement
  cout << endl << "Le classement final est : " << endl;
  for (size_t i(0); i < groupe2.size(); ++i)
    cout << "  " << i+1 << " : " << groupe2[i].nom << endl;

  return 0;
}

bool meilleure(const Equipe& eq1, const Equipe& eq2)
{
  if (eq1.points > eq2.points) return true;
  else if (eq1.points < eq2.points) return false;

  if (eq1.marques - eq1.encaisses > eq2.marques - eq2.encaisses)
    return true;
  else if (eq2.marques - eq2.encaisses > eq1.marques - eq1.encaisses)
    return false;

  if (eq1.marques > eq2.marques) return true;
  else if (eq2.marques > eq1.marques) return false;

  return true; // decision arbitraire
}

void swap(Equipe& eq1, Equipe& eq2)
{
  const Equipe eq(eq1);
  eq1 = eq2;
  eq2 = eq;
}
