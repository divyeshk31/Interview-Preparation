#include <bits/stdc++.h>
using namespace std;
void uni(int arr1[], int arr2[], int n, int m){
   int i = 0, j = 0;
  while (i < n && j < m)
  {
    if (arr1[i] < arr2[j])
      printf(" %d ", arr1[i++]);
    else if (arr2[j] < arr1[i])
      printf(" %d ", arr2[j++]);
    else
    {
      printf(" %d ", arr2[j++]);
      i++;
    }
  }
  while(i < m)
printf(" %d ", arr1[i++]);
while(j < n)
printf(" %d ", arr2[j++]);
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
    uni(a,b,n,m);
    return 0;
}
