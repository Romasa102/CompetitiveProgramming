#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<P> AB(N);
    map<ll,vector<ll>> connection;
    rep(i,N){
        cin >> AB[i].first >> AB[i].second;
        connection[AB[i].first-1].push_back(AB[i].second-1);
        connection[AB[i].second-1].push_back(AB[i].first-1);
    }
    queue<ll> Q;
    Q.push(0);
    bool searched[N];
    rep(i,N)searched[i] = false;
    ll dist[N];
    rep(i,N)dist[i]=1LL<<32;
    dist[0]=0;
    ll furthestP = 0;
    ll furthestN = 0;
    while(!Q.empty()){
        ll now = Q.front();
        Q.pop();
        if(searched[now])continue;
        searched[now] = true;
        for(ll i:connection[now]){
            if(searched[i])continue;
            Q.push(i);
            if(dist[i]>dist[now]+1){
                dist[i]=dist[now]+1;
                if(dist[i]>furthestN) {
                    furthestN = dist[i];
                    furthestP = i;
                }
            }
        }
    }
    Q.push(furthestP);
    rep(i,N)searched[i] = false;
    rep(i,N)dist[i]=1LL<<32;
    dist[furthestP]=0;
    furthestN=0;
    while(!Q.empty()){
        ll now = Q.front();
        Q.pop();
        if(searched[now])continue;
        searched[now] = true;
        for(ll i:connection[now]){
            if(searched[i])continue;
            Q.push(i);
            if(dist[i]>dist[now]+1){
                dist[i]=dist[now]+1;
                if(dist[i]>furthestN)furthestN=dist[i];
            }
        }
    }
    cout << furthestN + 1<< endl;
}