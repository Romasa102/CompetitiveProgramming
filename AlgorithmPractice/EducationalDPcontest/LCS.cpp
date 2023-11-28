#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string s,t;
    cin >> s >> t;
    ll dp[s.size()+1][t.size()+1];
    rep(i,s.size()+1)rep(j,t.size()+1)dp[i][j]=0;
    string ans;
    repp(i,1,s.size()+1){
        repp(j,1,t.size()+1){
            if(s[i-1]==t[j-1]){
                if(dp[i-1][j-1]+1>dp[i-1][j]&&dp[i-1][j-1]+1>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans += s[i-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << ans << endl;
}