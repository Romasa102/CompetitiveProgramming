#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll m,n;
    cin >> m >> n;
    ll a,b;
    cin >> a >> b;
    ll c[n][m];

    rep(i,n){
        rep(j,m){
            cin >> c[i][j];
            if(c[i][j] == -1){
                c[i][j] = 100000000;
            }
        }
    }
    ll Csum[n+1][m+1];
    rep(i,n+1){
        rep(j,m+1){
            Csum[i][j] = 0;
        }}
    Csum[0][0] = 0;
    rep(i,n){
        rep(j,m){
            Csum[i+1][j+1] = Csum[i+1][j] + Csum[i][j+1] + c[i][j] - Csum[i][j];
        }
    }
    ll ans = 1LL<<35;
    rep(i,n-b+1){
        rep(j,m-a+1){
            ans = min(ans,Csum[i+b][j+a] - Csum[i+b][j] - Csum[i][j+a] + Csum[i][j]);
        }
    }
    cout << ans << endl;
}