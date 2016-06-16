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
void rearrange(int a[], int n){
	int z=0,e=0;
	f(i,0,n){
		if(a[i]==0)
			z++;
		 if(a[i]==1)
			e++;
		}
		int c=0;
		f(i,0,n){
			if(a[i]!=1)
				a[c++]=a[i];
		}
		int r=n-1;
		while(e>0){
			a[r]=1;
			r--;
			e--;
		}
		int c1=n-1-e;
		for(int i=c1;i>=0;i--){
			if(a[i]!=0)
				a[c1--]=a[i];
		}
		int l=0;
		while(z>0){
			a[l]=0;
			l++;
			z--;
		}
	return;
}
int main()
{
    int n;
    cin>>n;
    int a[n+2];
    f(i,0,n)
    cin>>a[i];
    rearrange(a,n);
      f(i,0,n)
    cout<<a[i]<<" ";
  getch();
return 0;
}