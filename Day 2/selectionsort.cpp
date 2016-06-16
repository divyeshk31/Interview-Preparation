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
void sel(int a[],int s, int n){
	if(s>=n-1){
		return;
	}
	int m=s;
	for(int j=s+1;j<n;j++){
		if(a[j]<a[m])
			m=j;
	}
	int t=a[s];
	a[s]=a[m];
	a[m]=t;
	sel(a,s+1,n);
}
int main()
{
    	int n;
    	cin>>n;
    	int a[n+2];
    	f(i,0,n)
    	cin>>a[i];
    	sel(a,0,n);
    	f(i,0,n)
    	cout<<a[i]<<" ";
    	getch();
  return 0;
}