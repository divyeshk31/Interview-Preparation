#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
int min(int a, int b, int c){
	return min(min(a,b),c);
}
int edit_distance(string s, string t,int m, int n){
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++){
		for (int j=0;j<=n;j++)
		{
			if(i==0)
				dp[i][j]=j;
			if(j==0)
				dp[i][j]=i;
			else if(s[i-1]==t[j-1])
			dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
		}
	}
	return dp[m][n];
}

int main()
{
    string s,t;
    cin>>s>>t;
    int m=s.length();
	int n=t.length();
    int div=edit_distance(s,t,m,n);
    cout<<div<<endl;
    getch();
return 0;
}