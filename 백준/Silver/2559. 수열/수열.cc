#include <bits/stdc++.h>
using namespace std;

int N, K, idx, sum, result = -987654321;
int a[100004];

int main()
{
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> a[i];
        sum += a[i];

        if(i >= K - 1){
            result = max(result, sum);
            sum -= a[idx];
            idx++;
        }
    }

    cout << result << '\n';

    return 0;
}