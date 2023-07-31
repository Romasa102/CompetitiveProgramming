#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,W;
    cin >> N >> W;
    vector<P> wv(N+1);
    rep(i,0,N){
        ll a,b;
        cin >> a >>b;
        wv[i+1].first = a;
        wv[i+1].second = b;
        }
    ll dp[N+1][W+1]; 
    rep(i,0,N+1){
        rep(j,0,W+1){
            dp[i][j] = 0;
        }
    }
    rep(i,1,N+1)rep(j,0,W+1){
	    if(j-wv[i].first>=0)dp[i][j]=max(dp[i-1][j],dp[i-1][j-wv[i].first]+wv[i].second);
	    else dp[i][j]=dp[i-1][j];
    }
    cout << dp[N][W] << endl;
}