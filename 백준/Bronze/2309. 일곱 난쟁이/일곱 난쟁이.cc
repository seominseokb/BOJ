#include <bits/stdc++.h>
using namespace std;

int a[9];

void solution(int start, vector<int> res){
    if(res.size() == 7){
        int sum = 0;
        for(int r : res)
            sum += r;
        if(sum == 100){
            sort(res.begin(), res.end());
            for(int r : res)
                cout << r << '\n';
            exit(0);
        }
        return;
    }

    for(int i = start + 1; i < 9; i++){
        res.push_back(a[i]);
        solution(i, res);
        res.pop_back();
    }
}

int main()
{
    for(int i = 0; i < 9; i++)
        cin >> a[i];

    vector<int> result;
    
    solution(-1, result);

    return 0;
}