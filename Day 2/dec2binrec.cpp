#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
int dec2bin(int n){
	if(n<2){
		return n;
	}
	int rem=n%2;
	int m=dec2bin(n/2);
	return m*10+rem;
}
int main()
{
    int t;
    s(t);
    while(t--)
    {
    	int n;
    	cin>>n;
    	cout<<dec2bin(n)<<endl;
    }
return 0;
}
