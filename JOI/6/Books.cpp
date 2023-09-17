#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll C[N],G[N];
    vector<vector<ll>> P(10);
    rep(i,N){
        cin >> C[i] >> G[i];
        --G[i];
        P[G[i]].push_back(C[i]);
    }
    rep(i,10)sort(P[i].begin(),P[i].end(),greater<ll>());
    vector<vector<ll>> cost(10);
    rep(i,10){
        cost[i].assign(P[i].size() + 1,0);
        rep(j,P[i].size()){
            cost[i][j+1] = cost[i][j] + P[i][j];
        }
        rep(j, cost[i].size()){
            cost[i][j]+=(j-1)*j;
            cout << i << " " << j << "   " << cost[i][j] << endl;
        }
    }
    vector<vector<ll>> dp(11,vector<ll>(K+1,0));
    rep(i,10){
        rep(j,K+1){
            rep(k,cost[i].size()){
                if(j+k>K)break;
                dp[i+1][j+k] = max(dp[i+1][j+k],dp[i][j] + cost[i][k]);
            }
        }
    }
    cout << dp[10][K] << endl;
}