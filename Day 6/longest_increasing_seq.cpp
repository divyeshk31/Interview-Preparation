#include <bits/stdc++.h>
#include <map>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
int longestsubs(int a[], int n){
	map<int,int> mymap;
	f(i,0,n)
	mymap[a[i]]++;
	int c=0;
	int s=0;
	f(i,0,n){
		if(mymap.find(a[i]-1)==mymap.end()){
			int j=a[i];
			while(mymap.find(j)!=mymap.end())
				j++;
		c=max(c,j-a[i]);
			}
		}
	return c;
}
int main()
{
    int n;
    cin>>n;
    int a[n+2];
    f(i,0,n)
    cin>>a[i];
    cout<<longestsubs(a,n)<<endl;
    //getch();
return 0;
}
