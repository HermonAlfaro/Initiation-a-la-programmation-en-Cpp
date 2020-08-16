// imports
#include <iostream>
#include <string>
using namespace std;

// prototypes
char code(char c, int d);

char decale(char c, char debut, int decalage);

string code(string s, int d);

string decode(string s, int d);



int main()
{
	//char t(decale('g', 'a', -133));
	//cout << t << endl;
	
	/*
	string o("Fuyez manants");
	string t(code(o, 4));
	string od(decode(t,4));
	
	cout << o << endl;
	cout << t << endl;
	cout << od << endl;
	*/
	
	return 0;
}

// definitions
char decale(char c, char debut, int decalage)
{
	char d;
	
	while (decalage<0)
	{
		decalage += 26;
	}
	
	d = debut + (((c - debut) + decalage) % 26);
	
	
	return d;
}

char code(char c, int d)
{
	if (c>='a' and c<='z')
	{
		return decale(c, 'a', d);
	}
	
	else if (c>='A' and c<='Z')
	{
		return decale(c, 'A', d);
	}
	
	else
	{
		return c;
	}
	
}

string code(string s, int d)
{
	string s_code("");
	
	for (size_t i(0); i<s.size(); ++i)
	{
		s_code += code(s[i], d);
	}
	
	return s_code;
	
}

string decode(string s, int d)
{
	return code(s, -d);
}
	
	
