#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// Abhishek
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define s(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define set0(a) memset(a, 0, sizeof(a))
#define setdp(a) memset(a, -1, sizeof(a))
#define setinf(a) memset(a, 127, sizeof(a))
#define INF 2000000000
#define MOD 1000000007

void getPalind(int s, int e, string str, set<string>& S) {  
    while(s >= 0 && e < str.size() && str[s] == str[e]) {
        s--;
        e++;
        S.insert(str.substr(s+1, e-s-1));
    }
}

void printSet(set<string> S) {
    set<string>::iterator it;
    for(it = S.begin(); it != S.end(); it++) cout << *it <<endl;
}

void printPalind(string str) {
    set<string> S;
    int n = str.size();
    for(int i = 0; i < n; i++) {
        getPalind(i, i, str, S);
        
        if(i+1 < n && str[i] == str[i+1])
            getPalind(i, i+1, str, S);
    }
    printSet(S);
}

int main()
{
    string s;
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        printPalind(s);
        cout << endl;
    }
}
