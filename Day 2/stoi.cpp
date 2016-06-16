#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
int stoi(string s){
	int ans;
	int n=s.length();
	if(n==1){
		return (s[0]-'0');
	}
	ans=stoi(s.substr(0,n-1))*10+(s[n-1]-'0');
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
    	cout<<stoi(s)<<endl;
    }
return 0;
}
