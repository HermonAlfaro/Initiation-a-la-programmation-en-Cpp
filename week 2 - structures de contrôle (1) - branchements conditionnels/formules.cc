#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x;
	
	cout << "Entrez la valeur de x : ";
	cin >> x;
	
	
	// formule 1 : x / (1 - exp(x)). Indefinie quand x = 0
	if (x==0)
	{
		cout << "Expression 1 : indefinie" << endl;
	}
	else 
	{
		double f1(x / (1- exp(x)));
		cout << "formule 1 pour x egal a " << x << " vaut " << f1 << endl;
	}
	
	// formule 2 : xlog(x)exp(2/(x-1)). Indéfinie quand x = 1 et x <= 0
	if (x<=0 or x==1)
	{
		cout << "Expression 2: indefinie" << endl;
	}
	else
	{
		double f2(x*log(x)*exp(2/(x-1)));
		cout << "formule 2 pour x egal a " << x << " vaut " << f2 << endl;
	}
	
	// formule 3 : (-x-sqrt(x*x -8*x)) / (2-x). Indéfinie quand x = 2 et x entre 0 et 8
	if ( x>0 and x<8)
	{
		cout << "Expression 3: indefinie" << endl;
	}
	else
	{
		double f3((-x-sqrt(x*x -8*x)) / (2-x));
		cout << "formule 3 pour x egal a " << x << " vaut " << f3 << endl;
	}
	
	// formule 4 : sqrt((sin(x) - x/20.0 ) * log(x*x - 1/x))
	if (((sin(x) - x/20.)*log(x*x - 1/x) < 0.0) 
		or ((x*x - 1/x) <= 0.0)
		or (x==0))
	{
		cout << "Expression 4: indefinie" << endl;
	}
	else
	{
		double f4(sqrt((sin(x) - x/20.0 ) * log(x*x - 1/x)));
		cout << "formule 4 pour x egal a " << x << " vaut " << f4 << endl;
	}
	
		
	 
	
	
	return 0;
}
