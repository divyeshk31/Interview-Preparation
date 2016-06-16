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
ll czero(ll n){
	if(n<0)
		return 1;
	if(n<10)
		return 0;
	ll rem=n%10;
	if(rem==0)
		return 1+czero(n/10);
	else return czero(n/10);
}
int main()
{
	int t;
	cin>>t;
	while(t--){
    ll n;
    cin>>n;
    cout<<czero(n)<<endl;

    getch();
}
    return 0;
}