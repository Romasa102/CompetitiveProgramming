#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
const ll MOD = 1e9+7;
int main(){
    string K;
    ll D;
    cin >> K >> D;
    ll dp[K.size()+1][2][D]; // from top how many, whether its smaller than K or not, mod D
    rep(i,K.size()+1)rep(j,2)rep(k,D)dp[i][j][k]=0;
    dp[0][0][0]=1;
    rep(i,K.size()){
        rep(j,D){
            rep(k,10){
                dp[i+1][1][(j+k)%D] += dp[i][1][j];
                dp[i+1][1][(j+k)%D]%=MOD;
                if(k < K[i]-'0'){
                    dp[i+1][1][(j+k)%D] += dp[i][0][j]; //if its 1 its guranteed that it is less
                    dp[i+1][1][(j+k)%D]%=MOD;
                }
                if(k==K[i]-'0'){
                    dp[i+1][0][(j+k)%D]+=dp[i][0][j];
                    dp[i+1][0][(j+k)%D]%=MOD;
                }
            }
        }
    }
    cout << (dp[K.size()][0][0] + dp[K.size()][1][0] -1 + MOD)%MOD << endl;
}