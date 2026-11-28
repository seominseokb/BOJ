#include <bits/stdc++.h>
using namespace std;

int N, K, result;
int words[54];
string word;

void solution(int idx, int k, int learned){
    if(idx >= 26 || k == 0){
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if((learned & words[i]) == words[i])
                cnt++;
        }
        result = max(result, cnt);
        return;
    }

    // idx번째 글자를 가르친다
    solution(idx + 1, k - 1, learned | (1 << idx));

    // idx번째 글자를 가르치지 않는다
    char w = idx + 'a';
    if(w != 'a' && w != 'c' && w != 'i' && w != 'n' && w != 't')
        solution(idx + 1, k, learned);
}

int main()
{
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> word;
        for(char w : word){
            words[i] |= (1 << (w - 'a'));
        }
    }

    solution(0, K, 0);

    cout << result;

    return 0;
}