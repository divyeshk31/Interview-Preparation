#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)                printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)               printf("%lld\n",n)
#define ll long long int
double sum(int k, int a){
    if(k==0){
        return 1;
    }
    a*=2;
    return (double(1.0/a) + sum(k-1,a));
}
int main()
{
    int t;
    s(t);
    while(t--)
    {
        int k;
        cin>>k;
        int a=1;
        double ans=sum(k,a);
        cout<<ans<<endl;;
    }
return 0;
}