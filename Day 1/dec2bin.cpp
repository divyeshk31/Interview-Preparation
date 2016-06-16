#include <bits/stdc++.h>

using namespace std;
int bin(int n){
    int rem,i=1,bin=0,ans=0;
    while(n!=0){
        rem=n%2;
        n/=2;
        bin=bin+(rem*i);
        i*=10;
    }
    return bin;
}
int main()
{
    int n;
    cin>>n;
    cout<<bin(n);
    return 0;
}
