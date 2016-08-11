#include<bits/stdc++.h>
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
        int n;
        s(n);
       int s[n];
       for (int i = 0; i < n; ++i)
       {
       	cin>>s[i];
       }
        int flag=0;
        int ans[256]={0};
        f(i,0,n){
            ans[s[i]]++;
        }
        f(i,0,n){
            if(ans[s[i]]==1)
         {   cout<<s[i]<<endl;
            flag=1;
            break;
        }
       
        }
        if(flag==0)
        cout<<-1<<endl;
    }
return 0;
}
