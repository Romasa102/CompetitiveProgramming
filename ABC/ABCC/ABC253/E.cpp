#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    ll O[N+1][M];
    rep(i,M){
        O[0][i] = 1;
    }
    rep(i,N-1){
        rep(j,M-K){
            rep(k,M-j-K){
                O[i+1][j+K+k]+=O[i][j];
                O[i+1][j+K+k]%=998244353;
            }
        }
    }
    ll ans = 0;
    rep(i,M){
        ans += O[N][i]%998244353;
        ans%=998244353;
    }
    cout << ans << endl;
}