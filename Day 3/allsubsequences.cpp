#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
void recomb(string pre, string s){
	if(s.length()==0){
		cout<<pre+""<<endl;
	}
	else
{		recomb(pre+s[0], s.substr(1));
	recomb(pre,s.substr(1));
}
}
void allsubs(string s){
	if(s.length()!=0){
		recomb("", s);
	}
}
int main()
{
	string s;
	cin>>s;
	allsubs(s);
	getch();
   return 0;
}