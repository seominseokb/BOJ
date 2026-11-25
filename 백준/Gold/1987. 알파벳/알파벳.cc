#include <bits/stdc++.h>
using namespace std;

int R, C;
string a[24];
int visited, result;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt){
    result = max(result, cnt);

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= R || nx < 0 || nx >= C)
            continue;
        if(visited & 1 << (a[ny][nx] - 'A'))
            continue;

        visited |= 1 << (a[ny][nx] - 'A');
        dfs(ny, nx, cnt + 1);
        visited ^= 1 << (a[ny][nx] - 'A');
    }

    return;
}

int main()
{
    cin >> R >> C;

    for(int r = 0; r < R; r++){
        cin >> a[r];
    }

    visited |= 1 << (a[0][0] - 'A');
    dfs(0, 0, 1);

    cout << result;

    return 0;
}