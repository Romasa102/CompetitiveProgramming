#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
const ll MOD = 1e9 + 7;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll dp[N][N];
    rep(i,N)rep(j,N)dp[i][j]=0;
    dp[0][0]=1;
    repp(i,1,N){
        ll cur = 0;
        if(S[i-1]=='<'){
            rep(j,i+1){
                dp[i][j] += cur; //some number bigger or equal than j
                dp[i][j] %= MOD;
                cur += dp[i-1][j];
            }
        }else if(S[i-1]=='>'){
            for(int j = N-1; j >= 0; j--){
                cur += dp[i-1][j];
                dp[i][j] += cur; //some number bigger or equal than j
                dp[i][j] %= MOD;
            }
        }
    }
    ll ans = 0;
    rep(i,N){
        ans += dp[N-1][i];
        ans %= MOD;
    }
    /*
    rep(i,N){
        ll cur = 0;
        rep(j,N){
            cout << dp[i][j] << " ";
            cur += dp[i][j];
        }cout << "total was: " << cur << endl;
    }*/
    cout <<  ans % MOD << endl;
}