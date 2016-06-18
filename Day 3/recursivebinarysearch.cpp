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
int bin(int a[], int l, int r,int x){
	int c=0;
	if(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]==x){
			return mid;
		}
		if (a[mid] > x){
			return bin(a,l,mid-1,x);
		}
		else return bin(a,mid+1,r,x);
	}
	return -1;
}
int main()
{
    int n,x;
    cin>>n;
    int a[n+2];
    f(i,0,n)
    cin>>a[i];
    cin>>x;
    int c=bin(a,0,n-1,x);
    if(c==-1)
    	cout<<"Not Found\n";
    else
     cout<<"Found at : "<<c<<endl;
    getch();
    return 0;
}