#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;cin >> N >> K;
    map<ll,ll> mp;
    ll A[N];
    ll sans = 0;
    rep(i,N){
        cin >> A[i];
        if(A[i] <= K){
            if(mp.find(A[i]) == mp.end()){
                mp[A[i]]++;
                sans+=A[i];
            }
        }
    }
    cout << (K+1)*K/2 - sans << endl;

}