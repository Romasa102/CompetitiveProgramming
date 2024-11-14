#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,C;
    cin >> N >> C;
    ll T[N];
    rep(i,N){
        cin >> T[i];
    }
    ll ans = 1;
    ll cur = T[0];
    rep(i,N-1){
        if(T[i+1] - cur >= C){
            ans++;
            cur = T[i+1];
        }
    }
    cout << ans << endl;

}