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
int findk(int a[],int l, int r){
	if(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]>a[mid+1]&&a[mid]<a[mid-1]){
			return mid+1;
		}
		if(a[mid]>a[r])
			findk(a,mid,r);
		else findk(a,l,mid-1);
	}
}
int main(){
	int n;
	cin>>n;
	int a[n+2];
	f(i,0,n)
	cin>>a[i];
	int ans=findk(a,0,n-1);
	cout<<ans+1<<endl;
	getch();
	return 0;
}