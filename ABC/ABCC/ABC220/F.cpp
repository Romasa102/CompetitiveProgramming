#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

map<ll,vector<ll>> mp;

vector<bool> visited;
void dfs1(){
    
}
int main(){
    ll N;
    cin >> N;
    visited.resize(N,false);
    rep(i,N-1){
        ll u,v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dfs1(0);
}