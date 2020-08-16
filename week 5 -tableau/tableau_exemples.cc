#include <iostream>
#include <vector>
using namespace std;

// prototype
void saisie(vector<int>& vector, size_t taille);

int main()
{
	vector<int> tab(12);
	
	saisie(tab, tab.size());
	

	return 0;
}

void saisie(vector<int>& vector, size_t taille=4)
{
	vector.clear();
	cout << "Saisie de " << taille  << " valeurs :" << endl;
	while (vector.size() < taille)
	{
		cout << "Entrez la valeur " << vector.size() << " : ";
		int val;
		cin >> val;
		if ((val < 0) and (not vector.empty())) { vector.pop_back();}
		else if (val==0) {vector.clear();}
		else {vector.push_back(val);} 
	}
	
	for(auto e : vector) {cout << e << endl;}
	
}
