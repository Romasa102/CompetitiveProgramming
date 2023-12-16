#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll s[N];
    rep(i,N)cin >> s[i];
    ll dp[N+1][100*N];
    rep(i,N+1){
        rep(j,100*N){
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    rep(i,N){
        rep(j,100*N){
            dp[i+1][j+s[i]]+=dp[i][j];
            dp[i+1][j]+=dp[i][j];
        }
    }
    ll ans = 0;
    rep(i,100*N){
        if(dp[N][i]!=0 && i %10 !=0){
            ans = max(ans,i);
        }
    }
    cout << ans << endl;
}