#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    ll K;
    cin >> N >> K;
    ll h[N];
    rep(i,N)cin >> h[i];
    ll dp[N];
    repp(i,1,N)dp[i]=1LL<<60;
    dp[0]=0;
    repp(i,1,N){
        rep(j,min(i,K)+1){
            dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    cout << dp[N-1] << endl;
}