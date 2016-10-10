#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
void rev(int a[], int s, int e){
	while(s<e){
		int temp=a[s];
		a[s]=a[e];
		a[e]=temp;
		s++;
		e--;
	}
}
void leftrotate(int a[], int n, int k){
	rev(a,0,k-1);
	rev(a,k,n-1);
	rev(a,0,n-1);
}
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	leftrotate(a,n,k);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	getch();
	return 0;
}