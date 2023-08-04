#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll a[N];
    rep(i,N){
        cin >> a[i];
    }
    ll ans = 100000000000;
    for(int bit = 0;bit < 1<<N;bit++){
        if(__builtin_popcount(bit) < K) continue;
        ll highestNow = 0;
        ll cost = 0;
        rep(i,N){
            if(bit&1<<i){
                if(highestNow >= a[i]){ // you cant see if the height was same
                    cost += highestNow - a[i] +1;
                    highestNow+=1;
                }
            }
            highestNow = max(a[i],highestNow);
        }
        ans = min(ans,cost);
    }
    cout << ans << endl;
}