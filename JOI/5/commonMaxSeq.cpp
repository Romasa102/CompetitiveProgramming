#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string a,b;
    cin >> a >> b;
    ll dp[a.size()+1][b.size()+1];
    ll ans = 0;
    rep(i,static_cast<ll>(a.size()+1)){
        rep(j,static_cast<ll>(b.size()+1)){
            dp[i][j] = 0;
        }
    }
    repp(i,1,static_cast<ll>(a.size())+1){
        repp(j,1,static_cast<ll>(b.size())+1){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                ans = max(ans,dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    cout << ans << endl;
}