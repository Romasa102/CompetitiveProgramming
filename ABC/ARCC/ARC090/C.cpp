#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll dp[2][N];
    ll A[2][N];
    rep(i,2){
        rep(j,N){
            cin >> A[i][j];
            dp[i][j]=0;
        }
    }
    ll ans = A[0][0];
    rep(i,2){
        rep(j,N){
            if(i==0){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+A[i+1][j]);
            }
            if(j!=N-1){
                dp[i][j+1]=max(dp[i][j+1],dp[i][j]+A[i][j+1]);
            }
        }
    }
    cout << ans + dp[1][N-1] << endl;
}