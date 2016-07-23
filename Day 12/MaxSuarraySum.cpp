#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;
int MaxSubarray(int a[], int n){
	int maxhere=a[0];
	int maxsofar=a[0];
	for (int i = 1; i < n; ++i)
	{
		maxhere=max(a[i],maxhere+a[i]);
		maxsofar=max(maxsofar,maxhere);
	}
	return maxsofar;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int ans = MaxSubarray(a,n);
	cout<<ans<<endl;
	//getch();
	return 0;
}