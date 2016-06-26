#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
bool isvowel(char s){
	char t=s;
	if(t=='a'||t=='e'||t=='i'||t=='o'||t=='u'){
		return true;
	}
	return false;
}
bool ishigh(string s){
	int n=s.length();
	int c=0, flag=0;
	f(i,0,n){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
		{
			c++;
		}
	}
	//cout<<c<<endl;
	int con=n-c;
	//cout<<con<<endl;
	f(i,0,n)
	{
		if(isvowel(s[i])&&isvowel(s[i+1]))
		{
			flag=1;
			break;
		}
	}
	if(c>=con&&flag==1)
		{
			return true;
		}
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
    string s;
    cin>>s;
    if(ishigh(s)){
    	cout<<"Yes\n";
    }
    else cout<<"No\n";
    getch();
}
return 0;
}