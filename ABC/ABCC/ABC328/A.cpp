#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,X;
    cin >> N >> X;
    ll ans = 0;
    rep(i,N){
        ll a;
        cin >> a;
        if(a<=X){
            ans+=a;
        }
    }
    cout << ans << endl;
}