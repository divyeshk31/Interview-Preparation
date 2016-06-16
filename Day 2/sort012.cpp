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
void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void sort012(int A[],int n) {
    int lo=0,mid=0,hi=n-1;
    while(mid<=hi)
    {
        switch(A[mid])
        {
            case 0: swap(&A[lo++],&A[mid++]);
                    break;
            case 1: mid++;
                    break;
            case 2: swap(&A[mid],&A[hi--]);
                    break;
        }
    }
    
}
int main()
{
    int n;
    s(n);
    int a[n+2];
    f(i,0,n)
    s(a[i]);
    sort012(a,n);
    f(i,0,n)
    cout<<a[i]<<" ";
    getch();
return 0;
}