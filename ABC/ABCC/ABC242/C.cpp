#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll dp[9];
    ll dp1[9];
    bool now = false;
    rep(i,9){
        dp[i] = 1;
    }
    rep(i,N - 1){
        if(!now){
            now = true;
        }else{
            now = false;
        }
        rep(j,9){
            if(now){
                if(j > 0 && j < 8){
                    dp1[j] = (dp[j -1] + dp[j] + dp[j + 1])%998244353;
                }else if(j == 0){
                    dp1[j] = (dp[j] + dp[j + 1])%998244353;
                }else if(j == 8){
                    dp1[j] = (dp[j - 1] + dp[j])%998244353;
                }
            }
            if(!now){
                if(j > 0 && j < 8){
                    dp[j] = (dp1[j -1] + dp1[j] + dp1[j + 1])%998244353;
                }else if(j == 0){
                    dp[j] = (dp1[j] + dp1[j + 1])%998244353;
                }else if(j == 8){
                    dp[j] = (dp1[j - 1] + dp1[j])%998244353;
                }
            }
        }
    }
    ll ans = 0;
    rep(i,9){
        if(now){
            ans += dp1[i];
        }else{
            ans += dp[i];
        }
    }cout << ans%998244353 << endl;
}