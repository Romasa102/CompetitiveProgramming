#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
#define rrep(i,n) for(ll i = (n); i > 0; --i)
using P = pair<ll,ll>;
int main(){
    ll N,H;
    cin >> N >> H;
    ll X[N];
    rep(i,N){
        cin >> X[i];
    }
    ll P[N],F[N];
    rep(i,N-1){
        cin >> P[i] >> F[i];
    }
    ll dp[N][H];
    repp(i,1,N){
        ll dist = X[i]-X[i-1];
        rrep(j,H){
            dp[i][j] = dp[i-1][dist+j];
        }
    }
}