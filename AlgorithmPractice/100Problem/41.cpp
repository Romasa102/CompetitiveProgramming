#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll D,N; //<=200
    cin >> D >> N;
    ll Temp[D];
    rep(i,D){
        cin >> Temp[i];
    }
    ll a[N];
    ll b[N];
    ll c[N];
    rep(i,N){
        cin >> a[i] >> b[i] >> c[i];
    }
    ll dp[D][N];
    rep(i,D){
        rep(j,N){
            dp[i][j] = -1;
        }
    }
    rep(i,D){
        rep(j,N){
            if(a[j] <= Temp[i] && Temp[i] <= b[j]){
                dp[i][j] = 0;
            }
        }
    }
    repp(i,1,D){
        rep(j,N){
            if(dp[i][j] == -1)continue;
            rep(k,N) {
                if (dp[i - 1][k] == -1) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(c[j] - c[k]));
            }
        }
    }
    rep(i,D){
        rep(j,N){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    ll ans = 0;
    rep(i,N){
        ans = max(ans,dp[D-1][i]);
    }
    cout << ans << endl;
}