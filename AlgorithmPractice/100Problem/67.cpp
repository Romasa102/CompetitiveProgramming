#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<P,P> parent;
P find(P child){
    if(parent[child] == child)return child;
    return parent[child] = find(parent[child]);
}
void Union(P a,P b){
    parent[find(a)] = find(b);
}
int main(){
    ll N;
    cin >> N;
    P city[N];
    rep(i,N){
        cin >> city[i].first >> city[i].second;
        parent[city[i]] = city[i];
    }
}