#include <bits/stdc++.h>
using namespace std;

string in;

bool isPalin(const string& in){
    bool result = true;

    int start = 0;
    int end = in.size() - 1;

    while(start < end){
        if(in[start] != in[end]){
            result = false;
            break;
        }
        start++;
        end--;
    }

    return result;
}

int main()
{
    cin >> in;

    cout << isPalin(in);

    return 0;
}