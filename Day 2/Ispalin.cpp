#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
int ispalin(char s[],int n){
	if(n<2){
		return 1;
	}
    if(s[0]==s[n-1]){
        return ispalin(s+1,n-2);
    }
    return 0;	
}
int main()
{
    int t;
    s(t);
    while(t--)
    {
    	char s[256];
    	cin>>s;
        int n=strlen(s);
    	if((ispalin(s,n))==1){
    		cout<<"Yes\n";
    	}
    	else cout<<"No\n";
    }
    getch();
return 0;
}