#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll effort[200000];
map<ll,vector<ll>> connection;
ll fans = 0;
ll dfs(ll x){
    ll ans = effort[x];
    if(connection.find(x)==connection.end())return max(0LL,ans);
    for(ll i: connection[x]){
        ans += max(0LL,dfs(i));
    }
    fans = max(ans,fans);
    return max(0LL,ans);
}
int main(){
    ll n;
    cin >> n;
    ll bestOA = -(1LL<<20);
    rep(i,n){
        effort[i]=0;
    }
    rep(i,n){
        ll s,a;
        cin >> s >> a;
        connection[s].push_back(i+1);
        effort[i+1]=a;
        bestOA=max(bestOA,effort[i+1]);
    }
    dfs(0);
    if(fans==0){
        cout << bestOA << endl;
        return 0;
    }
    cout << fans << endl;
}