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
int rev(string a, string b){
    int n=a.length();
    int m=b.length();
	if(n==1&&m==1){
		return 1;
	}
    if(n!=m){
        return 0;
    }
	if(a[0]==b[m-1]){
		return rev(a.substr(1,n),b.substr(0,m-1));
	}
}
int main()
{
    int t;
    s(t);
    while(t--)
    {
    	string a,b;
    	cin>>a>>b;
    	if(rev(a,b)==1)
    		cout<<"Yes\n";
    	else cout<<"No\n";
    	getch();
    }
return 0;
}