#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define ll long long int
int main(){
	ll w,x,y,z;
	cin>>w>>x>>y>>z;
	if(w-(x+y+z)>=0){
		cout<<"Happy\n";
	}
	else cout<<"Sad\n";
	getch();
	return 0;
}