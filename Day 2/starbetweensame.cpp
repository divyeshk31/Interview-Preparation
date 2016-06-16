#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
string putstar(string s){
	int n=s.length();
	if(n==1){
		return s;
	}
	string ans="";
	if(s[0]==s[1]){
		string s1;
		s1='*';
		ans=(s[0]+s1+putstar(s.substr(1,n)));
	}
	else
		ans=s[0]+putstar(s.substr(1,n));
return ans;
}

int main()
{
    int t;
    s(t);
    while(t--)
    {
    	string s;
    	cin>>s;
    	cout<<putstar(s)<<endl;
    }
return 0;
}
