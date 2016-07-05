#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;

string SwapWords(char input[], char swap1[], char swap2[]){
	vector<string> s;
	string temp,ans="";
	for(int i=0;input[i]!='\0';i++){ 
		if(input[i]==' '){
			s.push_back(temp);
			temp.erase();
		}
		else{
			temp+=input[i];
		}
	}
	s.push_back(temp);
	
	int pos1=find(s.begin(), s.end(), swap1)-s.begin();
	int pos2=find(s.begin(), s.end(), swap2)-s.begin();
	s[pos1].swap(s[pos2]);
	for(int i=0;i<s.size();i++){
		ans+=s[i]+" ";
	}
	return ans;
}

int main() {
	char input[1000];
	cin.getline(input,1000,'\n');
	char swap1[100],swap2[100];
	cin.getline(swap1,100,'\n');
	cin.getline(swap2,100,'\n');
	string ans=SwapWords(input, swap1, swap2);
	cout<<ans<<endl;
//	getch();
	return 0;
}