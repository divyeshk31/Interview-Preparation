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
string reverse(string s){
	string s1;
	string k="";
	int n=s.length();
	f(i,0,n){
		while(s[i]=""){
			s1[i]=s[i];
		}
	}
	k=" "+s1;
	return k;
}
int main()
{
    string s;
    cin>>s;
    cout<<reverse(s)<<endl;
    getch();
return 0;
}
