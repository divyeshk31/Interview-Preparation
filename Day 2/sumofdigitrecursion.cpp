#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
int sumof(int n){
	if(n==0){
		return 0;
	}
	int r=n%10;
	if(r==0){
		return sumof(n/10);
	}
	else return r+sumof(n/10);
}
int main()
{
    int t;
    s(t);
    while(t--)
    {	
    	int n;
    	cin>>n;
    	int k=sumof(n);
    	cout<<k<<endl;
    }
return 0;
}