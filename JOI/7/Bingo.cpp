#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,S;
    cin >> N >> M >> S;
    //N < 7
    //M is maximum number possible < 2000
    //Total sum < 3000
    //must be some kind of dp
    //dont have to care about the order.
    ll dp[N*N+1][S+1];//number of pattern to choose i number under M and make j
    rep(i,N*N+1)rep(j,S+1)dp[i][j]=0;
    dp[0][0]=1;
    repp(i,1,M+1){
        //max current value is i
        for(ll j= N*N;j>0;j--){
            rep(k,S+1){
                if(k-i<0)continue;
                dp[j][k]+=dp[j-1][k-i];//number of pattern when the sum of the num til j is k
                dp[j][k]%=100000;
            }
        }
    }
    cout << dp[N*N][S] << endl;
}