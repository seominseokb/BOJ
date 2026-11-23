#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int s, e, res;
int a[104];

int main()
{
    cin >> A >> B >> C;

    for(int t = 0; t < 3; t++){
        cin >> s >> e;
        for(int i = s; i < e; i++)
            a[i]++;
    }
    
    for(int i = 1; i <= 100; i++){
        if(a[i] == 1)
            res += A;
        else if(a[i] == 2)
            res += 2 * B;
        else if(a[i] == 3)
            res += 3 * C;
    }

    cout << res;

    return 0;
}