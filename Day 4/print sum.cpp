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
void print_sum(int n, vector<int> &output, bool first = true) {
	if (n == 0) {
		for (int i = 0; i < output.size(); i++) {
			cout << output.at(i) << ",";
		}
		cout << endl;
		return;
	}
	int end;
	if (first)
		end = n - 1;
	else
		end = n;

	for (int i = 1; i <= end; i++) {
		output.push_back(i);
		print_sum(n - i, output, false);
		output.pop_back();
	}
}
int main()
{
   int n;
   cin>>n;
   std::vector<int> output;
   print_sum(n,output,true);
   getch();
return 0;
}