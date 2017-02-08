#include <bits/stdc++.h>
using namespace std;
int main(){
	int s,t,a,b,m,n,c1=0,c2=0;
	cin>>s>>t;
	cin>>a>>b;
	cin>>m>>n;
	int app[m+2],ora[n+2];
	for (int i = 0; i < m; ++i)
	{
		cin>>app[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>ora[i];
	}
	for (int i = 0; i < m; ++i)
	{
		app[i]+=a;
		if(app[i]>=s && app[i]<=t){
			c1++;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		ora[i]+=b;
		if(ora[i]>=s && ora[i]<=t){
			c2++;
		}

	}
	cout<<c1<<endl<<c2<<endl;
}