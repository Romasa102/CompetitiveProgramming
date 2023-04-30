#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll X[N];
    rep(i,N){
        cin >> X[i];
    }
    vector<P> C(M);
    rep(i,M){
        cin >> C[i].first >> C[i].second;
    }
    ll dp[N+1][N+1];
    rep(i,N+1){
        rep(j,N+1){
            dp[i][j] = 0;
        }
    }
    ll count = 0;
    dp[0][0] = 0;
    rep(i,N){
        count++;
        rep(j,count){
            if(dp[i][j] > dp[i+1][0]){
                dp[i+1][0] = dp[i][j];
            }
            dp[i+1][j+1] = dp[i][j] + X[i];
            rep(k,M){
                if(j+1 == C[k].first){ 
                    dp[i+1][j+1]+=C[k].second;
                }
            }
        }
    }
    ll ans = 0;
    rep(i,N){
        if(ans < dp[N][i]){
            ans = dp[N][i];
        }
    }
    cout << ans << endl;
}