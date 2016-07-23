#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
int counsteps(int n){
	int dp[n+1];
	dp[1]=0;
	f(i,2,n){
		dp[i]=1+dp[i-1];
		if(i%2==0)
			dp[i]=min(dp[i],1+dp[i/2]);
		if(i%3==0)
			dp[i]=min(dp[i],1+dp[i/3]);
	}
	return dp[n];
}
int main(){
	int n;
	s(n);
	int ans=counsteps(n);
	p(ans);
	//getch();
	return 0;
}