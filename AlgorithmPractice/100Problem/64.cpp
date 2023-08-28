#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll parents[100000];
int find(int child){
    if(parents[child] == child)return child;
    return parents[child] = find(parents[child]);
}
void Union(int a,int b){
    parents[find(a)] = find(b);
}
int main(){
    ll V,E;
    cin >> V >> E;
    ll s[E];
    ll t[E];
    ll w[E];
    P Edges[E];
    rep(i,V){
        parents[i] = i;
    }
    rep(i,E){
        cin >> s[i] >> t[i] >> w[i];
        Edges[i].first = w[i];
        Edges[i].second = i;
    }
    ll ans = 0;
    sort(Edges,Edges+E);
    rep(i,E){
        if(find(s[Edges[i].second]) != find(t[Edges[i].second])){
            Union(s[Edges[i].second],t[Edges[i].second]);
            ans += Edges[i].first;
        }
    }
    cout << ans << endl;
}