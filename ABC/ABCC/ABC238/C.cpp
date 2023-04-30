#include <bits/stdc++.h>
using ll = unsigned long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll J = N;
    ll digits = 0;
    while(J > 0){
        digits++;
        J /= 10;
    }
    ll ans = 0;
    ll g = 0;
    rep(i,digits - 1){
        ll y = 9 * pow(10,i);
        g += y;
        ans += (((y + 1)%998244353) * (y% 998244353) /2)%998244353;
    }
    ll k = (((N - g + 1)%998244353) * ((N - g)%998244353)/2)%998244353;
    ans += k;
    cout << ans << endl;
}