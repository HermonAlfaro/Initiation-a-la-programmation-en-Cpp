#include <iostream>
using namespace std;


int main ()
{
	double x;
	
	cout << "Entrez la valeur de x : ";
	cin >> x;
	
	if ((not(x<2) and x<3) 
		or ((not(x<0) and not(x==0)) and (x<1 or x==1)) 
		or (not(x<-10) and ((x<-2) or (x==2))))
	{
		cout << "x appartient a I" << endl;
	}
	else
	{
		cout << "x n'appartient a I" << endl;
	}
	
	return 0;

}
