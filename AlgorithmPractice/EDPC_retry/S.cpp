#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
const ll MOD = 1000000007;
int main(){
    ll D;
    string K;
    cin >> K >> D;
    ll digitC = K.size();
    vector<vector<vector<vector<ll>>>> dp(digitC+1,
        vector<vector<vector<ll>>>(D,
            vector<vector<ll>>(10,
                vector<ll>(2,0))));
    //ll dp[digitC+1][D][10][2]; //digitNum 10^4, MOD 10^2, number used, less than
    //rep(i,digitC+1)rep(j,D)rep(k,10)rep(l,2)dp[i][j][k][l]=0;
    dp[0][0][0][0] = 1;
    dp[0][0][0][1] = 1;
    repp(i,1,digitC+1){ //10^4
        rep(j,D){ // MOD
            rep(k,10){ // number used at i-th digit
                rep(l,10){ //number used at (i-1)th digit
                    if(k <= K[digitC-i]-'0'){
                        dp[i][j][k][1] += dp[i-1][(j-k+10 * D)%D][l][0];
                        dp[i][j][k][1] %= MOD;
                    }
                    //cout << "taking from address" << (j-k+D*10)%D << endl;
                    dp[i][j][k][0] += dp[i-1][(j-k+10*D)%D][l][0];
                    dp[i][j][k][0] %= MOD;
                    //cout << "new num for "<< i << "th digit with MOD: " << j << " and number used is" << k << " is" << dp[i][j][k][0] << endl;;
                }
                //cout << "dp for 1 in" << k << "th num is :" << dp[i][0][k][1] << endl;
            }
        }
    }
    ll ans = 0;
    ll digitRn = 0;
    //cout << "loop will go " << K[0]-'0' << "times" << endl;
    while(digitRn < K[0]-'0'){
        ans+= dp[digitC][0][digitRn][0];
        ans %= MOD;
        digitRn++;
        //cout << ans << endl;
    }
    ans += dp[digitC][0][digitRn][1];
    ans %= MOD;
    //cout << ans << endl;
    cout << ans % MOD -1 << endl;
}