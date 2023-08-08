#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,vector<ll>> m;
vector<ll> d(1000);
vector<ll> f(1000);
int dfs(ll o,ll currentC){
    d[o] = currentC;
    for(auto i : m[o]){
        f[o] = dfs(i,currentC+1);
        return f[o] + 1;
    }
    return currentC  +1;
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
    f[0] = dfs(0,1);
    rep(i,n){
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
}