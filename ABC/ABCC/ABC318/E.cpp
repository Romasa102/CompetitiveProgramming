#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    ll A[N];
    map<ll,vector<ll>> num;
    rep(i,N){
        cin >> A[i];
        num[A[i]].push_back(i);
    }
    ll ans = 0;
    rep(i,N){

    }
} 