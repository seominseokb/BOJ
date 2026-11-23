#include <bits/stdc++.h>
using namespace std;

int N;
string pattern, file;

vector<string> split(const string& in, const string& delimeter){
    vector<string> result;

    auto start = 0;
    auto end = in.find(delimeter);

    while(end != string::npos){
        result.push_back(in.substr(start, end - start));
        start = end + delimeter.size();
        end = in.find(delimeter, start);
    }

    result.push_back(in.substr(start));
    return result;
}

int main()
{
    cin >> N >> pattern;
    vector<string> res = split(pattern, "*");

    for(int n = 0; n < N; n++){
        cin >> file;
        
        auto start = file.find(res[0]);
        auto end = file.rfind(res[1]);

        string result = "DA";

        if(res[0].size() + res[1].size() > file.size())
            result = "NE";
        if(start == string::npos || start != 0 || end == string::npos || end != file.size() - res[1].size())
            result = "NE";

        cout << result << '\n';
    }

    return 0;
}