#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,D;
    cin >> N >> D;
    P LR[N];
    rep(i,N){
        cin >> LR[i].second >> LR[i].first;
    }
    sort(LR,LR+N);
    ll ans = 0;
    ll latest = -10000000000;
    rep(i,N){
        if(latest+D-1 >= LR[i].second){
            continue;
        }
        latest=LR[i].first;
        ans ++;
    }
    cout << ans << endl;
}