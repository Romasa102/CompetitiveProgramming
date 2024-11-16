#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S[8];
    rep(i,8){
        cin >> S[i];
    }
    rep(i,8) {
        rep(j, 8) {
            if (S[i][j] == '#') {
                rep(k, 8) {
                    rep(l, 8) {
                        if (S[k][l] == '.') {
                            S[i][j] = 'X';
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(i,8){
        rep(j,8){
            if(S[i][j] == '.'){
                ans++;
            }
        }
    }
    cout << ans << endl;
}