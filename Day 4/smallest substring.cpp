#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
void smallestSubstring(string s, string t) {
	int i = 0;
	int j = 0;
	int freq[256] = {0};
	int numberCharRequired = 0;
	for (int k = 0; k < t.size(); k++) {
		freq[t[k]]++;
		if (freq[t[k]] == 1) {
			numberCharRequired++;
		}
	}
	int bestLength = s.size() + 1;
	int index = -1;
	while (i < s.size() && j < s.size()) {		
		if (numberCharRequired > 0) {
			freq[s[j]]--;
			if (freq[s[j]] == 0) {
				numberCharRequired--;
			}
			j++;
		} else if (numberCharRequired == 0) {
			if (j - i < bestLength) {
				bestLength = j - i;
				index = i;
			}
			freq[s[i]]++;
			if (freq[s[i]] == 1) {
				numberCharRequired++;
			}
			i++;
		}
	}
	if (index == -1) {
		cout << "Nothing found" << endl;
		return;
	}
	cout << s.substr(index, bestLength) << endl;
}
int main()
{
    string a,b;
getline(cin,a);
getline(cin,b);
    smallestSubstring(a,b);
    getch();
return 0;
}