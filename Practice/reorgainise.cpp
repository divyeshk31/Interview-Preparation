#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
int main()
{
    int t;
    s(t);
    while(t--)
    {
  		int n,flag=0;
  		s(n);
  		ll a[n];
  		f(i,0,n)
  		sl(a[i]);
  		if(n==0 || n==1){
  			cout<<"YES\n";
  			continue;
  		}
  		sort(a,a+n);
  		f(i,1,n){
  			if((a[i]-a[i-1])>1){
  				flag=1;
  				break;
  			}
  		}
  		if(flag){
  			cout<<"NO\n";
  		}
  		else cout<<"YES\n";
    }
   // getch();
return 0;
}