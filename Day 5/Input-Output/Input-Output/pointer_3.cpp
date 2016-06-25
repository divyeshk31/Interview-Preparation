#include <iostream>
using namespace std;
int main() {
    char str[] = "CODING\nNINJAS";
    char *ptr1, *ptr2;

    ptr1 = &str[3];
    ptr2 = str+5;
    cout << (++*str - --*ptr1 + *ptr2)<<endl;
    cout << str;
}
