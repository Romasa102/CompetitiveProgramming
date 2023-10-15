#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<pair<ll,vector<ll>>,ll> dpT;
ll A[1000][10];
ll C[1000];
ll N,K,PN;
ll dp(ll i,vector<ll> o){
    if(dpT.find({i,o}) != dpT.end()){
        return dpT[{i,o}];
    }
    if(i == N){
        rep(j,K){
            if(o[j] != PN){
                return 1LL<<58;
            }
        }
        return 0;
    }else{
        vector<ll> newV = {};
        rep(j,K){
            newV.push_back(min(PN,o[j] + A[i][j]));
        }
        return dpT[{i,o}] = min(dp(i+1,o),C[i]+dp(i+1,newV));
    }
}
int main(){
    cin >> N >> K >> PN;
    rep(i,N){
        cin >> C[i];
        rep(j,K){
            cin >> A[i][j];
        }
    }
    vector<ll> U;
    rep(i,K){
        U.push_back(0);
    }
    ll ans = dp(0,U);
    if(ans >= 1LL<<58){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}