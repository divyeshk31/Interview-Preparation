#include<iostream>
using namespace std;
int main() {
    static int i = 5;
    if (--i) {
        main();
        cout << i << endl;
    }
    return 0;
}
