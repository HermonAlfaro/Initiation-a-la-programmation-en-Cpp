#include <iostream>
#include <string>
using namespace std;

void genereLettre(bool masculin, string destinataire, string sujet,
                  unsigned int jour, unsigned int mois,
                  string politesse, string auteur)
{
  cout << "Bonjour ";
  if (masculin) cout << "cher";
  else cout << "chère";
  cout << " " << destinataire << "," << endl;

  cout 
    << "Je vous écris à propos de " << sujet << endl
    << "Il faudrait que nous nous voyons le " << jour << "/" << mois 
    << " pour en discuter." << endl
    << "Donnez-moi vite de vos nouvelles !" << endl
    << politesse << ", " << auteur << endl;
}

int main()
{
  genereLettre(false, "Mireille", "votre cours" , 18, 12,
               "Amicalement", "John");
  cout << endl;
  genereLettre(true, "John", "votre demande de rendez-vous", 16, 12,
               "Sincèrement", "Mireille");
  return 0;
}
