#include <iostream>
using namespace std;

int main()
{
	double x;
	
	cout << "Entre la valeur de x : ";
	cin >> x;
	
	if ( (x>=-1.0) and (x<1.0) )
	{
		cout << "x appartient a I " << endl;
	}
	else 
	{
		cout << "x n'appartient pas a I " << endl;
	}
	
	return 0;
}
