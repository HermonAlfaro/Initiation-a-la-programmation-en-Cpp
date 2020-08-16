#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	int D(1);
	cout << "Entrez un entier n > 1 : ";
	cin >> n;
	
	if (n%2==0 and n>2)
	{
		cout << n << " n'est pas premier, car il est divisible par 2" << endl;
	}
	else 
	{
		int i(3);
		do
		{
			if (n%i==0)
			{
				D = i;
			}
			
			i += 2;
		}
		while(i<=sqrt(n) and D==1);

		if (D!=1)
		{
			cout << n <<" n'est pas premier, car il est divisible par " << D << endl;
		}
		else
		{
			cout << n << " es premier" << endl;
		}
	
	}
	
	

	
	
	return 0;
}
