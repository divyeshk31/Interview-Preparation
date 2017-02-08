#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int fun(int n){
	if(n==4) return n;
	else return 2*fun(n+1);
}
int main(int argc, char const *argv[])
{
	cout<<fun(2)<<endl;
	getch();
	return 0;
}