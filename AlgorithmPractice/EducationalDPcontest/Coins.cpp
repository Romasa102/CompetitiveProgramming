#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    double p[N];
    rep(i,N)cin >> p[i];
    double dp[N+1][N+1];
    rep(i,N)rep(j,N+1)dp[j][i]=0;
    dp[0][0] = 1-p[0];//ura
    dp[1][0] = p[0];//omote
    repp(i,1,N){
        rep(j,N+1){
            if(j==0){
                dp[j][i] = dp[j][i-1]*(1-p[i]);
                continue;
            }
            dp[j][i] = dp[j-1][i-1]*p[i] + dp[j][i-1] * (1-p[i]);//the possibility of getting j number of thing flipped
        }
    }
    double ans = 0;
    repp(i,(N+1)/2,N+1){
        ans += dp[i][N-1];
    }
    cout << fixed << setprecision(11) << ans << endl;
}