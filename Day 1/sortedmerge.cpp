#include <bits/stdc++.h>

using namespace std;
void merge(int a[],int b[],int n,int m){
    int i=0,j=0,k=0;
    int c[10001];
    while(i<n && j<m){
    if(a[i]<b[j])
      {
          c[k]=a[i];
    k++; i++;
    }
    else {
        c[k]=b[j];
        k++;
        j++;
    }
    }
    while(i<n){

        c[k]=a[i];
        k++;i++;
    }

    while(j<m){
        c[k]=b[j];
        k++;j++;
    }
    for(int i=0;i<k;i++)
        cout<<c[i]<<" ";
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+2],b[m+2];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    merge(a,b,n,m);
    return 0;
}
