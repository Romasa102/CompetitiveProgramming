#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> dist;
map<ll,vector<ll>> connection;
ll dfs(ll now,ll from){
    if(dist[now]!=-1)return dist[now];
    ll ans = 1;
    for(ll next:connection[now]){
        if(next==from)continue;
        ans+=dfs(next,now);
    }
    return dist[now]=ans;
}
int main(){
    ll N;
    cin >> N;
    ll u[N],v[N];
    rep(i,N-1){
        cin >> u[i] >> v[i];
        u[i]--;v[i]--;
    }
    rep(i,N-1){
        connection[u[i]].push_back(v[i]);
        connection[v[i]].push_back(u[i]);
    }
    if(connection[0].size()==1){
        cout << 1 << endl;
        return 0;
    }
    dist.resize(N+1,-1);
    vector<ll> anss;
    for(ll i:connection[0]){
        anss.push_back(dfs(i,0));
    }
    ll fans=1;
    sort(anss.begin(),anss.end());
    rep(i,connection[0].size()-1){
        fans+=anss[i];
    }
    cout << fans << endl;
}