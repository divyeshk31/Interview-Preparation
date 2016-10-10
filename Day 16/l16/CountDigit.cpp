#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int count(int n){
	int c=0;
	while(n>0){
		n/=10;
		c++;
	}
	return c;
}
int main(){
	int n,t;
	cin>>t;
	while(t--){
	cin>>n;
	int ans=count(n);
	cout<<ans<<endl;
	getch();
	}
	return 0;
}