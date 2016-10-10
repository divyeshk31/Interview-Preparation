#include <bits/stdc++.h>
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
		string n;
		cin>>n;
		int one=0,zero=0;
		f(i,0,n.size()){
			if(n[i]=='1')
				one++;
			else zero++;
		}
		if((zero==1 || one==1))
            printf("Yes\n");
        else
            printf("No\n");
			
    }
return 0;
}
