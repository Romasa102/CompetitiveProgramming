#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<vector<ll>> connection(210000);
ll A[201000];
ll Fans = 0;
ll N,M;
void dfs(ll a,vector<bool>visited,ll currentM, set<ll> types){
    if(currentM>A[a])return;
    types.insert(A[a]);
    visited[a] = true;
    for(ll i: connection[a]){
        if(visited[i])continue;
        dfs(i,visited,A[a],types);
    }
    if(a == N-1){
        Fans = max(Fans,(ll)types.size());
    }
}
int main(){
    cin >> N >> M;
    rep(i,N)cin >> A[i];
    rep(i,M){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        connection[u].push_back(v);
        connection[v].push_back(u);
    }
    set<ll>em;
    vector<bool> emp(N, false);
    dfs(0,emp,0,em);
    cout << Fans << endl;
}