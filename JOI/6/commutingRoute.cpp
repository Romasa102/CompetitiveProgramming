#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll ans = 0;
ll w,h;
int main(){
    cin >> w >> h;
    ll dp[w+1][h+1][2][2];
    rep(i,w+1){
        rep(j,h+1){
            rep(k,2){
                rep(l,2){
                    dp[i][j][k][l] = 0;
                }
            }
        }
    }
    dp[0][1][0][0] = 1;
    dp[1][0][1][0] = 1;
    repp(i,1,w+1){
        repp(j,1,h+1){
            dp[i][j][0][0] += dp[i][j-1][0][0]+dp[i][j-1][0][1];
            dp[i][j][1][0] += dp[i-1][j][1][0]+dp[i-1][j][1][1];
            dp[i][j][0][1] += dp[i][j-1][1][0];
            dp[i][j][1][1] += dp[i-1][j][0][0];

            dp[i][j][0][0] %= 100000;
            dp[i][j][1][0] %= 100000;
            dp[i][j][0][1] %= 100000;
            dp[i][j][1][1] %= 100000;
        }
    }
    cout << (dp[w][h][0][0]+dp[w][h][0][1]+dp[w][h][1][0]+dp[w][h][1][1])%100000 << endl;
}