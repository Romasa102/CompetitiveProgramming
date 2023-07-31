#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,L,W;
    cin >> N >> L >> W;
    ll a[N + 1];
    a[N] = L;
    rep(i,N){
        cin >> a[i];
    }
    ll ans = 0;
    if(a[0]%W != 0) ans++;
    ans += (a[0] - 0)/W;
    cout << a[N] << a[N - 1] + W << endl;
    rep(i,N){
        if(a[i + 1] - (a[i] + W) <= 1) continue;
        if((a[i + 1] - (a[i] + W) - 1)%W != 0) ans++;
        ans += (a[i + 1] - (a[i] + W) - 1)/W;
    }
    cout << ans << endl;
}