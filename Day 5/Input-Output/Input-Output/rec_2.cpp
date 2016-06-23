#include<iostream>
using namespace std;
int main() {
    static int i = 5;
    cout << i-- << endl;
    if (i) 
        main();
    return 0;
}
