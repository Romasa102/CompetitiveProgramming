#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N){
        cin >> A[i];
    }
    ll dp[N];
    rep(i,N){
        dp[i] = 1;
        rep(j,i){
            if(A[i] > A[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    ll ans = 0;
    rep(i,N){
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
}