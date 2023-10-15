#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    ll MOD = 1000000007;
    ll dp[S.size()+1][8];
    rep(i,S.size()+1){
        rep(j,8){
            dp[i][j] = 0;
        }
    }
    if(S[0] == 'c')dp[0][0] = 1;
    repp(i,1,S.size()+1){
        rep(j,8){
            dp[i][j] = dp[i-1][j];
        }
        if(S[i] == 'c'){
            dp[i][0]++;
            dp[i][0]%=MOD;
        }
        if(S[i] == 'h'){
            dp[i][1] += dp[i-1][0];
            dp[i][1]%=MOD;
        }
        if(S[i] == 'o'){
            dp[i][2] += dp[i-1][1];
            dp[i][2]%=MOD;
        }
        if(S[i] == 'k'){
            dp[i][3] += dp[i-1][2];
            dp[i][3]%=MOD;
        }
        if(S[i] == 'u'){
            dp[i][4] += dp[i-1][3];
            dp[i][4]%=MOD;
        }
        if(S[i] == 'd'){
            dp[i][5] += dp[i-1][4];
            dp[i][5]%=MOD;

        }
        if(S[i] == 'a'){
            dp[i][6] += dp[i-1][5];
            dp[i][6]%=MOD;
        }
        if(S[i] == 'i'){
            dp[i][7] += dp[i-1][6];
            dp[i][7]%=MOD;

        }
    }
    cout << dp[S.size()][7] << endl;
}