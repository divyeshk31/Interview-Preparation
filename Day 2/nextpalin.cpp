#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

bool palindrome(int n){
 int arr[100],i=0;
 while(n>0){
  arr[i]=n%10;
  n/=10;
  i++;
 }
 int s=0,r=i-1;
 while(s<r){
  
  if(arr[s]!=arr[r]){
   return false;
  }
  s=s++;
  r=r--;
 }
 return true;
}
int main(){
 int n;
 bool f=true;
 cin>>n ;         
 n=n+1;
 while(f){
  
  if(palindrome(n)==true){
   f=false;
  }
  else{
   n++;
  }
 }
 cout<<"Next No which is palindrome is = "<<n;
getch();
 return 0;
}