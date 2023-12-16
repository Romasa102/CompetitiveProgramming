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
    vector<vector<ll>> genre(10);
    rep(i,N){
        cin >> C[i] >> G[i];
        genre[G[i]-1].push_back(C[i]);
    }
    rep(i,10){
        sort(genre[i].begin(),genre[i].end(),greater<ll>());
    }
    vector<vector<ll>> genreS(10);
    rep(i,10){
        if(genre[i].empty())continue;
        genreS[i].push_back(genre[i][0]);
        repp(j,1,min(K,(ll)genre[i].size())){
            genreS[i].push_back(genre[i][j]+genreS[i][j-1]);
        }
        rep(j,min(K,(ll)genre[i].size())){
            genreS[i][j]+=j*(j+1);
        }
    }
    ll dp[10][K+1];
    rep(i,10)rep(j,K+1)dp[i][j]=0;
    rep(j,K){
        if(j>=genreS[0].size())break;
        dp[0][j+1]=genreS[0][j];
    }
    repp(i,1,10){
        rep(j,K+1){
            rep(k,min((ll)genreS[i].size(),j)){
                dp[i][j]=max(dp[i][j],dp[i-1][j-k-1]+genreS[i][k]);
            }
            dp[i][j]=max(dp[i-1][j],dp[i][j]);
        }
    }
    cout << dp[9][K] << endl;
}