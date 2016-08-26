#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)                printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)               printf("%lld\n",n)
#define ll long long int
int find(int a[30][30], int n,int x){
    int i=0, j=n-1;
    while(i<n && j>=0){
    if(a[i][j]==x){
        return 1;
    }
    else if(a[i][j]>x)
    j--;
    else
        i++;
}  
 return 0;
}

int main()
{
    int t;
    s(t);
    while(t--)
    {
        int x,n,m;
        s(n); s(m);
        int a[20][30];
        f(i,0,n){
            f(j,0,m)
            s(a[i][j]);
        }
        s(x);
        int a1 = find(a,n,x);
        if(a1==1)
        cout<<1<<endl;
        else cout<<0<<endl;
    }
return 0;
}

