#include <bits/stdc++.h>
using namespace std;

int T;
int a[26];
string name;

int main()
{
    cin >> T;

    for(int t = 0; t < T; t++){
        cin >> name;
        a[name[0] - 'a']++;
    }

    bool isWithdraw = true;

    for(int i = 0; i < 26; i++){
        if(a[i] >= 5){
            cout << char('a' + i);
            isWithdraw = false;
        }
    }

    if(isWithdraw)
        cout << "PREDAJA";

    return 0;
}