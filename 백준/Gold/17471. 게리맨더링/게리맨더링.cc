#include <bits/stdc++.h>
using namespace std;

int N, M, node;
int population[14];
vector<int> graph[14];
int visited;
int result = 987654321;

int dfs(int start, int cnt, const vector<int>& section){
    visited |= (1 << start);
    cnt += population[start];

    for(int next : graph[start]){
        if(visited & (1 << next))
            continue;
        for(int s : section){
            if(s == next)
                cnt = dfs(next, cnt, section);
        }
    }

    return cnt;
}

int main()
{
    cin >> N;
    
    for(int n = 0; n < N; n++)
        cin >> population[n];

    for(int n = 0; n < N; n++){
        cin >> M;

        for(int m = 0; m < M; m++){
            cin >> node;
            graph[n].push_back(node - 1);
        }
    }

    for(int i = 1; i < (1 << N) - 1; i++){
        visited = 0;
        vector<int> a, b;
        for(int j = 0; j < N; j++){
            if(i & (1 << j))
                a.push_back(j);
            else
                b.push_back(j);
        }

        int populationA = dfs(a[0], 0, a);
        int populationB = dfs(b[0], 0, b);

        if(visited == (1 << N) - 1)
            result = min(result, abs(populationA - populationB));
    }

    if(result == 987654321)
        result = -1;

    cout << result << '\n';

    return 0;
}