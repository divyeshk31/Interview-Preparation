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
void gen(string str, string &res, int A, int open, int close){
if(open>A) return;
    if(open==A&&close==A){
        cout<<str<<endl;
    }
    else{
        gen(str+"(",res,A,open+1,close);
        if(open>close){
            gen(str+")",res,A,open,close+1);
        }
    }
}
string  printstring(int n){
	string ans;
		if(n==0){
			return ans;
		}
		gen("",ans, n, 0, 0);
		return ans;
}
int main()
{
    int n;
    cin>>n;
    string s1=printstring(n);
   cout<<s1<<endl;
   getch();
return 0;
}