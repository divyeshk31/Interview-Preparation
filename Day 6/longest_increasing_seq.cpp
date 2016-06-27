#include <bits/stdc++.h>
#include <map>
#include <conio.h>
#include <tr1/unordered_set>
using std::tr1::unordered_set;
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
void longestsubs(int a[], int n){
	unordered_set<int> h;
	f(i,0,n)
	h.insert(a[i]);
	int c=0;
	int s=0;
	f(i,0,n){
		if(h.find(a[i]-1)==h.end()){
			int j=a[i];
			while(h.find(j)!=h.end())
				j++;
		if(c<j-a[i]){
			c=j-a[i];
			s=a[i];
			}
		}
	}
	int max=s+c;
	while(s<max){
		cout<<s<<" ";
		s++;
	}
}
int main()
{
    int n;
    cin>>n;
    int a[n+2];
    f(i,0,n)
    cin>>a[i];
    longestsubs(a,n);
    getch();
return 0;
}
