#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll N;
map<ll,vector<ll>> m;

int main(){
    cin >> N;
    ll d[150];
    rep(i,N){
        d[i+1] = -1;
        ll u;
        cin >> u;
        ll k;
        cin >> k;
        rep(j,k){
            ll v;
            cin >> v;
            m[u].push_back(v);
        }
    }
    queue<ll> Q;
    Q.push(1);
    ll counter = 0;
    while(Q.size()){
        ll prevQS = Q.size();
        rep(i,prevQS){
            ll p = Q.front();
            if(d[p] != -1){
                Q.pop();
                continue;
            }
            d[p] = counter;
            for(auto v : m[p]){
                Q.push(v);
            }
            Q.pop();
        }counter++;
    }
    rep(i,N){
        cout << i + 1 << " "<< d[i+1] << endl;
    }
}