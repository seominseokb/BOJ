#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[54][54], visited[54][54];
int roomSize[2504];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int maxSize, maxExpandSize;

void dfs(int y, int x, int r){
    visited[y][x] = r;
    roomSize[r]++;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if(a[y][x] & (1 << i))  // 벽인 경우
            continue;
        if(!visited[ny][nx])
            dfs(ny, nx, r);
    }

    return;
}

int main()
{
    cin >> M >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }

    int room = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j])
                dfs(i, j, room++);
        }
    }

    for(int i = 0; i <= room; i++)
        maxSize = max(maxSize, roomSize[i]);

    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            for(int idx = 0; idx < 4; idx++){
                int ny = y + dy[idx];
                int nx = x + dx[idx];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M)
                    continue;
                if(visited[y][x] != visited[ny][nx])
                    maxExpandSize = max(maxExpandSize, roomSize[visited[y][x]] + roomSize[visited[ny][nx]]);
            }
        }
    }

    cout << room - 1<< '\n';
    cout << maxSize << '\n';
    cout << maxExpandSize << '\n';

    return 0;
}