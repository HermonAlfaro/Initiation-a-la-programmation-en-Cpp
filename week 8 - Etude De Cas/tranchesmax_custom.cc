#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Sequence;

typedef size_t Position;

struct SousSequence
{
	Position debut;
	Position fin;
	int somme;
}; 

SousSequence tranche_max_1(Sequence seq);
SousSequence tranche_max_2(Sequence seq);
SousSequence tranche_max_3(Sequence seq);

int main()
{
	Sequence seq = {3,4,1,2,-3};
	
	SousSequence sousseq_1(tranche_max_1(seq));
	SousSequence sousseq_2(tranche_max_2(seq));
	SousSequence sousseq_3(tranche_max_3(seq));
	
	cout <<" tranche max 1 " << endl;
	cout << "Debut : " << sousseq_1.debut << endl;
	cout <<"Fin : " << sousseq_1.fin << endl;
	cout <<"Somme : " << sousseq_1.somme << endl;
	cout << endl;
	
	cout <<" tranche max 2 " << endl;
	cout << "Debut : " << sousseq_2.debut << endl;
	cout <<"Fin : " << sousseq_2.fin << endl;
	cout <<"Somme : " << sousseq_2.somme << endl;
	cout << endl;
	
	cout <<" tranche max 3 " << endl;
	cout << "Debut : " << sousseq_3.debut << endl;
	cout <<"Fin : " << sousseq_3.fin << endl;
	cout <<"Somme : " << sousseq_3.somme << endl;
	cout << endl;

	return 0;
}

SousSequence tranche_max_1(Sequence seq)
{
	int somme(0);
	SousSequence soussequence = {0, 0, seq[0]};
	
	for (size_t d(0); d<seq.size(); ++d)
	{
		for (size_t f(d); f<seq.size(); ++f)
		{
			somme = 0;			
			for (size_t i(d); i<=f; ++i)
			{
				somme = somme + seq[i];
			}
			
			if (somme > soussequence.somme)
			{
				soussequence = {d, f, somme};
			}
		
		}
	}
	
	
	return soussequence;
}

SousSequence tranche_max_2(Sequence seq)
{
	int somme(0);
	SousSequence soussequence = {0, 0, seq[0]};
	
	for (size_t d(0); d<seq.size(); ++d)
	{
		somme = 0;
		for (size_t f(d); f<seq.size(); ++f)
		{
			somme += seq[f];				
			if (somme > soussequence.somme)
			{
				soussequence = {d, f, somme};
			}
		}
	}
	
	
	return soussequence;
}

SousSequence tranche_max_3(Sequence seq)
{
	
	SousSequence soussequence = {0, 0, seq[0]};
	size_t debut = 0;
	int somme(0);
	
	for (size_t f(0); f<seq.size(); ++f)
	{
		somme += seq[f];				
		
		if (somme > soussequence.somme)
		{
			soussequence = {debut, f, somme};
		}
		
		if (somme<=0)
		{
			debut = f+1;
			somme = 0;
		}
		
	}
	
	return soussequence;
}
