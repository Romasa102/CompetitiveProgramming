#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

int main(){
    ll N, M;
    cin >> N >> M;
    ll a[M], b[M], c[M];//a~b's temp c
    vector<vector<P>> path(N);//all paths
    vector<vector<ll>> roomTemps(N);//all possible temps in the room
    rep(i, M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        path[a[i]].push_back({b[i], c[i]});
        path[b[i]].push_back({a[i], c[i]});
        roomTemps[a[i]].push_back(c[i]);
        roomTemps[b[i]].push_back(c[i]);
    }
    rep(i, N){
        roomTemps[i].push_back(0);
        sort(roomTemps[i].begin(), roomTemps[i].end());
        roomTemps[i].erase(unique(roomTemps[i].begin(), roomTemps[i].end()),roomTemps[i].end());
    }
    vector<vector<ll>> dist(N);
    rep(i, N) dist[i].assign(roomTemps[i].size(), 1LL << 60);
    priority_queue<pair<ll,P>,vector<pair<ll,P>>,greater<pair<ll,P>>> pq;
    
    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        ll d = cur.first;
        ll u = cur.second.first;
        ll idx = cur.second.second;
        if(d != dist[u][idx]) continue;
        ll curT = roomTemps[u][idx];
        
        if(idx - 1 >= 0){
            ll nd = d + (curT - roomTemps[u][idx-1]);
            if(nd < dist[u][idx-1]){
                dist[u][idx-1] = nd;
                pq.push({nd, {u, idx-1}});
            }
        }
        if(idx + 1 < roomTemps[u].size()){
            ll nd = d + (roomTemps[u][idx+1] - curT);
            if(nd < dist[u][idx+1]){
                dist[u][idx+1] = nd;
                pq.push({nd, {u, idx+1}});
            }
        }
        
        for(auto edge : path[u]){
            if(edge.second == curT){
                ll v = edge.first;
                ll j = lower_bound(roomTemps[v].begin(), roomTemps[v].end(), curT) - roomTemps[v].begin();
                if(d < dist[v][j]){
                    dist[v][j] = d;
                    pq.push({d, {v, j}});
                }
            }
        }
    }
    
    ll ans = 1LL << 60;
    for(auto cost : dist[N-1])ans = min(ans, cost);
    cout << ans << endl;
    return 0;
}