#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll cost[N];
    rep(i,N)cin >> cost[i];
    ll dp[N][2*N+1][2];//i番目まで　ＡがＢよりj大きい　最後のお菓子はkに属する
    rep(i,N)rep(j,2*N+1)rep(k,2)dp[i][j][k]=1LL<<60;
    dp[0][0][0]=0;
    rep(i,N){
        rep(j,i+1){
            dp[i][j+N][0]=min(dp[i-1][j+N-1][0],dp[i][j+N][0]);
            dp[i][j+N][1]=min(dp[i-1][j+N+1][1],dp[i][j+N][1]);
            dp[i][j+N][0]=min(dp[i][j+N][0],)
        }
    }
}