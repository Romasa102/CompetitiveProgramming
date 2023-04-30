#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    bool skipN = false;
    ll ans = S.size();
    rep(i,S.size()){
        if(skipN == true){
            skipN = false;
            continue;
        }
        if(i != S.size()-1){
            if(S[i] == 0 && S[i+1] == 0){
                skipN = true;
                ans--;
            }
        }
    }
}