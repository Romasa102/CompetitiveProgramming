#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    std::vector<ll> teeth(N,1);
    rep(i,Q){
        ll t;
        cin >> t;
        if(teeth[t-1]==0){
            teeth[t-1]=1;
        }else{
            teeth[t-1]=0;
        }
    }

    ll ans =0;
    rep(i,N){
        if(teeth[i] == 1){
            ans++;
        }
    }cout << ans << endl;
}