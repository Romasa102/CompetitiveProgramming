#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll parent[10100];
ll find(ll o){
    if(o == parent[o])return o;
    return parent[o] = find(parent[o]);
}
void unite(ll a,ll b){
    parent[find(a)] = parent[find(b)];
}
int main(){
    ll n,m;
    cin >> n >> m;
    rep(i,n){
        parent[i] = i;
    }
    rep(i,m){
        ll c,d;
        cin >> c >> d;
        unite(c,d);
    }
    set<ll> pattern;
    rep(i,n){
        pattern.insert(find(i));
    }
    cout << pattern.size()-1 << endl;
}