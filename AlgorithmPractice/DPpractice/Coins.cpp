#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int N;
    cin >> N;
    double p[N+1];
    rep(i,0,N){
        cin >> p[i];
    }
    double dp[N+1][N+1];
    rep(i,0,N){
        dp[0][i] = 0;
    }
    dp[0][0] = 1;
    rep(i,1,N+1){
        rep(j,0,N+1){
            if(j>=1){
               dp[i][j] = dp[i-1][j]*(1-p[i-1])+dp[i-1][j-1]*p[i-1];        
            }else{
                dp[i][j] = dp[i-1][j]*(1-p[i-1]);
            }
        }
    }
    double ans = 0;
    rep(i,(N+2)/2,N+1){
        ans+= dp[N][i];
    }
    cout << fixed << setprecision(10) << ans << endl;
}
