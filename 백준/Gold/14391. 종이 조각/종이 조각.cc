#include <bits/stdc++.h>
using namespace std;

int N, M, result;
int a[5][5];
string in;

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> in;
        for(int j = 0; j < M; j++){
            a[i][j] = in[j] - '0';
        }
    }

    for(int i = 0; i < (1 << (N * M)); i++){
        int orient = 0;
        for(int j = 0; j < N * M; j++){  // 0이면 가로, 1이면 세로
            if(i & (1 << j))
                orient |= 1 << j;
        }

        int sum = 0;

        for(int y = 0; y < N; y++){
            int s = 0;
            for(int x = 0; x < M; x++){
                int n = y * M + x;
                if(!(orient & (1 << n))){  // 0인 경우
                    s = s * 10 + a[y][x];
                }
                else{
                    sum += s;
                    s = 0;
                }
            }
            sum += s;
        }

        for(int x = 0; x < M; x++){
            int s = 0;
            for(int y = 0; y < N; y++){
                int n = y * M + x;
                if(orient & (1 << n)){
                    s = s * 10 + a[y][x];
                }
                else{
                    sum += s;
                    s = 0;
                }
            }
            sum += s;
        }

        result = max(result, sum);
    }

    cout << result;

    return 0;
}