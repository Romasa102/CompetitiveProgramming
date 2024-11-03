#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    scanf("%lld %lld", &N, &M);
    ll S,T,L,K;
    scanf("%lld %lld %lld %lld", &S, &T, &L, &K);
    vector<ll> A(M),B(M),C(M);
    map<ll,vector<P>> connections;
    rep(i,M){
        scanf("%lld %lld %lld", &A[i], &B[i], &C[i]);
        connections[A[i]-1].push_back({B[i]-1,C[i]});
        connections[B[i]-1].push_back({A[i]-1,C[i]});
    }
    vector<ll> dist(N,1LL<<50);
    vector<bool> visited(N,false);
    priority_queue<P,vector<P>,greater<P>> q;q.push({0,S-1});dist[S-1] = 0;
    while(!q.empty()){
        P now = q.top();q.pop();
        if(visited[now.second])continue;
        visited[now.second] = true;
        if(connections.find(now.second) == connections.end())continue;
        for(auto next:connections[now.second]){
            if(dist[next.first] > dist[now.second]+next.second && !visited[next.first]){
                dist[next.first] = dist[now.second]+next.second;
                q.push({dist[next.first],next.first});
            }
        }
    }
    vector<ll> dist2(N,1LL<<50);
    vector<bool> visited2(N,false);
    priority_queue<P,vector<P>,greater<P>> q2;q2.push({0,T-1});dist2[T-1] = 0;
    while(!q2.empty()){
        P now = q2.top();q2.pop();
        if(visited2[now.second])continue;
        visited2[now.second] = true;
        if(connections.find(now.second) == connections.end())continue;
        for(auto next:connections[now.second]){
            if(dist2[next.first] > dist2[now.second]+next.second&& !visited2[next.first]){
                dist2[next.first] = dist2[now.second]+next.second;
                q2.push({dist2[next.first],next.first});
            }
        }
    }
    ll ans = 0;
    rep(i,N){
        if(dist[i]+dist2[i] <= K){
            ans=N*(N-1)/2;
            printf("%lld\n", ans);
            return 0;
        }
    }
    K-=L;
    sort(dist2.begin(),dist2.end());
    rep(i,N){
        ll cash = K - dist[i];
        ans += upper_bound(dist2.begin(),dist2.end(),cash) - dist2.begin();
    }
    printf("%lld\n", ans);
}