#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,T,S;
    cin >> N >> T >> S;
    ll A[N],B[N];
    rep(i,N){
        cin >> A[i] >> B[i];
    }
    ll dp[N+1][T+1];
    rep(i,N+1){
        rep(j,T+1){
            dp[i][j] = 0;
        }
    }
    repp(i,1,N+1){
        repp(j,1,T+1){
            if(j < B[i-1] ||  (j > S && j-B[i-1] < S)){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - B[i - 1]] + A[i - 1]);
            }
        }
    }
    ll maxN = 0;
    rep(i,N+1){
        rep(j,T+1){
            maxN = max(maxN,dp[i][j]);
        }
    }
    cout << maxN << endl;
}