#include <iostream>
#include <conio.h>
using namespace std;

void printlex(int n , int x)
{

	if(x>n) return;

	if(x<=n) 
		cout<< x << endl;

	for(int i =0;i<10;i++)
		printlex(n,x*10+i);
}


void lex(int n)
{

	for(int i=1;i<10;i++)
		printlex(n,i);

}
int main()
{
	int n;
	cin>> n;
	lex(n);
	getch();
	return 0;
}