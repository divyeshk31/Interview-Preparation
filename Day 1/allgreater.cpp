#include <bits/stdc++.h>

using namespace std;
int fact(int n){
if(n==0)
    return 1;
else return  (n*fact(n-1));
}
int great(int a[],int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
        {
            int c=0;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>a[i])
            {
                c++;
            }
        }
           ans+=c*fact(n-i-1);
        }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int a[n+2];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans1=great(a,n);
    cout<<ans1<<endl;
    return 0;
}
