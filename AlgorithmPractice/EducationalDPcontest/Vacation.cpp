#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll a[N],b[N],c[N];
    rep(i,N)cin>>a[i]>>b[i]>>c[i];
    ll dp[N][3];//0 a1, 1 a2, 2 b1, 3 b2, 4 c1, 5 c2
    dp[0][0]=a[0];dp[0][1]=b[0];dp[0][2]=c[0];
    repp(i,1,N){
        dp[i][0]=max({dp[i-1][1],dp[i-1][2]})+a[i];
        dp[i][1]=max({dp[i-1][0],dp[i-1][2]})+b[i];
        dp[i][2]=max({dp[i-1][1],dp[i-1][0]})+c[i];
    }
    ll ans = 0;
    rep(i,3){
        ans = max(ans,dp[N-1][i]);
    }
    cout << ans << endl;
}