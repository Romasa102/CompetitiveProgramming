#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll D[N],C[N],S[N];
    ll dp[6000][N+10];
    rep(i,N){
        cin >> D[i] >> C[i] >> S[i];
    }
    ll ans = 0;
    rep(i,6000){
        rep(j,N+1){
            dp[i][j]=0;
        }
    }
    rep(i,5000){
        rep(j,N){
            if(i+C[j] <= D[j]){
                dp[i+C[j]][j+1] = max(dp[i+C[j]][j+1],dp[i][j]+S[j]);
            }
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(j>0){
                dp[i+1][j]=max(dp[i+1][j],dp[i+1][j-1]);
            }
        }
    }
    rep(i,5000){
        rep(j,N+1){
            ans = max(ans,dp[i][j]);
        }
    }
    rep(i,20){
        rep(j,N+1){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    cout << ans << endl;
}