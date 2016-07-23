#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
int longestpaln(string s){
	string ans="";
	int m=s.size();
	for(int i=m;i>=0;i--){
		ans+=s[i];
	}
	int n=ans.size();
	int LCS[m+1][n+1];
	for(int i=0;i<=m;i++){
		for (int j=0;j<=n;j++)
		{
			if(i==0||j==0)
				LCS[i][j]=0;
			else if(s[i-1]==ans[j-1])
			LCS[i][j]=LCS[i-1][j-1]+1;
			else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
		}
	}
	return LCS[m][n];
}
int main(){
	string s;
	cin>>s;
	int ans=longestpaln(s);
	cout<<ans<<endl;
	//getch();
	return 0;
}