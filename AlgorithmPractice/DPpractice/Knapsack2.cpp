#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,W;
    cin >> N >> W;
    ll w[N+1];
    ll v[N+1];
    rep(i,0,N){
        ll a,b;
        cin >> a >>b;
        w[i+1] = a;
        v[i+1] = b;
        }
    ll dp[N+1][100001]; 
    dp[0][0] = 0;
    rep(i,1,100001){
        dp[0][i] = 2000000000;
    }
    ll ans = 0;
    rep(i,1,N+1)rep(j,0,100001){
        if(v[i]>j){
            dp[i][j] = dp[i-1][j];
        }else{
            dp[i][j] = min(dp[i-1][j],dp[i-1][j-v[i]] + w[i]);
        }
    }ans = 100000;
    while(dp[N][ans]>W){
        ans--;
    }
    cout << ans << endl;
}