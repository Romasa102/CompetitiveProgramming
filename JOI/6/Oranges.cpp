#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    ll A[N];
    rep(i,N)cin >> A[i];
    ll dp[N+1];
    rep(i,N+1)dp[i]=1LL<<40;
    dp[0] = 0;
    repp(i,1,N+1){
        ll minN = 1LL<<40;
        ll maxN = 0;
        rep(j,min(M,i)){
            minN = min(minN,A[i-j-1]);
            maxN = max(maxN,A[i-j-1]);
            dp[i] = min(dp[i],dp[i-j-1] + K + (j+1) * abs(maxN-minN));
        }
    }
    cout << dp[N] << endl;
}