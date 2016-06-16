/*
1
2 3
4 5 6
7 8 9 10
*/

#include<iostream>
using namespace std;

void pattern(int n)
{
	int count = 1;
	for(int i =0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout<< count++ << " "; 
		}
		cout<< endl;
	}
}


int main()
{
	int n;
	cout<<"Enter the number of rows.";
	cin>> n;
	pattern(n);
}