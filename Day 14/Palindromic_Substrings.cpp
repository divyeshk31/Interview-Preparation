#include <iostream>
#include <conio.h>
#include <string>
#include <set>
using namespace std;

void palindromeSubStrs(string str)
{
    set<string> s;

    for(int i=0;i<str.size();i++)
    {
        s.insert(str.substr(i,1));
        int j,k;

        j=i-1,k=i;
        while(j>=0&&k<str.size()&&str[j]==str[k])
        {
            s.insert(str.substr(j,k-j+1));
            j--;
            k++;
        }

        j=i-1,k=i+1;
        while(j>=0&&k<str.size()&&str[j]==str[k])
        {
            s.insert(str.substr(j,k-j+1));
            j--;
            k++;
        }
    }
    set<string>::iterator it;
    int c=0;
    for(it=s.begin();it!=s.end();it++)
 {       c++;
}
cout<<c<<endl;
}
int main()
{ 
    string s;
    cin>>s;
    palindromeSubStrs(s);
    getch();
    return 0;
}