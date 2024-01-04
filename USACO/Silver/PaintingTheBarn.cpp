#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);
    ll N,K;
    cin >>  N >> K;
    vector<vector<ll>> preS(1200,vector<ll>(1200,0));
    rep(i,N){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        preS[x1][y1]++;
        preS[x1][y2]--;
        preS[x2][y1]--;
        preS[x2][y2]++;
    }
    rep(i,1200){
        repp(j,1,1200){
            preS[i][j]+=preS[i][j-1];
        }
    }
    rep(j,1200){
        repp(i,1,1200){
            preS[i][j]+=preS[i-1][j];
        }
    }
    ll ans = 0;
    rep(i,1200){
        rep(j,1200){
            if(preS[i][j]==K){
                ans++;
            }
        }
    }
    cout << ans << endl;
}