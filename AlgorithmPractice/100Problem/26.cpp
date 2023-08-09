#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,vector<ll>> m;
ll counter[300000];
bool visited[300000];
void dfs(ll x,ll p){
    if(visited[x])return;
    visited[x] = true;
    counter[x]+=p;
    for(ll i:m[x]){
        dfs(i,counter[x]);
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
        m[ab[i].second].push_back(ab[i].first);
        counter[i] = 0;
        visited[i] = false;
    }
    rep(i,Q){
        cin >> px[i].first >> px[i].second;
        counter[px[i].first] += px[i].second;
    }
    dfs(1,0);
    rep(i,N){
        cout << counter[i+1] << " ";
    }
}//you have to use cumulative sum