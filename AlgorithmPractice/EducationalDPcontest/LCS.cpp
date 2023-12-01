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
    ll cur = 0;
    repp(i,1,s.size()+1){
        repp(j,1,t.size()+1){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>cur){
                    cur = dp[i][j];
                }
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    ll need = dp[s.size()][t.size()];
    ll i  = s.size();
    ll j = t.size();
    while(need > 0){
            while(dp[i-1][j-1]==dp[i][j]){
                i--;
                j--;
            }
            while (dp[i][j]==dp[i-1][j]){
                i--;
            }
            while (dp[i][j]==dp[i][j-1]){
                j--;
            }
            ans += s[i-1];
            need--;
            i--;
            j--;
    }
    rep(k,ans.size()){
        cout << ans[ans.size()-k-1];
    }cout << endl;
}