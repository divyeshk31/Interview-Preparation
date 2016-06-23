#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;
bool no(int k,int i, const vector<int> A){
    for(int j=k;j<i;j++){
        if(A[j]==A[i]){
            return true;
        }
    }
    return false;
}
vector<vector<int> > perm(vector<int> A, int k, int n, vector<vector<int> > &res)
{
    if(k==n) {
        res.push_back(A);
    }
    else { for(int i=k;i<=n;i++)
    {
        if(no(k,i,A)){ continue;}
        int temp=A[k];
        A[k]=A[i];
        A[i]=temp;
        perm(A,k+1,n,res);
    }
}
return res;
}
int main()
{
	vector<int> a;
	vector<vector<int> > res;
	int n,x,k;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		a.push_back(x);
	}
	vector<vector<int> > ans = perm(a,0,n-1,res);
	for (  int k = 0; k < ans.size(); k++ )
{
   for ( int j = 0; j < ans[k].size(); j++ )
   {
      cout << ans[k][j] << ' ';
   }
   cout << endl;
}
	getch();
	return 0;
}