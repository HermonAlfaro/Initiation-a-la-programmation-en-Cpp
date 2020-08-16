#include <iostream>
#include <array>
#include <vector>
using namespace std;

constexpr size_t nb_etapes(13);

array<string, nb_etapes> pendu = {{
  "\n\n\n\n\n__________",
  "\n  |\n  |\n  |\n  |\n__|_______",
  "\n  |\n  |\n  |\n  |\n_/|_______",
  "\n  |\n  |\n  |\n  |\n_/|\\______",
  "  ______\n  |\n  |\n  |\n  |\n_/|\\______",
  "  ______\n  |/\n  |\n  |\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |\n  |\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |   O\n  |\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |   O\n  |   I\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |  _O\n  |   I\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |  _O_\n  |   I\n  |\n_/|\\______",
  "  ______\n  |/  |\n  |  _O_\n  |   I\n  |  /\n_/|\\______",
  "  ______\n  |/  |\n  |  _O_\n  |   I\n  |  / \\\n_/|\\______",
}};

struct Joueur {
  string nom;
  int points;
  unsigned int etape;
};

bool bonne_lettre(char l, string& mot, string ref)
{
  bool retour = false;
  for (size_t i(0); i < ref.size(); ++i)
    if ((ref[i] == l) and (mot[i] != l)) {
      mot[i] = l;
      retour = true;
    }
  return retour;
}

int main()
{
  cout << "Nombre de joueurs : " << endl;
  unsigned int nb_joueurs;
  cin >> nb_joueurs;

  vector< Joueur > joueurs(nb_joueurs);

  // saisie des noms des joueurs et initialisation
  for (unsigned int i(0); i < nb_joueurs; ++i) {
    cout << "Nom du joueur " << i+1 << " : ";
    cin >> joueurs[i].nom;
    joueurs[i].points = 0;
    joueurs[i].etape  = 0;
  }

  // nombre de joueurs pouvant encore jouer
  unsigned int pouvant_jouer(nb_joueurs);

  // jeu à tour de rôle
  for (unsigned int i(0); (i < nb_joueurs) and (pouvant_jouer > 0); ++i) {
    cout << "Au joueur " << joueurs[i].nom << " (" << i+1
               << ") de proposer un mot." << endl;
    cout << "(Les autres joueurs ne regardent pas)" << endl;

    cout << "Entrez le mot proposé : ";
    string mot;
    cin >> mot;

    // efface l'écran de façon rudimentaire (40 lignes vides ici)
    for (int j(0); j < 40; ++j) cout << endl;

    // cree la forme affichée du mot à deviner
    string mot_trouve;
    for (size_t j(0); j < mot.size(); ++j) mot_trouve += '.';

    // le joueur posant le mot ne peut pas jouer ce tour ci
    // (mais ne le supprimer ici que si il peut encore potentiellement jouer)
    if (joueurs[i].etape < nb_etapes)
      --(pouvant_jouer); 

    while ((mot_trouve != mot) and (pouvant_jouer > 0)) {
      for (unsigned int j(0);
           (j < nb_joueurs) and (mot_trouve != mot);
           ++j)
      {
        if ((j != i) and (joueurs[j].etape < nb_etapes)) {
                cout << endl << "MOT : " << mot_trouve << endl;
          cout << "Joueur " << joueurs[j].nom << " (" << j+1
               << ") proposez une lettre : ";
          char lettre;
          cin >> lettre;

          if (bonne_lettre(lettre, mot_trouve, mot)) {
            cout << "Bravo : " << mot_trouve << endl;
            if (mot_trouve == mot) {
              ++(joueurs[j].points);
              cout << "-> GAGNÉ !" << endl;
            }
          } else {
            ++(joueurs[j].etape);
            cout << "Pas de chance : " << endl;
            cout << pendu[joueurs[j].etape-1] << endl;
            if (joueurs[j].etape >= nb_etapes) {
              cout << "-> PERDU !" << endl;
              ++(joueurs[i].points);
              --pouvant_jouer;
            }
          }
        }
      }
    }

    // le joueur qui a posé le mot peut à nouveau jouer si
    // il n'a pas été éliminé auparavant
    if (joueurs[i].etape < nb_etapes)
      ++(pouvant_jouer);

  }

  // resultats :
  cout << endl
       << "La partie est finie." << endl
       << "Résultats : " << endl;
  for (unsigned int j(0); j < nb_joueurs; ++j) {
    cout << "Joueur " << joueurs[j].nom << " (" << j+1  << ") ";
    if (joueurs[j].etape < nb_etapes) {
      cout << "encore en vie ! et avec "
           << joueurs[j].points << " point";
      if (joueurs[j].points > 1) cout << 's';
      cout << '.';
    } else {
      cout << "pendu... (points : " << joueurs[j].points << ")";
    }
    cout << endl;
  }

  return 0;
}
