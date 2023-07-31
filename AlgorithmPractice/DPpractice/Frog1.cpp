#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    int h[N];
    int dp[N];
    rep(i,N){
        cin >> h[i];
        dp[i] = 0;
    }
    rep(i,N-1){
        if(i==0){
            dp[1] = dp[i]+abs(h[i]-h[1]);
        }
        dp[i+1] = min(dp[i]+abs(h[i+1]-h[i]),dp[i-1]+abs(h[i-1]-h[i+1]));
    }
    cout << dp[N-1] << endl;
}