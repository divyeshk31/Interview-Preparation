#include <bits/stdc++.h>
#include <tr1/unordered_set>
using namespace std::tr1;
#include <conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
bool isProduct(int arr[], int n, int x)
{
    if (n < 2)
        return false;
    unordered_set<int> s;
    f(i,0,n)
    {
        if (arr[i] == 0)
        {
           if (x == 0)
               return true;
           else
               continue;
        }
            if (x%arr[i] == 0)
        {
            if (s.find(x/arr[i]) != s.end())
               return true;
            s.insert(arr[i]);
        }
    }
    return false;
}
int main()
{
    int t;
    s(t);
    while(t--)
    {
        int n,prod,flag;
        cin>>n>>prod;
        int a[n];
        f(i,0,n)
        cin>>a[i];
       flag=isProduct(a,n,prod);
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
        getch();
    }
return 0;
}
