#include <bits/stdc++.h>
using namespace std;

string in;

string solution(const string& in){
    string result = "";
    
    for(char i : in){
        if('A' <= i && i <= 'Z')
            result += 'A' + ((i - 'A' + 13) % 26);
        else if('a' <= i && i <= 'z')
            result += 'a' + ((i - 'a' + 13) % 26);
        else
            result += i;
    }

    return result;
}

int main()
{
    getline(cin, in);
    
    cout << solution(in);

    return 0;
}