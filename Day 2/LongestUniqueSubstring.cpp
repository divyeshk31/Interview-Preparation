/* To find the longest substring of given string s which contains at most 2 unique characters */

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
string LongestTwoUniqueCharSubstring2(string s)
{
	string temp;
	char a , b;
	int j =0;
	int startindex = 0 , endindex = 0 , tempstartindex = 0 , tempendindex = 0 ,
	int max_size = 0 , temp_size = 0;
	int switchindex = 0;

		a = s[0];
		int x = 0;
		tempstartindex = 0;
		while(s[x]==a) x++;
		switchindex = x;
		int i = x;
	while(i<s.size())
	{ 
		tempstartindex = switchindex;
		switchindex = i;
		b = s[i];
		while(s[i]==b || s[i]==a) 
			{ 
				if(s[i]!=s[i-1]) switchindex = i;
				i++;
			}
		tempendindex = i-1;
		a = s[switchindex];
		temp_size = tempendindex - tempstartindex +1;
		if(temp_size>max_size)
		{
			max_size = temp_size;
			startindex = tempstartindex;
			endindex = tempendindex;
		}

	}

	for(int i = startindex;i<=endindex;i++)
		temp += s[i];


	return temp;
}



int main()
{

	string str;
	cout<<"Enter the string : " ;
	cin>> str;
	string temp = LongestTwoUniqueCharSubstring2(str);
	cout<<"The longest two unique character substring is : " << temp<<endl;
	getch();
	return 0;
}