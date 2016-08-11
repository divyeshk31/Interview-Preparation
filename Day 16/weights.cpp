#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	float a[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=0;
	int i=0,j=n-1;
	while(i<j){
		if(a[i]+a[j]<=3.00){
			ans++;
			i++;
			j--;
		}
		if(a[i]+a[j]>3.00){
			j--;
			ans++;
		}
		
	}
	if(i==j)
	ans++;
	cout<<ans<<endl;
	getch();
}