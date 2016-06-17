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
int findk(int a[],int n){
	while(n>=0){
		if(a[n]<a[n-1])
			return n;
	n--;
	}
}
int main(){
	int n;
	cin>>n;
	int a[n+2];
	f(i,0,n)
	cin>>a[i];
	int ans=findk(a,n-1);
	cout<<ans<<endl;
	getch();
	return 0;
}