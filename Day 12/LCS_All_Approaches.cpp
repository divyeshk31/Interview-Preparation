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
int LCS_DP(char *s, char *t,int m, int n){
	int LCS[m+1][n+1];
	for(int i=0;i<=m;i++){
		for (int j=0;j<=n;j++)
		{
			if(i==0||j==0)
				LCS[i][j]=0;
			else if(s[i-1]==t[j-1])
			LCS[i][j]=LCS[i-1][j-1]+1;
			else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
		}
	}
	return LCS[m][n];
}
int LCS_Recursive(char *s, char *t,int m, int n){
	if(m==0||n==0)return 0;
	if(s[m-1]==t[n-1]){
		return 1+LCS_Recursive(s,t,m-1,n-1);
	}
	else return max(LCS_Recursive(s,t,m,n-1),LCS_Recursive(s,t,m-1,n));
}
int main()
{
    char s[100], t[100];
    cin>>s>>t;
    int m=strlen(s);
	int n=strlen(t);
    int ans=LCS_Recursive(s,t,m,n);
    int div=LCS_DP(s,t,m,n);
    cout<<ans<<endl;
    cout<<div<<endl;
    getch();
return 0;
}