#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int const taille(10);
	vector<int> tab;
	for(size_t i(0); i < taille; ++i)
	{
		tab.push_back(tab.size());
	}
	
	for(auto e : tab){cout << e << endl;}
	
	return 0;
}
