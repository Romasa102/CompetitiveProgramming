#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,vector<ll>> children;
ll N,M;
ll dp[10000000];
ll ans = 0;
void child(ll O,ll current){
    dp[O] = max(dp[O],current+1);
    ans = max(ans,dp[O]);
    rep(i,children[O].size()){
        child(children[O][i],dp[O]);
    }
}
int main(){
    cin >> N >> M;
    vector<ll> Parent;  
    ll x,y;
    rep(i,N){
        Parent.push_back(i);
    }
    rep(i,M){
        cin >> x >> y;
        children[x-1].push_back(y-1);
    }
    rep(i,N){
        child(i+1,0);
    }
    cout << ans << endl;
}