#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll A[5];
    ll ans =0;
    rep(i,5){
        cin >> A[i];
        ans += A[i];
    }
    cout << ans << endl;
}