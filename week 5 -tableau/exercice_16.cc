#include <iostream>
#include <vector>
using namespace std;

double scalaire(vector<double> u, vector<double> v);

int main()
{
	cout <<"Entrez la taille n : ";
	int n;
	cin >> n;
	
	vector<double> u(n);
	vector<double> v(n);
	
	for(int i(0); i < n; ++i)
	{
		cout << "Entrez la composant " << i << " du premier vecteur : ";
		cin >> u[i];
	}
	
	for(int i(0); i < n; ++i)
	{
		cout << "Entrez la composant " << i << " du second vecteur : ";
		cin >> v[i];
	}
	
	double dot_prod(scalaire(u,v));
	
	cout << "Le produit scalaire est : " << dot_prod << endl;
	
	
	return 0;
}


double scalaire(vector<double> u, vector<double> v)
{
	double dot_prod(0);
	size_t taille(u.size());
	
	for(size_t i(0); i < taille; ++i)
	{
		dot_prod += u[i] * v[i];
	}
	
	return dot_prod;
}
