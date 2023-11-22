#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    string S[H];
    rep(i,H)cin >> S[i];
    ll horizontS[H];//Aoi's
    vector<ll> verticalS(W);//Aoi's
    ll total = 0;//Aoi's
    rep(i,H){
        ll cur =0;
        rep(j,W){
            if(S[i][j]=='#'){
                total++;
                cur++;
            }
        }
        horizontS[i]=cur;
    }
    rep(i,W){
        ll cur =0;
        rep(j,H){
            if(S[j][i]=='#'){
                cur++;
            }
        }
        verticalS[i]=cur;
    }
    rep(i,H){
        vector<ll> cash = verticalS;
        
    }
}