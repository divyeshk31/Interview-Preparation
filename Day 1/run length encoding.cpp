#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[10001];
    while(cin>>s)
    {
    int c=1;
    int l=strlen(s);
    for(int i=0;i<l;i++){
        if(s[i]==s[i+1])
                c++;

            else if(c>3){
                cout<<c<<"!"<<s[i];
                c=1;
            }
            else{
                while(c--)
                    cout<<s[i];
                c=1;
            }
    }
    cout<<endl;
    }
    return 0;
}
