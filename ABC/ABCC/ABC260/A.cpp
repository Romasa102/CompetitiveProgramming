#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    if(S[0] == S[1] == S[2]){
        cout << -1 << endl;
        return 0;
    }
    if(S[0] == S[1]){
        cout << S[2] << endl;
        return 0;
    }
    if(S[0] == S[2]){
        cout << S[1] << endl;
        return 0;
    }
    if(S[2] == S[1]){
        cout << S[0] << endl;
        return 0;
    }
}