#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,m;
		scanf("%lld %lld",&n,&m);
		int ans = m*n;
		ans--;
		if(ans%2 == 0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}