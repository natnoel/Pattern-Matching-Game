//Name of prog:			LabTest2.cpp
//Name of student: 		Tan Shi Terng Leon
//Computer Serial no:	CNC7270NJF
//Full time
//Seat no:				62
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void constructStr (char [], int);
int checkChar (char [], char, int);
int matchPatterns (char [], char [], char []);
int computeWin (int, int);

int main ()
{
//Declaring variables
	srand (time (NULL));
	char pattern[7] = {"\0"};
	char guess [7] = {"\0"};
	char result [7] = {"\0"};
	int bet, match;
	char cont;
	do
	{
		constructStr (pattern, 6);
		cout<<setw(15)<<left<<"My Pattern"<<"= "<<"******"<<endl;
		cout<<setw(15)<<"Your bet in S$:"<<"= ";
		cin>>bet;
		cout<<setw(15)<<"Your guess"<<"= ";
		for (int i = 0; i < 6; i++)
		{
			cin>>guess[i];
		}
		
		for (int i = 0; i < 6; i++)
		{
			result[i] = pattern[i];
		}
		cout<<endl<<endl<<"RESULT"<<endl<<endl;
		match = matchPatterns (pattern, guess, result);
		cout<<setw(15)<<"My Pattern"<<"= "<<pattern<<endl
			<<setw(15)<<"Your guess"<<"= "<<guess<<endl
			<<setw(15)<<"Matching"<<"= "<<result<<endl
			<<setw(15)<<"Match pattern"<<"= "
			<<match<<" letters"<<endl
			<<setw(15)<<"You won S$"<<"= "<<computeWin (match, bet);//<<endl;
		if (computeWin (match, bet) > 0)
			cout<<" - Congratulations\n";
		else
			cout<<" - Please come again\n";
		cout<<"Continue (Y/N)?: ";
		cin>>cont;
	}while (cont == 'Y');
	return 0;
}

void constructStr (char a[], int size)
{
	bool repeat;
	
	for (int i = 0; i < size; i++)
	{
		repeat = true;
		while (repeat == true)
		{
			a[i] = static_cast<char>((rand () % ('Z' - 'A' + 1)) + 'A');
			repeat = false;
			for (int j = i-1; j >= 0; j--)
			{
				if (a[j] == a[i])
					repeat = true;
			}
		}
	}
}

int checkChar (char a[], char ch, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == ch)
			return i;
	}
	return -1;
}

int matchPatterns (char m[], char y[], char r[])
{
	int correct = 0;
	for (int j = 0; j < 6; j++)
	{
		if (checkChar (y, m[j], 6) != -1)
		{
			r[checkChar(y, m[j], 6)] = '*';
			correct++;
		}
	}
	return correct;	   
}

int computeWin (int n, int win)
{
	int money [7] = { 0, 5, 50, 200, 1000, 10000, 100000};
	return money [n] * win; 
}


