#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
using PP = pair<P,P>;
vector<PP> parents;
ll parent(ll a){
    if(parents[a].first.first == a)return a;
    return parent(parents[a].first);
}
ll unite(ll a,ll b){
    parents[parent(a)].first = parent(b);
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    parents.resize(N);
    rep(i,N){
        parents[i].first = i;
        parents[i].second = i+1;
    }
    rep(i,Q){
        ll que;
        cin >> que;
        if(que == 1){
            ll x,c;
            cin >> x >> c;
            parents[parent(x-1)].second = c;
            if()
        }else{

        }
    }
}