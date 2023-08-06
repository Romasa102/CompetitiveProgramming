#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <utility>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll d;
    cin >> d;
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    ll sub[n+1];
    ll k[m];
    sub[0] = 0;
    sub[n] = d;
    rep(i,n-1){
        cin >> sub[i+1];
    }
    rep(i,m){
        cin >> k[i];
    }
    ll F,S;
    ll ans = 0;
    sort(sub,sub + n + 1);
    rep(i,m){
        F = *lower_bound(sub,sub+n+1,k[i]);
        S = *(lower_bound(sub,sub+n+1,k[i])-1);
        ans += min(abs(F-k[i]),abs(S-k[i]));
    }
    cout << ans << endl;
}