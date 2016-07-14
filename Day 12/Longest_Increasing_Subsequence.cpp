#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <conio.h>
#include <algorithm>
using namespace std;

int lis(vector<int>& arr){
    int n=arr.size();
     int i,j;
     int max=0;
     int lis[n];
    for (i = 0; i < n; i++ )
        lis[i] = 1;
    for (i = 1; i < n; i++ ){
        for (j = 0; j < i; j++ ){
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;}}
    for (i = 0; i < n; i++ ){
        if (max < lis[i]){
            max = lis[i];}}
    return max;
}
int main() {
   int n,x;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    int ans=lis(a);
    cout<<ans<<endl;
 	getch();
    return 0;
}
