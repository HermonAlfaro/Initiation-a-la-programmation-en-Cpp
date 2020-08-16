#include <iostream>
#include <vector>
using namespace std;

vector<vector<double>> lire_matrice();

vector<vector<double>> multiplication(const vector<vector<double>>& M1,
									  const vector<vector<double>>& M2);
									  
void affiche_matrice(const vector<vector<double>>& M);

int main()
{
	
	vector<vector<double>> M1;
	vector<vector<double>> M2;
	
	cout << "Entrez les données de la premiere matrice : " << endl;
	M1 = lire_matrice();
	
	cout << "Entrez les données de la deuxieme matrice : " << endl;
	M2 = lire_matrice();
	
	if (M1[0].size()!= M2.size()){cout << "Multiplication de matrices impossible !" << endl;}
	
	else 
	{
		vector<vector<double>> M3(multiplication(M1, M2));
		
		cout <<"Resultat : " << endl;
		affiche_matrice(M3);
	}
	
	
	return 0;

}

vector<vector<double>> lire_matrice()
{
	
	cout << "Saisie d'une matrice : " << endl;
	
	cout << "	Nombre de lignes : ";
	int lin;
	cin >> lin;
	
	cout << "	Nombre de colonnes : ";
	int col;
	cin >> col;
	
	vector<vector<double>> M(lin, vector<double>(col));
	
	for(size_t i(0); i<M.size(); ++i)
	{
		for(size_t j(0); j<M[0].size(); ++j)
		{
			cout << "M[" << i << ", " << j << "]=";
			cin >> M[i][j];
			
		}
	}
	
	return M;
	
	
}

vector<vector<double>> multiplication(const vector<vector<double>>& M1,
const vector<vector<double>>& M2)
{
// crée la Matrice prod à la bonne taille *et* l'initialise
// avec des zéros :
vector<vector<double>> prod(M1.size(), vector<double>(M2[0].size()));
for (size_t i(0); i < M1.size(); ++i)
for (size_t j(0); j < M2[0].size(); ++j)
for (size_t k(0); k < M2.size(); ++k)
prod[i][j] += M1[i][k] * M2[k][j];
return prod;
}



void affiche_matrice(const vector<vector<double>>& M)
{
	for(size_t i(0); i<M.size(); ++i)
	{
		for(size_t j(0); j<M[0].size(); ++j)
		{
			cout << M[i][j] << " ";
		}
		cout << "" << endl;
		
	}	
}







