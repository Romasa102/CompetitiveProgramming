#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> parents;
ll find(ll x){
    if(parents[x] == x) return x;
    else return parents[x] = find(parents[x]);
}
void unite(ll x,ll y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    parents[x] = y;
}
int main(){
    ll N,K;cin >> N >> K;
    parents.resize(K);
    rep(i,K) parents[i] = i;
    vector<ll> t(N);
    rep(i,N) cin >> t[i];
    priority_queue<P,vector<P>,greater<P>> pq;
    rep(i,K) pq.push(P(t[i],i));
    ll cur = K-1;
    ll times = 0;
    ll ans = 0;
    while(!pq.empty()&&cur < N) {
        vector<ll> enterC;
        P minn = pq.top();
        enterC.push_back(minn.second);
        pq.pop();
        while (!pq.empty()&&pq.top().first == minn.first){
            unite(minn.second,pq.top().second);
            if(pq.empty()){
                enterC.push_back(minn.second);
            }
            enterC.push_back(pq.top().second);
            pq.pop();
        }
        rep(i,enterC.size()){
            cur++;
            if(cur == N){
                pq.push({minn.first,enterC[i]});
                break;
            }
            pq.push({minn.first + t[cur],enterC[i]});
        }
        if(cur == N){
            break;
        }
    }
    ans = pq.top().second;
    times = pq.top().first;
    cout << times << endl;
    rep(i,K){
        if(find(i) == find(ans))cout << 1;
        else cout << 0;
    }cout << endl;

}