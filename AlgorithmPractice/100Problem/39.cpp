#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    ll dp[N+1][21];
    ll Final = 0;
    rep(i,N-1){
        cin >> A[i];
    }cin >> Final;
    repp(i,0,N){
        rep(j,21){
            dp[i][j] = 0;
        }
    }
    dp[0][A[0]] = 1;
    repp(i,1,N-2){
        rep(j,21){
            if(j-A[i] > 0){
                dp[i][j] += dp[i-1][j-A[i]];
            }
            if(j+A[i] <= 20){
                dp[i][j] += dp[i-1][j+A[i]];
            }
        }
    }
    rep(i,N-1){
        rep(j,21){
            cout << dp[i][j] << " ";
        }cout << endl;
    }

    cout << dp[N-1][Final] << endl;
}