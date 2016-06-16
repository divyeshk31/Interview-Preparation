#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a1=0,a2=0;
    int a[n+2];
    for(int i=0;i<n;i++){
        cin>>a[i];
        a1^=a[i];
    }
    //cout<<a1<<endl;
    for(int i=0;i<=n-2;i++){
        a2^=i;
    }
    //cout<<a2<<endl;
    cout<<(a1^a2);
    return 0;
}
