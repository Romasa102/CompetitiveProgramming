#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,m;
    cin >> n >> m;
    ll c[m];
    rep(i,m){
        cin >> c[i];
    }
    ll dp[m+1][n+1];
    rep(i,m+1){
        rep(j,n+1){
            dp[i][j] = 60000;
        }
    }
    repp(i,1,m+1){
        rep(j,n+1){
            if(j == c[i-1]) {
                dp[i][j] = 1;
                continue;
            }
            if(j-c[i-1] < 0) {
                dp[i][j] = min(dp[i][j],dp[i-1][j]);
            }
            else {
                dp[i][j] = min(dp[i-1][j],dp[i][j-c[i-1]] + 1);
            }
        }
    }
    cout << dp[m][n] << endl;
}