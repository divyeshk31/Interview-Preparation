#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)                printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)               printf("%lld\n",n)
#define ll long long int
string remdup(string s){
	int n=s.length();
	if(n==0||n<=1)
		return s;
	else if(s[0]==s[1])
		return remdup(s.substr(1,n));
	else return s[0]+remdup(s.substr(1,n));
}
int main()
{
	string s;
	cin>>s;
	cout<<remdup(s)<<endl;
	getch();
	return 0;
}