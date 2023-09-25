#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define rrep(i,n) for(ll i = (n); i >= 0; --i)
#define rrepp(i,o,n) for(ll i = (n); i >= o; --i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll Q,K;
    cin >> Q >> K;
    ll dp[K+1]; //dp[i] = pattern of making i;
    rep(i,K+1)dp[i]=0;
    dp[0] = 1;
    rep(i,Q){
        char as;
        ll x;
        cin >> as >> x;
        if(as == '+'){
            rrep(j,K-x){
                dp[j+x] += dp[j];
                dp[j+x]%=998244353;
            }
        }else{
            rep(j,K-x+1){
                dp[j+x]+=(998244353-dp[j]);
                dp[j+x] %=998244353;
            }

            //for(int j=x;j<=K;j++){
            //    dp[j]+=(998244353-dp[j-x]);
            //    dp[j]%=998244353;
            //}
        }
        cout << dp[K]%998244353 << endl;
    }
}