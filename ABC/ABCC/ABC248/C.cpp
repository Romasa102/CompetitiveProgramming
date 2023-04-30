#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    ll dp[N][N*M] = {0};
    rep(i,M){
        dp[0][i] = 1;
    }
    rep(i,N-1){
        rep(j,N*M){
            if(dp[i][j] != 0){
                rep(k,M){
                    if(j+k+1 < N*M){
                        dp[i+1][j + k + 1] += dp[i][j];
                    }
                    if(dp[N-1][i] != 0){dp[i+1][j + k + 1]%=998244353;}
                }
            }
        }
    }
    ll ans = 0;
    rep(i,K){
        if(dp[N-1][i] != 0){
            ans = (ans + dp[N-1][i]) % 998244353;
        }
    }
    cout << ans << endl;
}