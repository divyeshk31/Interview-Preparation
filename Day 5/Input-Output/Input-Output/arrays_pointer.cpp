#include<iostream>
using namespace std;
void function1(int *arr) {
    cout << sizeof(arr) << endl;
    cout << arr << endl;
    cout << &arr << endl;
}
void function2(int arr[]) {
//    cout << sizeof(arr) << endl;
    cout << arr << endl;
    cout << &arr << endl;
}
void function3(int (&arr)[]) { // int & arr[10];
    cout << sizeof(arr) << endl;
    cout << arr << endl;
    cout << &arr << endl;
}
int main() {
    int arr[10];
    cout << sizeof(arr) << endl;
    cout << arr << endl;
    cout << &arr << endl;
    function1(arr);function2(arr);function3(arr);
    return 0;
}
