#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct QCM {
  string question;
  vector<string> reponses;
  unsigned int solution;
};

typedef vector<QCM> Examen;

void affiche(const QCM& question);
unsigned int demander_nombre(unsigned int min, unsigned int max);
unsigned int poser_question(const QCM& question);
Examen creer_examen();

// ======================================================================
int main()
{
  unsigned int note(0);
  Examen exam(creer_examen());

  for (auto question : exam) {
    if (poser_question(question) == question.solution) {
      ++note;
    }
  }

  cout << "Vous avez trouvé " << note << " bonne";
  if (note > 1) cout << 's';
  cout << " réponse";
  if (note > 1) cout << 's';
  cout << " sur " << exam.size() << "." << endl;

  return 0;
}

// ======================================================================
void affiche(const QCM& q)
{
  cout << q.question << " ?" << endl;
  unsigned int i(0);
  for (auto reponse : q.reponses) {
    cout << "    " << ++i << "- " << reponse << endl;
  }
}

// ======================================================================
unsigned int demander_nombre(unsigned int a, unsigned int b)
{
  /* échange les arguments s'ils n'ont pas été donnés dans *
   * le bon sens.                                          */
  if (a > b) { unsigned int tmp(b); b=a; a=tmp; }

  unsigned int res;
  do {
    cout << "Entrez un nombre entier compris entre "
         << a << " et " << b <<" : ";
    cin >> res;
  } while ((res < a) or (res > b));

  return res;
}

// ======================================================================
unsigned int poser_question(const QCM& q)
{
  affiche(q);
  return demander_nombre(1, q.reponses.size());
}

// ======================================================================
Examen creer_examen()
{
  return {
    // Question 1
    { "Combien de dents possède un éléphant adulte",
      { "32", "de 6 à 10", "beaucoup", "24", "2" },
      2 // réponse
    },

    // Question 2
    { "Laquelle des instructions suivantes est un prototype de fonction",
      { "int f(0);"     ,
        "int f(int 0);" ,
        "int f(int i);" ,
        "int f(i);"     },
      3 // réponse
    },

    // Question 3
    { "Qui pose des questions stupides",
      { "le prof. de math",
        "mon copain/ma copine",
        "le prof. de physique",
        "moi",
        "le prof. d'info",
        "personne, il n'y a pas de question stupide",
        "les sondages" } ,
      6 // réponse
    }
  };
}
