#include <bits/stdc++.h>
using namespace std;

string in;
int a[26];


int main()
{
    cin >> in;

    for(char i : in){
        a[i - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        cout << a[i] << ' ';
    }

    return 0;
}