#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    ll a[M],b[M],l[M];
    map<ll,vector<P>> connection;
    rep(i,M){
        cin >> a[i] >> b[i] >> l[i];
        a[i]--;b[i]--;
        connection[a[i]].push_back({b[i],l[i]});
        connection[b[i]].push_back({a[i],l[i]});
    }
    priority_queue<P,vector<P>,greater<P>> Q;//dist,index
    rep(i,K){
        ll s;
        cin >> s;s--;
        Q.push({0,s});
    }
    vector<ll> dist(N,-1);
    while(!Q.empty()){
        P cur = Q.top();//first = distance, second = index
        Q.pop();
        if(dist[cur.second]!=-1)continue;
        dist[cur.second] =  cur.first;
        for(P i : connection[cur.second]){
            if(dist[i.first]==-1){
                Q.push({dist[cur.second]+i.second,i.first});
            }
        }
    }
    ll ans = 0;
    rep(i,M){
        if(min(dist[a[i]],dist[b[i]])+l[i]>max(dist[a[i]],dist[b[i]])){
            ll ansm = (double)(dist[a[i]]+dist[b[i]]+l[i])/double(2)+0.5;
            ans = max(ans, ansm);
        }else{
            ans = max({ans,dist[a[i]],dist[b[i]]});
        }
    }
    cout << ans << endl;
}