#include <bits/stdc++.h>
using namespace std;

int M, S, x;
string cmd;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M;

    for(int m = 0; m < M; m++){
        cin >> cmd;

        if(cmd == "add"){
            cin >> x;
            S |= (1 << (x - 1));
        }

        else if(cmd == "remove"){
            cin >> x;
            S &= ~(1 << (x - 1));
        }

        else if(cmd == "check"){
            cin >> x;
            if(S & (1 << (x - 1)))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(cmd == "toggle"){
            cin >> x;
            S ^= (1 << (x - 1));
        }
        else if(cmd == "all"){
            S = (1 << 20) - 1;
        }
        else{
            S = 0;
        }
    }

    return 0;
}