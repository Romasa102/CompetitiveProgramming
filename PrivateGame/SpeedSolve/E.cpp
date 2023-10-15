#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,X;
    cin >> n >> X;
    ll a[n];
    rep(i,n){
        cin >> a[i];
    }
    ll ans = 0;
    rep(i,n){
        if(1LL<<i&X){
            ans += a[i];
        }
    }
    cout << ans << endl;
}