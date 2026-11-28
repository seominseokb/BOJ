#include <bits/stdc++.h>
using namespace std;

int y, x;

int main()
{
    cin >> x >> y;

    if(x > 0 && y > 0)
        cout << 1;
    else if(x < 0 && y > 0)
        cout << 2;
    else if(x < 0 && y < 0)
        cout << 3;
    else if(x > 0 && y < 0)
        cout << 4;

    return 0;
}