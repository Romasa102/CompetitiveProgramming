#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,M,K,S,T,X;
    cin >> N >> M >> K >> S >> T >> X;
    vector<P> U(M);
    bool graph[N][N];
    ll dp[K + 1][N];
    rep(i,M){
        cin >> U[i].first >> U[i].second;
        graph[U[i].first][U[i].second] = true;
        graph[U[i].second][U[i].first] = true;
    }
    rep(i,K + 1){
        if(i == 0){
            dp[i][S]++;
        }else{
            rep(j,N){
                graph[dp[i - 1][j]];
            }
        }
    }
}