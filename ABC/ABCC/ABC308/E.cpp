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
    rep(i,N)cin >> A[i];
    string S;
    cin >> S;
    ll dp[N][3][8];//0
    rep(i,N)rep(j,3)rep(k,3)dp[i][j][k]=0;
    repp(i,1,N+1){
        if(S[i-1] == 'M'){
                dp[i][0][1<<A[i]] = dp[i-1][0][1<<A[i]];
        }else if(S[i-1] == 'E'){
            for(int j:{1,2,4}){
                dp[i][1][j&(1<<A[i])] += dp[i][1][j];
            }
        }else{
            for(int j:{1,2,3,4,5,6}){
                dp[i][2][j&(1<<A[i])] += dp[i][1][j];
            }
        }
    }
    ll ans = 0;
    ans += dp[N][2][1] * 1;
    ans += dp[N][2][3] * 2;
    ans += dp[N][2][5] * 1;
    ans += dp[N][2][7] * 3;
    cout << ans << endl;
}