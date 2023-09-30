#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N)cin >> A[i];
    string S;
    cin >> S;
    ll dp[N+1][3][8];//0
    rep(i,N+1)rep(j,3)rep(k,8)dp[i][j][k]=0;
    repp(i,1,N+1){
        if(S[i-1] == 'M'){
            rep(j,8){
                dp[i][0][j] = dp[i-1][0][j];
            }
            dp[i][0][1<<A[i-1]] = dp[i-1][0][1<<A[i-1]]+1;
        }else{
            rep(j,8){
                dp[i][0][j] = dp[i-1][0][j];
            }
        }
        if(S[i-1] == 'E') {
            rep(j,8){
                dp[i][1][j] = dp[i-1][1][j];
            }
            for (int j: {1, 2, 4}) {
                cout << (j|(1<<A[i-1])) << endl;
                dp[i][1][j | (1 << A[i-1])] += dp[i-1][0][j];
            }
        }else{
            rep(j,8){
                dp[i][1][j] = dp[i-1][1][j];
            }
        }
        if(S[i-1] == 'X'){
            rep(j,8){
                dp[i][2][j] = dp[i-1][2][j];
            }
            for(int j:{1,2,3,4,5,6}){
                dp[i][2][j|(1<<A[i-1])] += dp[i-1][1][j];
            }
        }else{
            rep(j,8){
                dp[i][2][j] = dp[i-1][2][j];
            }
        }
    }
    rep(i,N+1){
        rep(j,3){
            rep(k,8){
                cout << dp[i][j][k] << " " ;
            }cout << endl;
        }cout << endl;
    }
    ll ans = 0;
    ans += dp[N][2][1] * 1;
    ans += dp[N][2][3] * 2;
    ans += dp[N][2][5] * 1;
    ans += dp[N][2][7] * 3;
    cout << ans << endl;
}