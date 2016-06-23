#include<iostream>
using namespace std;
void fun(int *p) {
    p = new int;
}
int main() {
    int * p;
    fun(p);
    *p = 6;
    cout << *p << endl;
    return 0;
}
