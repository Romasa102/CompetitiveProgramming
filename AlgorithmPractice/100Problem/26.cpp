#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,vector<ll>> m;
ll counter[300000];
void dfs(ll x,ll p){
    counter[x] += p;
    for(int i:m[x]){
        dfs(i,p);
    }
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<P> ab(N-1);
    vector<P> px(Q);
    rep(i,N-1){
        cin >> ab[i].first >> ab[i].second;
        m[ab[i].first].push_back(ab[i].second);
    }
    rep(i,Q){
        cin >> px[i].first >> px[i].second;
        dfs(px[i].first,px[i].second);
    }
    rep(i,N){
        cout << counter[i+1] << " ";
    }
}