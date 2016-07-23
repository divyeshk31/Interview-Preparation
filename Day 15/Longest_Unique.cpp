#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int longest(string s){
	int vis[256];
	for (int i = 0; i < 256; i++)
	{
		vis[i]=-1;
	}
	int cur=1;
	int maxl=1;
	int prev;
	vis[s[0]]=0;
	for(int i=1;i<s.size();i++){
		prev=vis[s[i]];
		if(prev==-1 || i-cur>prev)
			cur++;
		else{
			if(cur>maxl)
				maxl=cur;
			cur=i-prev;
		}
		vis[s[i]]=i;
	}
	if(cur>maxl)
		maxl=cur;
	return maxl;
}
int main(){
	string s;
	cin>>s;
	int ans=longest(s);
	cout<<ans<<endl;
	getch();
	return 0;
}