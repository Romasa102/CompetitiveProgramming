#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> parents
int main(){
    ll T;cin >> T;
    rep(i,T){
        ll N,M;
        cin >> N >> M;
        map<ll,vector<ll>> connection;
        rep(i,M){
            ll a,b;
            cin >> a >> b;
            connection[a].push_back(b);
            connection[b].push_back(a);
        }
        queue<ll> Q;
        Q.push(1);
        vector<bool> visited(N+1,false);
        vector<ll> C1;//connected to 1
        while(!Q.empty()){
            ll cur = Q.front();
            C1.push_back(cur);
            Q.pop();
            visited[cur] = true;
            for(ll i:connection[cur]){
                if(visited[i])continue;
                Q.push(i);
            }
        }
        Q.push(N);
        visited.resize(N+1,false);
        vector<ll> CN;
        while(!Q.empty()){
            ll cur = Q.front();
            C1.push_back(cur);
            Q.pop();
            visited[cur] = true;
            for(ll i:connection[cur]){
                if(visited[i])continue;
                Q.push(i);
            }
        }
        
    }
}