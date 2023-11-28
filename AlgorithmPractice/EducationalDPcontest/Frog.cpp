#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll h[N];
    rep(i,N)cin >> h[i];
    ll dp[N];
    rep(i,N)dp[i]=0;
    dp[1]=dp[0]+abs(h[1]-h[0]);
    repp(i,2,N){
        dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout << dp[N-1] << endl;
}