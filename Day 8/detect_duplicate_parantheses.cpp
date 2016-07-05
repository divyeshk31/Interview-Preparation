#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;
int braces(string str)
    {
        int N = str.size();
        stack<char> Stk;

        for(int i = 0; i < N; ++i) {
            if(str[i] == ')') {
                int cnt = 0;
                while(Stk.top() != '(') {
                        Stk.pop();
                        cnt++;
                }
                Stk.pop();
                if(cnt < 2)
                        return 1;
            } else {
                Stk.push(str[i]);
            }
        }
        
        bool is = true;
        while(Stk.size()) {
            if(Stk.top() == '(' || Stk.top() == ')') {
                    is = false;
                    break;
            }
            Stk.pop();
        }

        if(!is)
                return 1;
        return 0;
    }
int main(){
	string s;
	cin>>s;
	int ans=braces(s);
	if(ans==1)
		cout<<"1\n";
	else 
		cout<<"0\n";
	//getch();
	return 0;
}