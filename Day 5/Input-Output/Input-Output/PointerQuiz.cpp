#include<iostream>
using namespace std;
int main() {
    short nValue = 7; 
    short nOtherValue = 3; 
    short *pnPtr = &nValue;

    cout << &nValue << endl;
    cout << nValue << endl;
    cout << pnPtr << endl;
    cout << *pnPtr << endl;
    cout << endl;
    *pnPtr = 9;
    cout << &nValue << endl;
    cout << nValue << endl;
    cout << pnPtr << endl;
    cout << *pnPtr << endl;
    cout << endl;
    pnPtr = &nOtherValue;
    cout << &nOtherValue << endl;
    cout << nOtherValue << endl;
    cout << pnPtr << endl;
    cout << *pnPtr << endl;
    cout << endl;

    cout << sizeof(pnPtr) << endl;
    cout << sizeof(*pnPtr) << endl;
    return 0;
}
