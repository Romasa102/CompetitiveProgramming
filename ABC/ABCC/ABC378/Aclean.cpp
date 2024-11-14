#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll count[4];
    rep(i,4)count[i]=0;
    ll A[4];
    rep(i,4){
        cin >> A[i];
        count[A[i]-1]++;
    }
    ll ans = 0;
    rep(i,4){
        ans += (count[i]/2);
    }
    cout << ans << endl;
}