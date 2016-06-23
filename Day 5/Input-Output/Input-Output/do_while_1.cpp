#include <iostream>
using namespace std;
int main()
{
    int c = 5, no = 1000;
    do {
        no /= c;
    } while(c--);

    cout << no;
    return 0;
}
