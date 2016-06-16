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
void reverse(char *s){
	if(*s){
		reverse(s+1);
		cout<<*s;
	}
}
int main()
{
	char s[200];
	cin>>s;
	reverse(s);
	getch();
	return 0;
}