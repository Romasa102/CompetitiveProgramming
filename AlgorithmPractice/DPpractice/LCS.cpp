#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,vector<char>>;
int main(){
    string s,t;
    cin >> s >> t;
    int dp[s.size()+1][t.size()+1];
    rep(i,0,s.size()+1){
        rep(j,0,t.size()+1){
            dp[i][j] = 0;
        }
    }
    rep(i,1,s.size()+1){
        rep(j,1,t.size()+1){
            if(s[i-1]==t[j-1]){
                dp[i][j] = max(max(dp[i-1][j-1]+1,dp[i-1][j]),dp[i][j-1]);
                
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    ll needC = dp[s.size()][t.size()];
    vector<char> ans;
    ll a = s.size();
    ll b = t.size();
    while(needC){
        if(dp[a-1][b]!=dp[a][b] &&dp[a][b-1]!=dp[a][b]){
            ans.push_back(s[a-1]);
            needC--;
            a--;
            b--;
        }
        if(dp[a-1][b] == dp[a][b]){
            a--;
        }
        if(dp[a][b-1] == dp[a][b]){
            b--;
        }
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i];
    }cout << endl;
}