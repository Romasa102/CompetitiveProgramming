#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,W;
    cin >> N >> W;
    ll w[N],v[N];
    rep(i,N)cin >> w[i] >> v[i];
    ll dp[N+1][1000000];
    rep(i,N+1)rep(j,100100)dp[i][j]=1LL<<60;//minimum weight u can use to make the value j in i object
    dp[0][0]=0;
    ll ans = 0;
    repp(i,1,N+1)rep(j,100100){
        if(j-v[i-1]>=0){
            dp[i][j]=min({dp[i][j],dp[i-1][j-v[i-1]]+w[i-1],dp[i-1][j]});
        }else{
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
        }
        if(dp[i][j]<W){
            ans = max(ans,j+1);
        }
    }
    rep(i,N+1){
        rep(j,90){
            cout << dp[i][j] << " ";
        }cout << endl;
    }

    cout << ans << endl;
}