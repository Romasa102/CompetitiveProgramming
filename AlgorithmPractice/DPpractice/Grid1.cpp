#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    string a[H+10];
    rep(i,H){
        cin >> a[i];
    }
    ll dp[H][W];
    rep(i,H){
        rep(j,W){
            dp[i][j] = 0;
        }
    }
    dp[0][0]=1;
    rep(i,H){
        rep(j,W){
            if(a[i][j] == '#') continue;
            if(i+1>H-1 && j-1>W-1) continue;
            if(a[i+1][j] == '.'){
                dp[i+1][j] = (dp[i+1][j]+dp[i][j])%1000000007;
            }
            if(a[i][j+1] == '.'){
                dp[i][j+1] = (dp[i][j+1]+dp[i][j])%1000000007;
            }
        }
    }
    cout << dp[H-1][W-1] << endl;
}