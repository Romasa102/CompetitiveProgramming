#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,S,M,L;
    cin >> N >>  S >> M >> L;
    ll ans = 1LL<<62;
    rep(i,N/6+2){
        rep(j,N/8+2){
            rep(k,N/12+2){
                if(6*i+8*j+12*k>=N){
                    ans = min(ans,S*i+M*j+L*k);
                }
            }
        }
    }
    cout << ans << endl;
}