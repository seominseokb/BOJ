#include <bits/stdc++.h>
using namespace std;

string pikachu[3] = {"pi", "ka", "chu"};
string in, result = "YES";

int main()
{
    cin >> in;

    for(int i = 0; i < in.size();){
        bool find = false;
        for(string p : pikachu){
            if(in.substr(i, p.size()) == p){
                find = true;
                i += p.size();
                break;
            }
        }
        if(!find){
            result = "NO";
            break;
        }
    }
    
    cout << result;

    return 0;
}