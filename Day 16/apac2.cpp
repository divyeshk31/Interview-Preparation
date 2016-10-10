#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll min(ll x,ll y)
{
	if(x<=y)
	return x;
	else
	return y;
}
ll max(ll x,ll y)
{
	if(x>=y)
	return x;
	else
	return y;
}
int main()
{
//	freopen("A-large.in","r",stdin);
//	freopen("anshu.out","w",stdout);
	int t;
	int j=0;
	cin>>t;
	int l=1;
	for(j=0;j<t;j++)
	{
		
		ll n,l1,r1,a,b,c1,c2,m;
		cin>>n>>l1>>r1>>a>>b>>c1>>c2>>m;
		ll L[n+1];
		ll R[n+1];
		ll x[n+1];
		ll y[n+1];
		L[1]=l1;
		R[1]=r1;
		ll i;
		cout<<l1<<" "<<r1<<"\n";
		for(i=2;i<=n;i++)
		{
			x[i]=(a*x[i-1] + b*y[i-1] + c1)%m;
			y[i]=(a*y[i-1] + b*x[i-1] + c2)%m;
		}
		for(i=2;i<=n;i++)
		{
			L[i]=min(x[i],y[i]);
			R[i]=max(x[i],y[i]);
			cout<<L[i]<<" "<<R[i]<<"\n";
		}
		l++;
	}
	return 0;
}
