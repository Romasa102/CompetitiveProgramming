#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,m;
    cin >> n >> m;
    ll s[n];
    rep(i,n-1){
        cin >> s[i];
    }
    ll Csum[n+1];
    Csum[0] = 0;
    rep(i,n-1){
        Csum[i+1] = Csum[i] + s[i];
    }
    ll a[m];
    ll  currentPos = 0;
    ll ans = 0;
    rep(i,m){
        cin >> a[i];
        ans += abs(Csum[currentPos + a[i]] - Csum[currentPos]);
        currentPos += a[i];
    }
    cout << ans << endl;
}