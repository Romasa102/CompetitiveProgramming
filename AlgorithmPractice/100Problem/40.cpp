#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll A[K];
    ll B[K];
    map<ll,ll> locked;
    ll dp[N][7]; //0 nothing 1 2 3 4:continuous1 5: continuous2 6:continuous3
    rep(i,K){
        cin >> A[i] >> B[i];
        locked[A[i]-1] = B[i];
    }
    rep(i,N){
        rep(j,7){
            dp[i][j] = 0;
        }
    }
    if(locked.find(0) == locked.end()){
        dp[0][1] = 1;
        dp[0][2] = 1;
        dp[0][3] = 1;
    }else{
        dp[0][locked[0]] = 1;
    }
    repp(i,1,N){
        if(locked.find(i)==locked.end()){
            dp[i][1] = (dp[i-1][2] + dp[i-1][3] + dp[i-1][5] + dp[i-1][6])%10000;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + dp[i-1][6])%10000;
            dp[i][3] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][5] + dp[i-1][4])%10000;
            dp[i][4] = dp[i-1][1];
            dp[i][5] = dp[i-1][2];
            dp[i][6] = dp[i-1][3];
        }else{
            if(locked[i] == 1) dp[i][locked[i]] = (dp[i-1][2] + dp[i-1][3] + dp[i-1][5] + dp[i-1][6])%10000;
            if(locked[i] == 2) dp[i][locked[i]] = (dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + dp[i-1][6])%10000;
            if(locked[i] == 3) dp[i][locked[i]] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][5] + dp[i-1][4])%10000;
            dp[i][locked[i] + 3] = dp[i-1][locked[i]]%10000;
        }
    }
    ll ans = 0;
    repp(i,1,7){
        ans += dp[N-1][i];
    }
    cout << ans % 10000 << endl;
}