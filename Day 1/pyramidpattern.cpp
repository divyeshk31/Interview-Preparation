/*
        1
      2 3 2
    3 4 5 3 2
  4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5
*/

#include<iostream>
using namespace std;


void pyramidpattern(int n)
{
	int d = n-1 , j;

	for(int i =1;i<=n;i++)
	{
		for(j=0;j<d;j++)
			cout<<" ";
		d--;

		for(j=i;j<2*i-1;j++)
			cout<< j;
		for(;j>=i; j--)
			cout<< j ;
		cout<< endl;
	}
}



int main()
{
	int n;
	cout<< " Enter the number of rows : " ;
	cin>> n;

	pyramidpattern(n);

}