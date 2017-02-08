#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define ll long long int
int main(){
	int n;
	cin>>n;
	int a[n+2];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int flag=0;
	for (int i = 1; i < n; ++i)
	{
		if(a[i]<a[i-1]){
			flag=1;
			break;
		}
	}
	if(flag)
		cout<<"Angry\n";
	else
		cout<<"Happy\n";
	getch();
	return 0;
}