#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,A,B,C;
    cin >> N >> A >> B >> C;
    ll D[N][N];
    rep(i,N)rep(j,N){
        cin >> D[i][j];
    }
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,0});
    bool searched[N];
    ll dis[N];
    rep(i,N){
        searched[i]=false;
        dis[i]=-1;
    }
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();
        if(searched[now.second])continue;
        dis[now.second]=now.first;
        searched[now.second]=true;
        rep(i,N){
            if(searched[i])continue;
            pq.push({now.first + D[now.second][i]*A,i});
        }
    }
    priority_queue<P,vector<P>,greater<P>> pq2;
    pq2.push({0,N-1});
    bool searched2[N];
    ll dis2[N];
    rep(i,N){
        searched2[i]=false;
        dis2[i]=1LL<<50;
    }
    dis2[N-1]=0;
    while(!pq2.empty()){
        P now = pq2.top();
        pq2.pop();
        if(searched2[now.second])continue;
        dis2[now.second]=now.first;
        searched2[now.second]=true;
        rep(i,N){
            if(searched2[i])continue;
            pq2.push({now.first + D[i][now.second]*B+C,i});
        }
    }
    ll ans = 1LL<<50;
    rep(i,N){
        ans = min(ans,dis[i]+dis2[i]);
    }
    cout << ans<< endl;
}