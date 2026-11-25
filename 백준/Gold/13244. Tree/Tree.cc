#include <bits/stdc++.h>
using namespace std;

int T, N, M;  // 테스트 케이스, 노드 수, 엣지 수
int s, e;
string result;
vector<int> graph[1004];
int visited[1004];

void dfs(int start){
    visited[start] = 1;

    for(int next : graph[start]){
        if(!visited[next])
            dfs(next);
    }

    return;
}

bool checkVisit(){
    for(int i = 1; i <= N; i++){
        if(!visited[i])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for(int t = 0; t < T; t++){
        cin >> N >> M;
        
        for(int i = 0; i < 1004; i++){
            graph[i].clear();
        }

        memset(visited, 0, sizeof(visited));
        
        for(int m = 0; m < M; m++){
            cin >> s >> e;
            graph[s].push_back(e);
            graph[e].push_back(s);
        }

        if(M != N - 1)
            result = "graph";
        else{
            dfs(1);
            result = checkVisit() ? "tree" : "graph";
        }
        
        cout << result << '\n';
    }

    return 0;
}