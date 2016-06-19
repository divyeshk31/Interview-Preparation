#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
void swap(char *a, char *b){
	char t;
	t=*a;
	*a=*b;
	*b=t;
}
void allper(string s, int l, int r){
	if(s.length()<1){
		cout<<s<<endl;
	}else if(l==r)
	{
		cout<<s<<endl;
	}
	else f(i,l,r){ 
		swap(s[l], s[i]);
		allper(s, l+1, r);
		swap(s[i], s[l]);
}
}



int main()
{
	string s;
	cin>>s;
	int n=s.length();
	allper(s,0,n-1);
	getch();
   return 0;
}