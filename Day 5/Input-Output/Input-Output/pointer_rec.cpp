#include <iostream>
using namespace std;
int fun(int n, int *fg)
{
    int t, f;
    if(n <= 1)
    {
        *fg = 1;
        return 1;
    }
    t = fun(n-1, fg);
    f = t + *fg;
    *fg = t;
    return f;
}
int main()
{
    int x = 15;
    cout << fun(5, &x) << endl;
    return 0;
}
