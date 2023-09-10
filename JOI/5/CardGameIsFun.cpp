#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll A,B;
    cin >> A >> B;
    ll ACard[A];
    ll BCard[B];
    rep(i,A){
        cin >> ACard[i];
    }
    int dp[B+1][A+1];
    rep(i,B){
        cin >> BCard[i];
    }
    rep(i,B+1){
        rep(j,A+1){
            dp[i][j] = 0;
        }
    }
    int ans = 0;
    repp(i,1,B+1){
        repp(j,1,A+1){
            if(BCard[i-1] == ACard[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans,dp[i][j]);
            }
            dp[i][j] = max(dp[i][j],dp[i][j-1]);
        }
    }
    cout << ans << endl;
}