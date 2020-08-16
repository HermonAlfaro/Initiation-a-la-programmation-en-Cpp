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

  for (unsigned int i(0); i < exam.size(); i++) {
    if (poser_question(exam[i]) == exam[i].solution) {
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
  for (unsigned int i(0); i < q.reponses.size(); i++) {
    cout << "    " << i+1 << "- " << q.reponses[i] << endl;
  }
}

// ======================================================================
unsigned int demander_nombre(unsigned int a, unsigned int b)
{
  unsigned int res;

  if (a > b) { res=b; b=a; a=res; }

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
  return demander_nombre(1,q.reponses.size());
}

// ======================================================================
Examen creer_examen()
{
  QCM q;
  Examen retour;

  q.question = "Combien de dents possède un éléphant adulte";
  q.reponses.clear();
  q.reponses.push_back("32");
  q.reponses.push_back("de 6 à 10");
  q.reponses.push_back("beaucoup");
  q.reponses.push_back("24");
  q.reponses.push_back("2");
  q.solution=2;
  retour.push_back(q);

  q.question = "Laquelle des instructions suivantes est un prototype de fonction";
  q.reponses.clear();
  q.reponses.push_back("int f(0);");
  q.reponses.push_back("int f(int 0);");
  q.reponses.push_back("int f(int i);");
  q.reponses.push_back("int f(i);");
  q.solution=3;
  retour.push_back(q);

  q.question = "Qui pose des questions stupides";
  q.reponses.clear();
  q.reponses.push_back("le prof. de math");
  q.reponses.push_back("mon copain/ma copine");
  q.reponses.push_back("le prof. de physique");
  q.reponses.push_back("moi");
  q.reponses.push_back("le prof. d'info");
  q.reponses.push_back("personne, il n'y a pas de question stupide");
  q.reponses.push_back("les sondages");
  q.solution=6;
  retour.push_back(q);

  return retour;
}
