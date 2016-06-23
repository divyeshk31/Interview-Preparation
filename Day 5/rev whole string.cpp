#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

void reverse(char  *str ,  int start , int end )
{
   char ch;
   int j = end;
   for(int i =start;i<=(start+end)/2;i++)
   	{	ch = str[i];	
   		str[i] = str[j-i+start];
   		str[j-i+start] = ch;
   } 
}
void reversewithoutwords(char *str , int n)
{

	reverse(str,0,n-1);
	int j =0 , i;
	for( i = 0 ; i<n;i++)
	{ 
		if(str[i]!=' ' && str[i]!='\0') 
			continue;
		reverse(str,j,i-1);
		j = i+1;
	}
	reverse(str,j,i-1);
}
int main()
{
	char  str[50];
	cout<<"Enter the string : " ;
	gets(str);
	reversewithoutwords(str,strlen(str));
	cout<<" The Modified string is : " << str << endl;
	getch();
	return 0;
}