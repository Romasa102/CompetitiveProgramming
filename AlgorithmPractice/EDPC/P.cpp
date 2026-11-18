#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
vector<vector<ll>> dp; // 0 is white  1 is black
map<ll,vector<ll>> mp;
vector<ll> visited;
const ll MOD = 1e9 + 7;
void dfs(ll x){
    for(auto i : mp[x]){
        if(!visited[i]){
            visited[i]=true;
            dfs(i);
            dp[x][0] *= (dp[i][0] + dp[i][1]) % MOD;
            dp[x][0] %= MOD;
            dp[x][1] *= dp[i][0];
            dp[x][1] %= MOD;
        }
    }
}
int main(){
    ll N;
    cin >> N;
    ll x[N-1],y[N-1];
    rep(i,N-1){
        cin >> x[i] >> y[i];x[i]--;y[i]--;
        mp[x[i]].push_back(y[i]);
        mp[y[i]].push_back(x[i]);
    }
    dp.resize(N,vector<ll>(2,1));
    visited.resize(N,false);
    visited[0]=true;
    dfs(0);
    rep(i,N){
        //cout << i << "th : " << dp[i][0] << " black: " << dp[i][1] << endl;
    }cout << (dp[0][0] + dp[0][1]) % MOD << endl;

}