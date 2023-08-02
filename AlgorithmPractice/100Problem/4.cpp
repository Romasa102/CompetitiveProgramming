#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    ll song[N][M];
    rep(i,N){
        rep(j,M){
            cin >> song[i][j];
        }
    }
    ll ans =0;
    rep(i,M){
        rep(j,M){
            if(i==j)continue;
            ll current_score = 0;
            rep(k,N){
                current_score+=max(song[k][i],song[k][j]);
            }
            ans = max(current_score,ans);
        }
    }
    cout << ans << endl;
}