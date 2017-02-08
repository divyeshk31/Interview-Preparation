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
int main()
{
    int t;
    s(t);
    while(t--)
    {
  		int x1,y1,x2,y2;
  		int f=0;
  		s(x1); s(y1); s(x2); s(y2);
  		if(x1==x2){
  			if(y2>y1){
  				cout<<"up\n";
  				f=1;
  			}
  			else {
  				cout<<"down\n";
  				f=1;
  			}
  		}
  		if(y1==y2){
  			if(x2>x1){
  				cout<<"right\n";
  				f=1;
  			}
  			else {
  				cout<<"left\n";
  				f=1;
  			}
  		}
  		if(!f) cout<<"sad\n";
    }
    getch();
return 0;
}