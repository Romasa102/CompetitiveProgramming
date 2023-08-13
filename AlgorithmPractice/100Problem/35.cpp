#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,W;
    cin >> N >> W;
    ll v[N];
    ll w[N];
    rep(i,N){
        cin >> v[i] >> w[i];
    }
    ll dp[N+1][W+1];
    rep(i,N+1){
        rep(j,W+1){
            dp[i][j] = 0;
        }
    }
    rep(i,W+1){
        if(i+1 > w[0]){
            dp[0][i] = v[0];
        }
    }
    for(int i = 1; i < N + 1; i++){
        rep(j,W + 1){
            if(j-w[i]<0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    cout << dp[N-1][W] << endl;
}