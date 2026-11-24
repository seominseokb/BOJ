#include <bits/stdc++.h>
using namespace std;

int N, result;
int a[200004];
string in;
stack<int> stk;

int main()
{
    cin >> N >> in;

    
    for(int i = 0; i < N; i++){
        if(in[i] == '('){
            stk.push(i);
        }
        else{
            if(!stk.empty()){
                a[i] = 1;
                a[stk.top()] = 1;
                stk.pop();
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < N; i++){
        if(a[i] != 0)
            sum += a[i];
        else{
            result = max(result, sum);
            sum = 0;
        }
    }

    result = max(result, sum);
    cout << result;

    return 0;
}