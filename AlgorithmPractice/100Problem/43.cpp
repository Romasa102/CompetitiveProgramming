#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string S[5];
    rep(i,5){
        cin >> S[i];
    }
    ll dp[N][3];
    ll turnToR[N];
    ll turnToB[N];
    ll turnToW[N];
    rep(i,N){
        ll redC = 0;
        ll blueC = 0;
        ll whiteC = 0;
        ll blackC = 0;
        rep(j,5){
            if(S[j][i] == 'R')redC++;
            if(S[j][i] == 'B')blueC++;
            if(S[j][i] == 'W')whiteC++;
            if(S[j][i] == '#')blackC++;
        }
        turnToR[i] = blueC+whiteC+blackC;
        turnToB[i] = redC+whiteC+blackC;
        turnToW[i] = redC+blueC+blackC;
        cout << redC << blueC <<whiteC <<blackC <<endl;
    }
    rep(i,N){
        rep(j,3){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = turnToR[0];
    dp[0][1] = turnToB[0];
    dp[0][2] = turnToW[0];
    repp(i,1,N){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + turnToR[i];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + turnToB[i];
        dp[i][2] = min(dp[i-1][1],dp[i-1][0]) + turnToW[i];
    }
    cout << min({dp[N-1][0],dp[N-1][1],dp[N-1][2]}) << endl;
}