#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
double consta[5050];
double calc(double x,int k){
    double ans=x/consta[k]-(double)1200/sqrt((double)(k+1));
    return ans;
}
int main(){
    const double c=0.9;
    ll N;
    cin >> N;
    double Pn[N];
    rep(i,N)cin >> Pn[i];
    double dp[N][N];
    rep(i,N)rep(j,N)dp[i][j]=0;
    dp[0][0]=Pn[0];
    consta[0]=1;
    repp(i,1,N){
        consta[i]=consta[i-1]*c+1.0;
    }
    repp(i,1,N){
        rep(j,N){
            if(j<=0){
                if(calc(dp[i-1][j],j) > calc(Pn[i],j)){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=Pn[i];
                }
            }else{
                if(i==j){
                    dp[i][j] = dp[i-1][j-1]*c+Pn[i];
                }else{
                    if(calc(dp[i-1][j],j) > calc(dp[i-1][j-1]*c+Pn[i],j)){
                        dp[i][j] = dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j-1]*c+Pn[i];
                    }
                }
            }
        }
    }
    double ans=-1200.0;
    rep(j,N){
        ans = max(ans,calc(dp[N-1][j],j));
    }
    cout  << fixed << setprecision(10) << ans << endl;
}