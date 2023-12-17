#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("cbarn.in", "r", stdin);
    ll n;
    cin >> n;
    ll r[n];
    rep(i,n){
        cin >> r[i];
    }
    ll ans = 1e9;
    rep(i,n){//starting pos;
        ll sum = 0;
        rep(j,n){//loop
            sum += r[(i+j)%n]*j;
        }
        ans = min(ans, sum);
    }
    freopen("cbarn.out", "w", stdout);
    cout << ans << endl;
}