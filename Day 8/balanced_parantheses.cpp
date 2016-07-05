#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;
int isValid(string s) {
 stack<char> st;
        for (int i = 0; i < s.length(); i ++) {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
                st.push(s[i]); 
            } else {
                if (st.size() == 0) return false;
                char top = st.top();
                if (s[i] == ')') {
                    if (top != '(') return false;
                } else if (s[i] == ']') {
                    if (top != '[') return false;
                } else {
                    if (top != '{') return false;
                }
                st.pop();
            }
        }
        return st.size() == 0;
    }
int main(){
	string s;
	cin>>s;
	int ans=isValid(s);
	if(ans==1)
		cout<<"1\n";
	else 
		cout<<"0\n";
	//getch();
	return 0;
}