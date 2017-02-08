#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> c(N);
    for(int c_i = 0;c_i < N;c_i++){
       cin >> c[c_i];
    }
    int noOfJumps = 0, i = 0;
		while(true) {
			if(i + 2 < N && c[i + 2] == 0) {
				i += 2;
			} else if(i + 1 < N) {
				i++;
			} else {
				break;
			}
			noOfJumps++;
		}
    cout<<noOfJumps<<endl;		
    return 0;
}
