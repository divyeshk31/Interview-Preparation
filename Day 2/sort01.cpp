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
void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void sort01(int a[], int s, int n){
	int p=s;
	f(i,s,n){
		if(a[i]==0){
			swap(&a[p],&a[i]);
			p++;
		}
	}
	return;
}
int main()
{
    int n;
    s(n);
    int a[n+2];
    f(i,1,n)
    s(a[i]);
    sort01(a,0,n-1);
    f(i,1,n)
    cout<<a[i]<<" ";
    getch();
return 0;
}
