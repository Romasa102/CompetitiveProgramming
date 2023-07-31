#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll X,Y,Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;
    ll dp[2][S.size()];
    if(S[0] == 'a'){
        dp[0][0] = X;
        dp[1][0] = Y + Z;
    }else{
        dp[0][0] = Y;
        dp[1][0] = X + Z;
    }
    rep(i,S.size()-1){
        if(S[i+1] == 'a'){
            dp[0][i+1] = min(dp[0][i] + X,dp[1][i] + Z + X);
            dp[1][i+1] = min(dp[0][i] + Z + Y,dp[1][i] + Y);
        }else{
            dp[0][i+1] = min(dp[0][i] + Y,dp[1][i] + Z + Y);
            dp[1][i+1] = min(dp[0][i] + Z + X,dp[1][i] + X);
        }
    }
    cout << min(dp[0][S.size()-1],dp[1][S.size()-1]) << endl;
}