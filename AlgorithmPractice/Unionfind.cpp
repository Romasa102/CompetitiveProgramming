#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> parent;
ll find(ll x){
    if(parent[x] == x)return x;
    return parent[x] = find(parent[x]);
}

void unite(ll x, ll y){
    parent[x] = find(y);
}
int main(){
    ll n,m;
    parent.resize(n*m,-1);
    rep(i,n)parent[i] = i;
    vector<vector<char>> mp;
    n = mp.size();
    m = mp[0].size();
    rep(i,n){
        rep(j,m){
            ll ind = i * m + j;
            if(mp[i-1][j] == mp[i][j]){
                unite(ind, (i-1)*m+j);
            }
            if(mp[i][j-1] == mp[i][j]){
                unite(ind, i*m+j-1);
            }
        }
    }
    set<ll> ans;
    rep(i,n){
        rep(j,m){

            ll ind = i * m + j;
            if(mp[i][j] == '1'){
                ans.insert(find(ind));
            }
        }
    }
    cout << ans.size() << endl;
}