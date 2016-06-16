#include <bits/stdc++.h>
using namespace std;
bool ispm(string a, string b){
    int c1[256]={0};
    int c2[256]={0};
    int i;
    for(i=0;a[i]&&b[i];i++)
    {

        c1[a[i]]++;
        c2[b[i]]++;
    }
    int m=a.length();
    int n=b.length();
    if(m!=n)
        return false;
    for(i=0;i<256;i++)
        if(c1[i]!=c2[i])
            return false;
    return true;
}
int main()
{
    string a,b;
    cin>>a>>b;
    if(ispm(a,b))
        cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
