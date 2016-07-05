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
int platform(int a[], int b[], int n){
	sort(a,a+n); sort(b,b+n);
	int i=1,j=0;
	int need=1, ans=1;
	while(i<n && j<n){
		if(a[i]<b[j]){
			need++;
			i++;
		if(need>ans)
			ans=need;
	}
	else{
		need--;
		j++;
	}
}
return ans;
}
int main()
{
    int n;
    s(n);
    int a[n+2],b[n+2];
    f(i,0,n)
    s(a[i]);
    f(i,0,n)
    s(b[i]);
    int ans=platform(a,b,n);
    p(ans);
    getch();
return 0;
}
