#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

string FlipString(string a)
{
	reverse(a.begin(), a.end());
	return a;
}
string haslo;
void add(int x)
{
	string h = "a";
	string help2;
	while (x > 0)
	{

		if (x % 100 >= 65 && x % 100 <= 90)
		{

			h[0] = x % 100;
			help2.append(h);

		}
		x = x / 100;
	}
	string help3 = FlipString(help2);
	haslo.append(help3);
}
int main()
{
	////4.1
	ifstream przyk("przyklad.txt");
	ifstream napis("napisy.txt");
	ofstream wyniki("wyniki4.txt");
	int ileLiczb = 0;
	string t[1000];
	for (int i = 0; i < 1000; i++)
	{
		przyk >> t[i];
		for (int j = 0; j < 50; j++)
		{
			if (isdigit(t[i][j]))
			{
				ileLiczb++;
			}
		}
	}
	wyniki << "4.1" << endl;
	wyniki << ileLiczb << endl;
	//4.2
	int x = 0;
	wyniki << "4.2" << endl;
	for (int i = 19; i < 1000; i += 20)
	{
		wyniki << t[i][x];
		x++;
	}
	//4.3
	string s[1000];
	ifstream napis2("napisy.txt");
	int ilePalindrom = 0;
	wyniki << endl << "4.3" << endl;
	for (int i = 0; i < 1000; i++)
	{
		napis2 >> s[i];
		string opcja1 = s[i] + s[i][0];
		string opcja2 = s[s[i].size() - 1] + s[i];
		string palindrom1 = FlipString(opcja1);
		string palindrom2 = FlipString(opcja2);
		if (opcja1 == palindrom1)
		{
			wyniki << opcja1[(opcja1.size() - 1) / 2];
		}
		if (opcja2 == palindrom2)
		{
			wyniki << opcja2[(opcja2.size() - 1) / 2];
		}
	}
	//4.4
	ifstream napis3("przyklad.txt");
	string tab[1000];
	wyniki << endl << "4.4" << endl;
	for (int i = 0; i < 1000; i++)
	{
		napis3 >> tab[i];
		int ileCyfr = 0;
		string onlyCyfry;
		for (int j = 0; j < 50; j++)
		{
			if (isdigit(tab[i][j]))
			{
				onlyCyfry = onlyCyfry + tab[i][j];
				ileCyfr++;
			}
		}
		if (ileCyfr > 0)
		{
			if (ileCyfr % 2 != 0)
			{
				onlyCyfry.pop_back();
			}
			
			int CyfryInt = stoi(onlyCyfry);
			if (haslo.size() > 3)
			{
				if (haslo[haslo.size() - 1] == 88 && haslo[haslo.size() - 2] == 88 && haslo[haslo.size() - 3] == 88)
				{
					break;
				}
				else
				{
					add(CyfryInt);
				}
			}
			else
			{
				add(CyfryInt);
			}
		}
	}
	wyniki << haslo;
}
