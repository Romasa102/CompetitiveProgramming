#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll C[N];
    ll G[N];
    map<ll,vector<ll>> M;
    rep(i,N){
        cin >> C[i] >> G[i];
        M[G[i]].push_back(C[i]);
    }
    ll ans = 0;
    for(auto itr = M.begin(); itr != M.end(); ++itr){
        sort(itr->second.begin(),itr->second.end());
    }
    ll dp[15][K+1];
    rep(i,K){
        dp[0][i] = 0;
    }
}