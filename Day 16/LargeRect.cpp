#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
int large(int a[], int n){
	int maxarea=0;
	int areatop, tp;
	stack<int> s;
	int i=0;
	while(i<n){
		if(s.empty() || a[s.top()]<=a[i]){
			s.push(i++);
		}
		else{
			tp=s.top();
			s.pop();
			areatop=a[tp]*(s.empty()?i:i-s.top()-1);
			if(maxarea<areatop)
				maxarea=areatop;
		}
	}
	while(!s.empty()){
		tp=s.top();
			s.pop();
			areatop=a[tp]*(s.empty()?i:i-s.top()-1);
			if(maxarea<areatop)
				maxarea=areatop;
	}
	return maxarea;
}
int main()
{
    int t;
    s(t);
    while(t--)
    {
  		int n;
  		s(n);
  		int a[n];
  		f(i,0,n)
  		s(a[i]);
  		int ans=large(a,n);
  		p(ans);
    }
return 0;
}
