#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll NG[3];
    rep(i,3)cin >> NG[i];
    ll dp[101][N+1];
    rep(i,101)rep(j,N+1)dp[i][j]=0;
    dp[0][0]=1;
    rep(i,100){
        rep(j,N+1){
            rep(k,4){
                ll possible = true;
                if(j+k>N)continue;
                rep(o,3){
                    if(j+k==NG[o])possible=false;
                }
                if(possible)dp[i+1][j+k]+=dp[i][j];
            }
        }
    }
    if(dp[100][N]!=0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}