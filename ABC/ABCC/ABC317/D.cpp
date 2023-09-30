#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll X[N],Y[N],Z[N];
    ll Aoki = 0;
    ll Takahashi = 0;
    vector<P> Change;
    rep(i,N){
        cin >> X[i] >> Y[i] >> Z[i];
        if(X[i] < Y[i]){
            Aoki+=Z[i];
            Change.push_back({(X[i]+Y[i]+1)/2-X[i],Z[i]});
        }else{
            Takahashi+=Z[i];
        }
    }
    if(Takahashi>Aoki){
        cout << 0 << endl;
        return 0;
    }
    ll need = ((Aoki + Takahashi + 1)/2) - Takahashi;
    ll dp[Change.size()+1][100010];
    rep(i,Change.size()+1){
        rep(j,100010){
            dp[i][j] = 1LL<<40;
        }
    }
    dp[0][0] = 0;
    ll ans = 1LL<<40;
    rep(i,Change.size()){
        rep(j,100010){
            if(j >= Change[i].second){
                dp[i+1][j] = min(dp[i][j],dp[i][j-Change[i].second]+Change[i].first);
            }else{
                dp[i+1][j] = dp[i][j];
            }
            if(j>=need){
                ans = min(ans,dp[i+1][j]);
            }
        }
    }
    cout << ans << endl;
}