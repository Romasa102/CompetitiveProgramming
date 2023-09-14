#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,D;
    cin >> N >> D;
    ll price[D][N];
    rep(i,D){
        rep(j,N){
            cin >> price[i][j];
        }
    }
    ll dp[D+1][N+1][3];
    rep(i,D+1){
        rep(j,N+1){
            dp[i][j][0] = 1LL<<32;
            dp[i][j][1] = 1LL<<32;
            dp[i][j][2] = 1LL<<32;
        }
    }
    dp[0][0][0] = 0;
    ll smallestN = 0;
    ll smallestB = 0;
    repp(i,1,D+1){
        smallestN = smallestB;
        smallestB = 1LL<<32;
        repp(j,1,N+1){
            dp[i][j][0] = smallestN + price[i-1][j-1];
            dp[i][j][1] = dp[i-1][j][0] + (price[i-1][j-1] * 0.9);
            dp[i][j][2] = min(dp[i-1][j][2] + (price[i-1][j-1] * 0.7),dp[i-1][j][1] + (price[i-1][j-1] * 0.7));
            smallestB = min({smallestB,dp[i][j][0],dp[i][j][1],dp[i][j][2]});
        }
    }
    cout << smallestB << endl;
}