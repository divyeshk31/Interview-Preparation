#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int n;
	int x;
	cin>>n>>x;
	int a[n];
	int score=0,ts=0,i=0,turn=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if(a[i]==-1)
		{
			cout<<score<<" "<<ts<<endl;
			continue;
			score=0;
		}
		else if(a[i]%2!=0)
		{
			score=0;
		}
		if(turn%x==0)
		{
			score=0;
		}
		if(a[i]!=-1&&a[i]%2==0)
		{
			score=score+a[i];
			
		}
		if(a[i]!=-1)
		{
			ts=ts+a[i];
		}
		
		i++;
		turn++;
	}
	cout<<ts<<endl;
	getch();
	return 0;
}