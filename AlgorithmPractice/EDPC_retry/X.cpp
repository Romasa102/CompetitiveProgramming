#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin >> N;
    ll w[N],s[N],v[N];
    rep(i,N)cin >> w[i] >> s[i] >> v[i];
    vector<vector<ll>> dp(N,vector<ll>(11000,0));
    vector<tuple<ll,ll,ll,ll>> tp;
    rep(i,N){
        tp.push_back({s[i]+w[i],w[i],s[i],v[i]});
    }
    sort(tp.begin(),tp.end(),greater<tuple<ll,ll,ll,ll>>());
    dp[0][get<2>(tp[0])]=get<3>(tp[0]);
    repp(i,1,N){
        dp[i][get<2>(tp[i])] = get<3>(tp[i]);
        rep(j,11000){ // old capacity
            dp[i][j]=max(dp[i-1][j],dp[i][j]);
            if(get<1>(tp[i]) > j){
                continue;
            }
            ll curCap = get<2>(tp[i]);
            ll oldCap = j - get<1>(tp[i]);
            ll newCap = min(curCap,oldCap);
            dp[i][newCap] = max(dp[i][newCap],dp[i-1][j] + get<3>(tp[i]));
        }
    }
    ll ans = 0;
    /*rep(i,N){
        cout <<"weight: " <<get<1>(tp[i]) << " cap: " << get<2>(tp[i]) << " val: "<< get<3>(tp[i])<<endl;
    }
    rep(i,N){
        rep(j,30){
            cout << dp[i][j] << " ";
        }cout << endl;
    }*/
    rep(i,11000){
        ans = max(ans,dp[N-1][i]);
    }
    cout << ans << endl;
}