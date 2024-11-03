#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;cin >> N >> M;
    ll A[M],B[M],X[M];rep(i,M)cin >> A[i] >> B[i] >> X[i];
    vector<vector<bool>> visited(N,vector<bool>(N,false));
    vector<vector<ll>> W(N,vector<ll>(N,0));
    rep(i,M){
        W[A[i]-1][B[i]-1]=X[i]+1;
    }
    rep(i,N-1){
        rep(j,N){
            if(j>i)continue;
            W[i+1][j] = max(W[i+1][j],W[i][j]-1);
            W[i+1][j+1] = max(W[i+1][j+1],W[i][j]-1);
        }
    }
    ll ans= 0;
    rep(i,N){
        rep(j,N){
            if(j>i)continue;
            if(W[i][j] != 0)ans++;
        }
    }
    cout << ans << endl;
}
