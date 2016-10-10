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

int nonfib(int n)
{
	int a=1,b=2,c=3;
	while(n>0)
	{
		a=b;
		b=c;
		c=a+b;
		n-=(c-b-1);
	}
	n+=(c-b-1);
	return b+n;
}

int main()
{
    int t;
    s(t);
    while(t--)
    {
  		int n;
  		s(n);
  		int ans=nonfib(n);
  		p(ans);
    }
    getch();
    return 0;
}