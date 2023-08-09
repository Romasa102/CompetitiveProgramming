#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,vector<ll>> m;
vector<ll> d(1000);
vector<ll> f(1000);
ll currentC = 0;
bool visited[1000];
void dfs(ll o){
    if(visited[o])return;
    visited[o] = true;
    currentC++;
    d[o] = currentC;
    for(auto i : m[o]){
        dfs(i);
    }
    currentC++;
    f[o] = currentC;
}
int main(){
    ll n;
    cin >> n;
    rep(i,n){
        ll u,k;
        cin >> u >> k;
        rep(i,k){
            ll inp;
            cin >> inp;
            m[u].push_back(inp);
        }
    }
    d[0] = 0;
    rep(i,n){
        dfs(i+1);
    }
    rep(i,n){
        cout << i+1 << " " << d[i+1] << " " << f[i+1] << endl;
    }
}