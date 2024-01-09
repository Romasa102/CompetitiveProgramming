#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> parents;
ll find(ll x){
    if(parents[x]==x)return x;
    return parents[x] = find(parents[x]);
}
void Union(ll a,ll b){
    parents[find(a)]=find(b);
}
int main(){
    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
    ll N,M;cin>>N>>M;
    ll p[N];rep(i,N)cin>>p[i];
    queue<P> requirement;
    rep(i,N) {
        if (p[i] != i + 1) {
            requirement.push({p[i], i + 1});
        }
    }
    rep(i,N+1)parents.push_back(i);
    ll a,b,w;
    priority_queue<pair<ll,P>> pq;
    rep(i,M) {
        cin >> a >> b >> w;
        pq.push({w,{a,b}});
    }
    ll ans = -1;
    while(!requirement.empty()){
        auto curR = requirement.front();
        requirement.pop();
        while(find(curR.first)!= find(curR.second)){
            Union(pq.top().second.first,pq.top().second.second);
            ans = pq.top().first;
            pq.pop();
        }
    }
    cout << ans << endl;
}