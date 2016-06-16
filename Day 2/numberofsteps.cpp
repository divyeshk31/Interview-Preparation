#include<iostream>
#include<conio.h>
using namespace std;

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
 cout<<"\nNo of ways to climb "<<n<<" steps = "<<total<<endl;
 getch();
}
 return 0;
}