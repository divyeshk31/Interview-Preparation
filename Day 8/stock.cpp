#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
void calculateSpan(int a[], int n, int ans[])
{
   stack<int> st;
   st.push(0);
  ans[0] = 1;
   f(i,1,n)
   {
      while (!st.empty() && a[st.top()] <= a[i])
         st.pop();
      ans[i] = (st.empty())? (i + 1) : (i - st.top());
      st.push(i);
   }
}

int main()
{
    int n;
    s(n);
    int ans[n+1];
    int a[n+2];
    f(i,0,n)
    s(a[i]);
    calculateSpan(a,n,ans);
    f(i,0,n)
    cout<<ans[i]<<" ";
    return 0;
}
