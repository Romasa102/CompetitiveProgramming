#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll x;
    cin >> x;
    ll cash = x;
    double ans = 1;
    rep(i,4){
        cash-=5;
        ans *= ((double)cash/(double)x);
    }
    cout << ans << endl;
}