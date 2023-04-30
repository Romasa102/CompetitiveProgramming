#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    rep(i,N-1){
        if(S[i] == S[i+1]){
            if(S[i] == 'j'){
                S[i] = 'J';
                S[i+1] = 'J';
            }
            if(S[i] == 'o'){
                S[i] = 'O';
                S[i+1] = 'O';
            }
            if(S[i] == 'i'){
                S[i] = 'I';
                S[i+1] = 'I';
            }
        }
    }
    cout << S << endl;
}