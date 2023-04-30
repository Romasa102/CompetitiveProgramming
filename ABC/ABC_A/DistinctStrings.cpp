#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans = 3;
    if(S[0] == S[1] && S[1] == S[2]){
        ans = 1;
    }
    if(S[0] != S[1] && S[0] != S[2] && S[1] != S[2]){
        ans = 6;
    }
    cout << ans << endl;
}