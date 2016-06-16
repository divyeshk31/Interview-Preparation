#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

int checkstring(char *t){
 if(*t==NULL){
  return 1;
 }
 char *c=t;
 if(*t=='a'){
  if(*(c+1)=='a'){
   
  return checkstring(t+1);
  }
  else if(*(c+1)=='b'){
   return checkstring(t+1);
  }
  if(*(c+1)==NULL){
   
   return 1;
  }
  else{
   return 0;
  }
 }
 else if(*t=='b'){
  if(*(c+1)=='b'&&*(c+2)=='a'){
   return checkstring(t+2);
  }
  else if(*(c+1)=='b'&&*(c+2)==NULL){
   return 1;
  }
  else{
   return 0;
}}}

int main(){
 
 char s[100];
 cin>>s;
 char *t;
 t=s;
 if(*t=='a'){
  t=t++;
  if(checkstring(t)){
   cout<<"Valid Substring\n";
  }
  else{
   cout<<"Not a Valid Substring\n";
  }
 }
 else{
  cout<<"Not a valid substring";
 }
 getch();
 return 0;
}