#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<P>> rock(n);
    rep(i,n){
        ll k;
        cin >> k;
        rep(j,k){
            ll x,d;
            cin >> x >> d;
            rock[i].push_back({x,d});
        }
    }
    ll dp[n+1][m+1][11];
    rep(i,n+1)rep(j,m+1)rep(x,11)dp[i][j][x] = 1LL<<50;
    rep(x,rock[0].size())dp[0][0][x]=0;
    if(m>0){
        rep(x,rock[1].size())dp[1][1][x]=0;
    }
    rep(i,n-1){
        rep(j,m+1){
            rep(x,rock[i].size()){
                P cur = rock[i][x];
                rep(nu,rock[i+1].size()){
                    dp[i+1][j][nu]=min(dp[i+1][j][nu],dp[i][j][x]+abs(abs(cur.first-rock[i+1][nu].first) * (cur.second+rock[i+1][nu].second)));
                }
                if(j<=m-1&&i<n-2){
                    rep(nu,rock[i+2].size()){
                        dp[i+2][j+1][nu]=min(dp[i+2][j+1][nu],dp[i][j][x]+abs(abs(cur.first-rock[i+2][nu].first) * (cur.second+rock[i+2][nu].second)));
                    }
                }
            }
        }
    }
    ll ans = 1LL<<50;
    rep(i,m){
        rep(x,rock[n-2].size()){
            ans = min(ans,dp[n-2][i][x]);
        }
    }
    rep(i,m+1){
        rep(x,rock[n-1].size()){
            ans = min(ans,dp[n-1][i][x]);
        }
    }
    cout << ans << endl;
}