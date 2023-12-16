#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll K,N;//K,N<3001
    cin >> K >> N;
    ll A[N];//<10^9
    rep(i,N){
        cin >> A[i];
    }
    ll dp[N][K][K];
    rep(i,N)rep(j,N)rep(k,N)dp[i][j][k]=0;
    rep(i,N){
        rep(j,K){//one before
            rep(k,K){//two before
                dp[i][j][k]=(dp[i-1][j-1][k-1]);
            }
        }
    }
}