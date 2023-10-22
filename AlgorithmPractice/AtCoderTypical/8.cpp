#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll dp[7][N+1];
    rep(i,7){
        rep(j,N+1){
            dp[i][j]=0;
        }
    }
    repp(i,1,N+1){
        if(S[i-1]=='a'){
            dp[0][i]=dp[0][i-1]+1;
            dp[0][i]%=1000000007;
        }else{
            dp[0][i]=dp[0][i-1];
        }
        if(S[i-1]=='t'){
            dp[1][i]=dp[1][i-1]+dp[0][i-1];
            dp[1][i]%=1000000007;
        }else{
            dp[1][i]=dp[1][i-1];
        }
        if(S[i-1]=='c'){
            dp[2][i]=dp[2][i-1]+dp[1][i-1];
            dp[2][i]%=1000000007;
        }else{
            dp[2][i]=dp[2][i-1];
        }
        if(S[i-1]=='o'){
            dp[3][i]=dp[3][i-1]+dp[2][i-1];
            dp[3][i]%=1000000007;
        }else{
            dp[3][i]=dp[3][i-1];
        }
        if(S[i-1]=='d'){
            dp[4][i]=dp[4][i-1]+dp[3][i-1];
            dp[4][i]%=1000000007;
        }else{
            dp[4][i]=dp[4][i-1];
        }
        if(S[i-1]=='e'){
            dp[5][i]=dp[5][i-1]+dp[4][i-1];
            dp[5][i]%=1000000007;
        }else{
            dp[5][i]=dp[5][i-1];
        }
        if(S[i-1]=='r'){
            dp[6][i]=dp[6][i-1]+dp[5][i-1];
            dp[6][i]%=1000000007;
        }else{
            dp[6][i]=dp[6][i-1];
        }
    }
    cout << dp[6][N]%1000000007 << endl;
}