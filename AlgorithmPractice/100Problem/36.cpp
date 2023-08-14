#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,W;
    cin >> N >> W;
    ll v[N+1];
    ll w[N+1];
    rep(i,N){
        cin >> v[i] >> w[i];
    }
    ll dp[N+1][W+1];
    rep(i,N+1){
        rep(j,W+1){
            dp[i][j] = 0;
        }
    }
    repp(i,1,N+1){
        rep(j,W+1){
            if(j-w[i-1]<0){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j - w[i-1]] + v[i-1]);
            }
        }
    }
    cout << dp[N][W] << endl;
}