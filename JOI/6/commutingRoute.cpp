#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll ans = 0;
ll w,h;
int main(){
    cin >> w >> h;
    ll dp[w+1][h+1][];
    rep(i,w+1){
        rep(j,h+1){
            dp[i][j] = 0;
        }
    }
    rep(i,w){
        rep(j,h){

        }
    }
    cout << ans % 100000 << endl;
}