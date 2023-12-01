#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> longest;
map<ll,vector<ll>> road;
ll dfs(ll o){
    if(longest[o]!=-1)return longest[o];
    if(road.find(o)==road.end()){
        return 0;
    }else{
        ll curM = 0;
        for(ll i:road[o]){
            curM = max(curM,dfs(i)+1);
        }
        return longest[o] = curM;;
    }
}
int main(){
    ll N,M;
    cin >> N >> M;
    ll x[M],y[M];
    longest.resize(N,-1);
    rep(i,M){
        cin >> x[i] >> y[i];
        x[i]--;y[i]--;
        road[x[i]].push_back(y[i]);
    }
    ll ans = 0;
    rep(i,N){
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
}