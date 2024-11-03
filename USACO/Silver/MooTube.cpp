#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,vector<P>> mp;
vector<bool> visited;
ll v,k,ans;
void dfs(ll cur){
    if(visited[cur]) return;
    visited[cur] = 1;
    for(auto x: mp[cur]) {
        if (visited[x.first]) continue;
        if(x.second < k) continue;
        ans++;
        dfs(x.first);
    }
}
int main(){
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);

    ll N,Q; cin >> N >> Q;
    ll p,q,r;
    visited.resize(N,0);
    rep(i,N-1){
        cin >> p >> q >> r;p--;q--;
        mp[p].push_back({q,r});
        mp[q].push_back({p,r});
    }
    rep(i,Q){
        cin >> k >> v;v--;
        std::fill(visited.begin(), visited.end(), false);
        ans = 0;
        dfs(v);
        cout << ans << endl;
    }
}