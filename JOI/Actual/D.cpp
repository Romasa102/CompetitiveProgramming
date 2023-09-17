#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    set<ll> S;
    rep(i,N){
        cin >> A[i];
        S.insert(A[i]);
    }
    for(auto x : S){
        cout << x << endl;
    }
}