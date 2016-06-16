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
void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void bubble(int a[],int n){
    bool swapped=false;
    f(i,0,n-1){
        f(j,0,n-i-1){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                swapped=true;
            }
        }
    if(swapped==false)
        break;
    }
}
int main()
{
    	int n;
    	cin>>n;
    	int a[n+2];
    	f(i,0,n)
    	cin>>a[i];
    	bubble(a,n);
    	f(i,0,n)
    	cout<<a[i]<<" ";
    	getch();
  return 0;
}