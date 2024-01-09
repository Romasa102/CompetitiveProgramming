#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> parents;
ll find(ll x){
    if(x == parents[x]){
        return x;
    }
    return find(parents[x]);
}
void Union(ll a,ll b){
    parents[find(a)] = find(b);
}
int main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    ll N;cin >> N;
    ll ans = 0;
    rep(i,N)parents.push_back(i);
    P XY[N];rep(i,N)cin >> XY[i].first >> XY[i].second;
    priority_queue<pair<ll,P>,vector<pair<ll,P>>,greater<pair<ll,P>>> connection;
    rep(i,N){
        rep(j,N){
            connection.push({(XY[i].first-XY[j].first)*(XY[i].first-XY[j].first)+(XY[i].second-XY[j].second)*(XY[i].second-XY[j].second),{i,j}});
        }
    }
    while(!connection.empty()){
        auto cur = connection.top();
        connection.pop();
        if(find(cur.second.first) != find(cur.second.second)){
            ans = max(ans,cur.first);
            Union(cur.second.first,cur.second.second);
        }
    }
    cout << ans << endl;
}