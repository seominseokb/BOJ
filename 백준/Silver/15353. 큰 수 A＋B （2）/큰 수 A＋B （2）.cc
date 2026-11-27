#include <bits/stdc++.h>
using namespace std;

string A, B;

string addStr(const string& a, const string& b){
    string result = "";
    
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry){
        int n1 = 0, n2 = 0;

        if(i >= 0){
            n1 = a[i] - '0';
            i--;
        }

        if(j >= 0){
            n2 = b[j] - '0';
            j--;
        }
        
        carry = n1 + n2 + carry;
        result += (carry % 10) + '0';
        carry /= 10;
    }
    
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    cin >> A >> B;

    cout << addStr(A, B);

    return 0;
}