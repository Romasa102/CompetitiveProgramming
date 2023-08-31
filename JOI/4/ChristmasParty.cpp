#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n;
    ll m;
    cin >> n >> m;
    map<ll,vector<ll>> connection;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }
    bool visited[n+1];
    ll dist[n+1];
    rep(i,n+1){
        visited[i] = false;
        dist[i] = 10000000;
    }
    queue<ll> Q;
    dist[1] = 0;
    Q.push(1);
    ll ans = 0;
    while(!Q.empty()){
        ll Now = Q.front();
        Q.pop();
        if(visited[Now])continue;
        visited[Now] = true;
        for(int i : connection[Now]){
            if(visited[i])continue;
            if(dist[i] == 10000000){
                dist[i] = dist[Now] + 1;
                Q.push(i);
            }
        }
    }
    rep(i,n+1){
        if(dist[i] <= 2)ans += 1;
    }cout << ans - 1 << endl;
}