#include <bits/stdc++.h>
using namespace std;

int T, N;
string in, cmd;

deque<int> split(string& in){
    deque<int> result;

    int num = 0;

    for(char i : in){
        if(i == '[' || i == ']' ||i == ','){
            if(num == 0)
                continue;
            result.push_back(num);
            num = 0;
        }
        else
            num = num * 10 + (i - '0');
    }

    return result;
}

int main()
{
    cin >> T;

    for(int t = 0; t < T; t++){
        cin >> cmd >> N >> in;

        deque<int> dq = split(in);

        bool finish = false;
        bool front = true;

        for(char c : cmd){
            if(c == 'D'){
                if(!dq.empty()){
                    if(front)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
                else{
                    finish = true;
                    cout << "error\n";
                    break;
                }
                    
            }
            else if(c == 'R')
                front = !front;
        }

        if(!finish){
            cout << '[';
            while(!dq.empty()){
                if(front){
                    cout << dq.front();
                    dq.pop_front();
                }
                else{
                    cout << dq.back();
                    dq.pop_back();
                }
                if(!dq.empty())
                    cout << ',';
            }
            cout << ']' << '\n';
        }
    }

    return 0;
}