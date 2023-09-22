#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll M,N;//M is a number of the manju , N is a number of the manjuBox
    cin >> M >> N;
    ll P[M];
    ll C[N],E[N];
    rep(i,M) cin >> P[i];
    rep(i,N) cin >> C[i] >> E[i];//C = size E = price
    ll CountPrice[M+1];//cumulative sum of the price of the manju
    CountPrice[0] = 0;
    sort(P,P+M,greater<ll>());
    repp(i,1,M+1){
        CountPrice[i] = CountPrice[i-1] + P[i-1];
    }
    ll dp[M+1];
    rep(i,M+1)dp[i] = 2LL<<32;
    dp[0] = 0;
    rep(i,N){
        for(ll j=M; j >= 0; --j){
            dp[min(j+C[i], M)] = min(dp[min(j+C[i], M)],dp[j] + E[i]);
        }
    }
    ll ans = 0;
    rep(i,M){
        cout << CountPrice[i+1] << " " << dp[i+1] << " " << endl;
        ans = max(ans,CountPrice[i+1] - dp[i+1]);
        cout << ans << endl;
    }
    cout << ans << endl;
}