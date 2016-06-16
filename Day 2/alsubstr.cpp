#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
string prints(string s){
	if(s.length()==1){
		return s;
	}
	return prints(s.substr(0,s.length()-1));
}

int main(){
	string s;
	cin>>s;
	prints(s);
	getch();
	return 0;
}