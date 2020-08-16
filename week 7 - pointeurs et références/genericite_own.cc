#include <iostream>
#include <memory>
using namespace std;


int main()
{
	double valeur1(1.0);
	double valeur2(2.0);
	double valeur3(3.0);
	
	double* choix;
	
	int val;
	do
	{
		cout << "Entre une valeur entre 1 et 3 :  ";
		cin >> val;
		
	}
	while(val<1 or val>3);
	
	if (val==1){choix = &valeur1;}
	else if(val==2){choix = &valeur2;}
	else {choix = &valeur3;}
	
	cout <<"vous avez choisi : " << *choix << endl;

	return 0;
}
