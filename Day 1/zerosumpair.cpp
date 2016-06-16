#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
void pai(int arr[], int arr_size, int sum)
{
  int i, temp;
  bool binMap[MAX] = {0};

  for (i = 0; i < arr_size; i++)
  {
      temp = sum - arr[i];
      if (temp >= 0 && binMap[temp] == 1)
         printf("Pair with given sum %d is (%d, %d) \n",sum, arr[i], temp);
      binMap[arr[i]] = 1;
  }
}
int main()
{
    int n,x;
    cin>>n>>x;
    int a[n+2];
    for(int i=0;i<n;i++)
        cin>>a[i];
    pai(a,n,x);
    return 0;
}
