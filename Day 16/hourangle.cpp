#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int calculate(double h, double m){
	if(h<0 || m<0 || h>12 || m>60)
		cout<<"bleh\n";
	if(h==12) h=0;
	if(m==60) m=0;
	int hangle=0.5*(h*60 +m);
	int mangle=6*m;
	int angle=abs(hangle-mangle);
	angle=min(360-angle, angle);
	return angle;
}
int main(int argc, char const *argv[])
{
	double h, m;
	cin>>h>>m;
	int ans=calculate(h,m);
	cout<<ans<<endl;
	getch();
	return 0;
}