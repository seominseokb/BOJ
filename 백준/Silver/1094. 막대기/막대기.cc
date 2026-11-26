#include <bits/stdc++.h>
using namespace std;

int X, result;

int main()
{
    cin >> X;
    
    for(int i = 0; i < 7; i++){
        if(X & (1 << i))
            result++;
    }

    cout << result;

    return 0;
}