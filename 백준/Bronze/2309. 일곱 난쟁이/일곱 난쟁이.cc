#include <bits/stdc++.h>
using namespace std;

int a[9];

int main()
{
    for(int i = 0; i < 9; i++)
        cin >> a[i];

    sort(a, a + 9);
    
    for(int i = 0; i < (1 << 9); i++){
        vector<int> res;
        int sum = 0;

        for(int j = 0; j < 9; j++){
            if(i & (1 << j))
                res.push_back(a[j]);
        }

        if(res.size() == 7){
            for(int r : res)
                sum += r;
            if(sum == 100){
                for(int r : res)
                    cout << r << '\n';
                return 0;
            }
        }
    }

    return 0;
}