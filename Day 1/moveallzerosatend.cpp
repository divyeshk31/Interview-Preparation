#include <bits/stdc++.h>
#include<conio.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n+2];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]!=0)
            a[c++]=a[i];
    }
    while(c<n)
        a[c++]=0;
    for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
getch();
return 0;
}
