#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    ll JOI[H][W];
    rep(i,H){
        rep(j,W){
            cin >> JOI[i][j];
        }
    }
    vector<vector<ll>> xAxis(H,vector<ll>(3,0));
    vector<vector<ll>> yAxis(W,vector<ll>(3,0));
    ll ans = 0;
    rep(i,H){
        rep(j,W){
            if(JOI[i][j] == 0){
                xAxis[i][0]++;
                yAxis[j][0]++;
            }else if(JOI[i][j] == 1){
                xAxis[i][1]++;
                yAxis[j][1]++;
            }else{
                xAxis[i][2]++;
                yAxis[j][2]++;
            }
        }
    }
    rep(i,H){
        rep(j,W){
            if(JOI[i][j] == 0){
                ans += xAxis[i][2] * yAxis[j][1];
                ans += xAxis[i][1] * yAxis[j][2];
            }else if(JOI[i][j] == 1){
                ans += xAxis[i][2] * yAxis[j][0];
                ans += xAxis[i][0] * yAxis[j][2];
            }else{
                ans += xAxis[i][0] * yAxis[j][1];
                ans += xAxis[i][1] * yAxis[j][0];
            }
        }
    }
    cout << ans /2 << endl;
}