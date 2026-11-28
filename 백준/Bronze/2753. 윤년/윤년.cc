#include <bits/stdc++.h>
using namespace std;

int y;
bool result;

int main()
{
    cin >> y;

    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        result = true;
    
    cout << result;

    return 0;
}