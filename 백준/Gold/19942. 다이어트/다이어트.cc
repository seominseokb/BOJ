#include <bits/stdc++.h>
using namespace std;

int N;
int mp, mf, ms, mv;
int p[20], f[20], s[20], v[20], cost[20];
int resCost = 987654321;
vector<int> resIndexes;

void calculate(const vector<int>& indexes){
    int sumP = 0, sumF = 0, sumS = 0, sumV = 0, totalCost = 0;

    for(int i : indexes){
        sumP += p[i];
        sumF += f[i];
        sumS += s[i];
        sumV += v[i];
        totalCost += cost[i];
    }
    
    if(sumP >= mp && sumF >= mf && sumS >= ms && sumV >= mv){
        if(resCost > totalCost || (totalCost == resCost && indexes < resIndexes)){
            resCost = totalCost;
            resIndexes = indexes;
        }
    }

    return;
}

int main()
{
    cin >> N;

    cin >> mp >> mf >> ms >> mv;

    for(int n = 0; n < N; n++)
        cin >> p[n] >> f[n] >> s[n] >> v[n] >> cost[n];

    for(int i = 1; i < (1 << N); i++){
        vector<int> indexes;

        for(int j = 0; j < N; j++){
            if(i & (1 << j))
                indexes.push_back(j);
        }

        calculate(indexes);
    }

    if(resCost == 987654321)
        resCost = -1;

    cout << resCost << '\n';
    for(int i : resIndexes)
        cout << i + 1 << ' ';

    return 0;
}