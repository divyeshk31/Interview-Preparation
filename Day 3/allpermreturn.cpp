#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void swap(char &s, char &t)
{
	char temp;
	temp = s;
	s = t;
	t = temp;
}
vector<string> permute(vector<string> &a,string x, int l, int r)
{
int i;
if (l == r){
	a.push_back(x);
	return a;
}
else
{
	for (i = l; i <= r; i++)
	{
		swap(x[l], x[i]);
		permute(a,x, l+1, r);
		swap(x[i], x[l]);
	}
}
return a;
}
int main()
{
	vector<string> s;
	string x;
	getline(cin,x);
	int n = x.length();
	vector<string> ans= permute(s,x, 0, n-1);
	for(int i=0;i<ans.size();i++){
	    cout<<ans[i]<<endl;
	}
	getch();
	return 0;
}