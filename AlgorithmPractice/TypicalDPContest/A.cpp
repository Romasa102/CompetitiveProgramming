#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll p[N];
    rep(i,N)cin >> p[i];
    ll dp[N+2][N*100];
    rep(i,N+2){
        rep(j,N*100){
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    rep(i,N){
        rep(j,N*100){
            dp[i+1][j+p[i]]+=dp[i][j];
            dp[i+1][j]+=dp[i][j];
        }
    }
    ll ans = 0;
    rep(i,N*100){
        if(dp[N][i]!=0){
            ans++;
        }
    }
    cout << ans << endl;
}