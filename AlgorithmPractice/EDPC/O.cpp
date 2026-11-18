#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
const ll MOD = 1000000007;
int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> a(N,vector<ll>(N));
    rep(i,N)rep(j,N)cin >> a[i][j];
    vector<vector<ll>> dp(N+1,vector<ll> (1<<N,0));
    dp[0][0]=1;
    rep(i,N){ //21
        rep(bits,1<<N){ // 10^6
            if(__builtin_popcount(bits) != i)continue;
            rep(cur,N){
                //if it isnt taken and its a good match push it.
                if(!(bits & (1<<cur)) && a[i][cur]){
                    //cout << "at " << i << "th num with bits : " << bits << "giving out to :" << cur << endl;
                    dp[i+1][bits + (1<<cur)]+=dp[i][bits];
                    dp[i+1][bits + (1<<cur)]%=MOD;
                }
            }
        }
    }
    cout << dp[N][(1<<N) - 1] << endl;
}