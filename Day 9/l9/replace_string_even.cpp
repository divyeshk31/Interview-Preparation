#include <bits/stdc++.h>
#include <conio.h>
#include <string>
using namespace std;
vector<string> addwhite(vector<string> arr, string s){
	int l=s.size()/2;
	string n=" ";
	string p=s.substr(0,l-1)+n+s.substr(l,s.size());
	arr.push_back(p);
	return arr;
}
string replacestring(string s){
	int n=s.size();
	vector<string> arr;
	string temp="";
	for(int i=0;i<n;i++){
		while(s[i]!=' '){
			temp+=s[i];
			i++;
		}
		arr.push_back(temp);
	}
	for(int k=0;k<arr.size();k++){
		int m=arr[k].length();
		if(m%2==0 && m>=4){
					addwhite(arr,arr[k]);
		}
		else continue;
	}
	string ans="";
	int k=0;
	while(k<arr.size()){
		ans+=arr[k];
		k++;
	}
	return ans;
}
int main(){
	string s;
	getline(cin,s);
cout<<replacestring(s)<<endl;
	getch();
	return 0;
}