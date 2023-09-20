#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string s;
    cin >> N >> s;
    ll dp[N+1][8];
    rep(i,N+1){
        rep(j,8){
            dp[i][j] = 0;
        }
    }
    dp[0][1] = 1;
    dp[0][3] = 1;
    dp[0][5] = 1;
    dp[0][7] = 1;
    repp(i,1,N+1){
        if(s[i] == 'J'){
            dp[i][1] = dp[i-1][1];//J
            dp[i][3] = dp[i-1][3] + dp[i-1][1] + dp[i-1][2];//JO
            dp[i][5] = dp[i-1][5] + dp[i-1][1] + dp[i-1][4];//JI
            dp[i][7] = dp[i-1][7] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5] + dp[i-1][6];//JOI
        }else if(s[i] == 'O'){
            dp[i][2] = dp[i-1][2];//O
            dp[i][3] = dp[i-1][3] + dp[i-1][1] + dp[i-1][2];//JO
            dp[i][6] = dp[i-1][6] + dp[i-1][2] + dp[i-1][4];//OI
            dp[i][7] = dp[i-1][7] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5] + dp[i-1][6];//JOI
        }else{
            dp[i][4] = dp[i-1][4];//I
            dp[i][5] = dp[i-1][5] + dp[i-1][1] + dp[i-1][4];//JI
            dp[i][6] = dp[i-1][6] + dp[i-1][2] + dp[i-1][4];//OI
            dp[i][7] = dp[i-1][7] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5] + dp[i-1][6];//JOI
        }
    }
    ll ans = 0;

    rep(i,N+1){
        rep(j,8){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    rep(i,8){
        ans += dp[N][i];
    }cout << ans << endl;
}