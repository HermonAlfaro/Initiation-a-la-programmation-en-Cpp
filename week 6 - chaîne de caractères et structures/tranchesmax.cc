#include <iostream>
#include <vector>
using namespace std;

// Prototypes
int somme_consecutifs_max(vector<int> v);
vector<size_t> lignes_max(vector<vector<int>> v);
vector<vector<int>> tranches_max(vector<vector<int>> v);

int main()
{
	return 0;
}

int somme_consecutifs_max(vector<int> v)
{
	int max_cons(0);
	int best_max(0);
	
	for(size_t i(0); i<v.size(); ++i)
	{
		max_cons += v[i];
		
		if(v[i]==0)
		{
			max_cons = 0;
		}
		
		if (max_cons>best_max){best_max=max_cons;}
	}
	
	return best_max;
}

vector<size_t> lignes_max(vector<vector<int>> v)
{
	vector<size_t> vect_lignes;
	int best_max(0);
	
	for(auto ligne : v)
	{
		int max_ligne(somme_consecutifs_max(ligne));
		if (max_ligne>best_max)
		{
			best_max = max_ligne;
		}
		
	}
	
	for(size_t i(0); i<v.size(); ++i)
	{
		int max_ligne(somme_consecutifs_max(v[i]));
		if (max_ligne==best_max)
		{
			vect_lignes.push_back(i);
		}
		
	}
	
	return vect_lignes;
}

vector<vector<int>> tranches_max(vector<vector<int>> v)
{
	vector<vector<int>> vect_res;
	
	vector<size_t> indices(lignes_max(v));
	
	for (auto i : indices)
	{
		vect_res.push_back(v[i]);
	}
	
	return vect_res;
	
}









	
