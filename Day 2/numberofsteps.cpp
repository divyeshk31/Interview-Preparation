#include <iostream>
//#include<conio.h>
using namespace std;
int stepdp(int n)
{
    int res[n];
    res[0] = 1; res[1] = 1;
    for (int i=2; i<n; i++)
    {
       res[i] = 0;
       for (int j=1; j<=3 && j<=i; j++)
         res[i] += res[i-j];
    }
    return res[n-1];
}
 int bleh(int s)
{
    return stepdp(s+1);
}
int steps(int n){
 if(n==1){
  return 1;
 }
 else if(n==2){
  return 3;
 }
 else if(n==3){
  return 4;
 }
 else{
  return steps(n-1)+steps(n-2)+steps(n-3);
 }
}
int main()
{
 int n,t;
 cin>>t;
 while(t--){        
 cin >> n;          
 int total=steps(n);
 int ans=bleh(n);
 cout<<ans<<endl;
 //getch();
}
 return 0;
}