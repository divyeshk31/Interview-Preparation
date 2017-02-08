#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
int LCS_DP(int a[], int b[],int m, int n){
	int LCS[m+1][n+1];
	f(i,0,m){
		LCS[i][0]=0;
	}
	f(j,0,n){
		LCS[0][j]=0;
	}
	for(int i=1;i<=m;i++){
		for (int j=1;j<=n;j++)
		{
		 if(a[i-1]==b[j-1])
			LCS[i][j]=LCS[i-1][j-1]+1;
			else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
		}
	}
	int index = LCS[m][n];
   int lcs[index+1];
    int k=0;
 	int i = m, j = n;
   while (i > 0 && j > 0)
   {
      if (a[i-1] == b[j-1])
      {
          lcs[index-1] = a[i-1]; 
          i--;
          k++; 
          j--; 
          index--;     
      }
 	else if (LCS[i-1][j] > LCS[i][j-1])
         i--;
      else
         j--;
   }
 
 	for (int i = 0; i < k; ++i)
 	 {
 	 	cout<<lcs[i]<<" ";
 	 } 
}

int main()
{
    int s,t;
    cin>>s>>t;
    int a[s],b[t];
    for (int i = 0; i < s; ++i)
    {
    	cin>>a[i];
    }
    for (int i = 0; i < t; ++i)
    {
    	cin>>b[i];
    }
    LCS_DP(a,b,s,t);
   	getch();
return 0;
}