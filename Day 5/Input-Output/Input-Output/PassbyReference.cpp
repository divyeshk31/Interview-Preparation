#include<iostream>
using namespace std;
void myfunction(int x) {
    x = 25;
}
void myfunction1(int & x) {
    x = 21;
}
void myfunction2(int *x) {
    int y = 100;
    x = &y;
    *x = 30;
}
int main() {
    int x = 20; int *ptr = &x;
    myfunction(x);cout << x << endl;
    myfunction1(x); cout << x << endl;
    myfunction2(ptr); cout << x << endl;
}
// 20 21 21