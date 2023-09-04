#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N, 0));
    rep(i, N) {
        for(int j = i + 1; j < N; j++) cin >> A[i][j];
    }
    ll dp[(1<<N)+100000];
    rep(i,(1<<N)-1){
        ll l = -1;
        rep(j,N){
            if((i>>j & 1) == false){
                l = j;
                break;
            }
        }
        rep(j,N){
            if((i>>j & 1) == false){
                ll NGroup = i | (1<<j) | (1<<l);
                dp[NGroup] = max(dp[NGroup],dp[i] + A[l][j]);
            }
        }
    }
    cout << dp[(1<<N)-1] << endl;
}