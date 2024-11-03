#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,bool> usable;
vector<vector<ll>> connection;
vector<ll> childsC;
vector<ll> parents;
ll ans = 0;
ll dfs(ll x){
    if(childsC[x] == 0){
        if(usable.find(x)!=usable.end()){
            ans++;
            return 0;
        }else{
            return 1;
        }
    }
    ll remains = 0;
    for(ll i: connection[x]){
        remains += dfs(i);
    }
    if(usable.find(x)==usable.end()){
        return remains;
    }else{
        if(remains>0){
            ans++;
            return remains-1;
        }
        return 0;
    }

}
int main(){
    ll N;cin >> N;
    ll p[N];{
        rep(i,N)cin >> p[i];
    }
    vector<P> ab(N-1);
    rep(i,N-1){
        cin >> ab[i].first >> ab[i].second;
        ab[i].first--;ab[i].second--;
    }
    childsC.resize(N);
    parents.resize(N);
    connection.resize(N);
    rep(i,N-1){
        parents[ab[i].second]=ab[i].first;
        connection[ab[i].first].push_back(ab[i].second);
        childsC[ab[i].first]++;
    }
    ll edges= 0;
    rep(i,N){
        if(childsC[i]==0){
            edges++;
        }
    }
    rep(i,edges){
        usable[p[i]-1]=true;
    }
    dfs(0);
    cout << ans << endl;
}