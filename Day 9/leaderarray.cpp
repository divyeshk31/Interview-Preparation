#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
void leader(int a[], int n){
	int maxtillnow = a[n-1];
	cout << maxtillnow << " ";
	for (int i = n-2; i >= 0; i--)
	{
		if (maxtillnow < a[i])
		{		 
			maxtillnow = a[i];
			cout << maxtillnow << " ";
		}
	} 
}
int main()
{
	int n;
	cin>>n;
	int a[n+2];
	for(int i=0;i<n;i++)
		cin>>a[i];
	leader(a,n);
	getch();
	return 0;
}
	