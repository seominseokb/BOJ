#include <bits/stdc++.h>
using namespace std;

int N, M, result;
string a[5];
int visited[5][5];
int dy[2] = {0, 1};
int dx[2] = {1, 0};

void dfs(int idx, int sum){
    if(idx == N * M){
        result = max(result, sum);
        return;
    }

    int y = idx / M, x = idx % M;

    if(visited[y][x]){
        dfs(idx + 1, sum);
        return;
    }

    for(int i = 0; i < 2; i++){
        int K = (i == 0) ? M : N;
        string num = "";
        int cnt = 0;
        for(int j = 0; j < K; j++){
            int ny = y + dy[i] * j;
            int nx = x + dx[i] * j;
            if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]){
                break;
            }

            visited[ny][nx] = 1;
            num += a[ny][nx];
            cnt++;
            dfs(idx + 1, sum + stoi(num));
        }
        for(int j = 0; j < cnt; j++){
            int ny = y + dy[i] * j;
            int nx = x + dx[i] * j;
            visited[ny][nx] = 0;
        }
    }
}

int main()
{
    cin >> N >> M;

    for(int i = 0 ; i < N; i++){
        cin >> a[i];
    }

    dfs(0, 0);

    cout << result << '\n';

    return 0;
}