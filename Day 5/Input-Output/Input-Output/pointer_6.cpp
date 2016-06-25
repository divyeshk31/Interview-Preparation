#include <iostream>
using namespace std; 
int main() {
    char s[] = "CodingNinjas";
    char *ptr = s;
    while(*ptr!='\0') 
        ++*ptr++;
    cout << s << " --" << ptr << endl;
    return 0;
}
