#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll D[N];
    rep(i,N){
        cin >> D[i];
    }
    ll W[M];
    rep(i,M){
        cin >> W[i];
    }
    ll dp[M+1][N+1];
    rep(i,M+1){
        rep(j,N+1){
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    repp(i,1,M+1){
        repp(j,0,N + 1){
            if(j == 0) {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            if(dp[i-1][j] == -1){
                if(dp[i-1][j-1] == -1)continue;
                dp[i][j] = dp[i-1][j-1] + D[j-1] * W[i-1];
                continue;
            }
            dp[i][j] = min(dp[i-1][j],dp[i-1][j-1] + D[j-1] * W[i-1]);
        }
    }

    cout << dp[M][N] << endl;
}