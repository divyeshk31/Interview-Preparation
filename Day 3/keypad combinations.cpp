#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

string getlastdigit(int n)
{	
	string str;

	switch(n)
	{
	case 1 : str = " "; return str;
	case 2: str = "abc"; return str;
	case 3: str = "def"; return str;
	case 4: str = "ghi"; return str;
	case 5: str = "jkl"; return str;
	case 6: str = "mno"; return str;
	case 7: str = "pqrs"; return str;
	case 8: str = "tuv"; return str;
	case 9: str = "wxyz"; return str;
	}
}

void printallcombination(int n , string str)
{
	if(n==0) 
		{	
			cout<< str<< endl;
			return ;
		}
 string lastdigitoption = getlastdigit(n%10);
 for(int i=0;i<lastdigitoption.size();i++)
 	printallcombination(n/10,lastdigitoption[i]+str);
 return;
}

int main()
{
	int n;
	cout<<"Enter the keypad number : ";
	cin>>n;
	printallcombination(n,"");
	getch();
	return 0;
}