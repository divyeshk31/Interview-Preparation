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
void concat(string a, string b){
	int n=a.length();
	int m=b.length();
	string c="";
	int i,j,k=0;
	f(i,0,n){
		c[i]=a[i];
		k=i;
	}
	k++;
	f(j,0,m){
		c[k+j]=b[j];
	}
//	c[n+m]='\0';
	i=0;
	for(i=0;i<n+m;i++)
		cout<<c[i];

	cout<<"\n";
}
int main()
{
    int t;
    s(t);
    while(t--)
    {
  		string a,b;
  		cin>>a>>b;
  		concat(a,b);
  		//cout<<c<<endl;
    	getch();
    }

return 0;
}
