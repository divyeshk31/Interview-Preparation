#include <iostream>
#include <conio.h>
using namespace std;

void find(int n, string str )
{	
	if(n==0)
		{
			if(str.size())
			cout<< str << endl;
			return;
		}
	if(n<0) 
		return;
	char ch = char(n%10 +'a' -1);
	find(n/10,ch+str);
	char ch1 = char(n%100  + 'a' - 1);
	if(ch1>='a' && ch1<='z' && ch1!=ch)
	find(n/100, ch1+str);
	
}

int main()
{
	int n;
	cin>>n;
	find(n,"");
	getch();
	return 0;
}