#include <bits/stdc++.h>
using namespace std;
#include <conio.h>
int majority(int a[], int n){
	int ans=a[0], count=1;
	for(int i=1;i<n;i++){
		if(ans==a[i])
		{
			count++;
		}
		else if(count==0){
			ans=a[i];
			count++;
		}
		else{
			count--;
		}
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	int a[n+2];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int major=majority(a,n);
	cout<<major<<endl;
	getch();
	return 0; 
}