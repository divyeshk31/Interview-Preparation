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
/* int partition(int a[], int n){
	int sum=0,rightsum=0,leftsum=0,maxdiff=INT_MIN,diff;
	f(i,0,n)
	sum+=a[i];
	int j=n-1,index;
	while(j>=0){
		rightsum+=a[j];
		leftsum=sum-rightsum;
		diff=abs(rightsum-leftsum);
		if(diff>maxdiff)
			{
				maxdiff=diff;
				index=j-1;
			}
		j--;
	}
	return index;
} */
int partition(int a[], int n){
	int sum=0,sum1=0,maxdiff=INT_MIN,diff;
	int ans;
	f(i,0,n)
	sum+=a[i];
	int j=n-1,index;
	f(i,0,n){
		sum1+=a[i];
		diff=abs((sum-sum1)-sum1);
		if(diff>maxdiff)
			{
				maxdiff=diff;
				ans=i;
			}
	}
	return ans;
}
int main()
{
    int n,ans;
    s(n);
    int a[n+2];
    f(i,0,n)
    s(a[i]);
    ans=partition(a,n);
    cout<<ans<<endl;
    getch();
    return 0;
}
