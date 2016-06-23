#include <iostream>
using namespace std;

int & squareRef(int &);
int * squarePtr(int *);

int main() {
    int number1 = 8;
    cout <<  "number1: " << &number1 << endl;  
    int & result = squareRef(number1);
    cout <<  "&result: " << &result << endl;  
    cout << result << endl;   
    cout << number1 << endl;  

    int number2 = 9;
    cout <<  "&number2: " << &number2 << endl;  
    int * pResult = squarePtr(&number2);
    cout <<  "pResult: " << pResult << endl; 
    cout << *pResult << endl;   
    cout << number2 << endl;   
}

int & squareRef(int & rNumber) {
    cout <<  "In squareRef(): " << &rNumber << endl;
    rNumber *= rNumber;
    return rNumber;
}

int * squarePtr(int * pNumber) {
    cout <<  "In squarePtr(): " << pNumber << endl;
    *pNumber *= *pNumber;
    return pNumber;
}
//You should not pass Function's local variable as return value by reference
