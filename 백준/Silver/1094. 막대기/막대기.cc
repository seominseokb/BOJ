#include <bits/stdc++.h>
using namespace std;

int X, cnt;

int main()
{
    cin >> X;

    while(X >= 1){
        if(X % 2 == 1)
            cnt++;
        X /= 2;
    }
    
    cout << cnt;

    return 0;
}