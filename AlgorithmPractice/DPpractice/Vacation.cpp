#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> b(N);
    vector<ll> c(N);
    rep(i,N){
        cin >> a[i] >> b[i] >> c[i];
    }
    ll dp[3][N];
    rep(i,3){
        rep(j,N){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = a[0];
    dp[1][0] = b[0];
    dp[2][0] = c[0]; 
    for(int i = 1;i < N;i++){
        dp[0][i] = max(dp[1][i-1] + a[i],dp[2][i-1] + a[i]);
        dp[1][i] = max(dp[0][i-1] + b[i],dp[2][i-1] + b[i]);
        dp[2][i] = max(dp[1][i-1] + c[i],dp[0][i-1] + c[i]);
    }
    cout << max({dp[0][N-1],dp[1][N-1],dp[2][N-1]}) << endl;
}