#include<iostream>
using namespace std;
int main() {
    int arr[] = {65,2,3};
    cout << arr << endl;
    char * ptr = (char *) arr;
    char str[] = "ankush";
    char *ptr1 = str;

    cout << ptr1 << endl;
    cout << str << endl;

    cout << ptr << endl;
    return 0;
}
