#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin >> N;
    map<ll,vector<ll>> connection;
    rep(i,N-1){
        ll a,b;cin >> a >> b;a--;b--;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }
    queue<ll> Q;
    vector<hool> 
    ll cost = 0;
    Q.push(0);
    ll ans = 0;
    while(!Q.empty()){
        ll cur = Q.front();
        Q.pop();
        visited[cur]=true;
        ll count = 1;
        for(ll i : connection[cur]){
            if(visited[i])continue;
            Q.push(i);
            count++;
        }
        ans += ceil(log2(count));
    }
    cout << ans << endl;
}