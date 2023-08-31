#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n;
    ll m;
    cin >> n >> m;
    map<ll,ll> connection;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        connection[a] = b;
        connection[b] = a;
    }
    queue<ll> Q;
    Q.push(1);
    while(!Q.empty()){
        
    }
}