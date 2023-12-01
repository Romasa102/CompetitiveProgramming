#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,m,h,k;
    cin >> n >> m >> h >> k;
    ll score[n];
    rep(i,n)cin >> score[i];
    vector<P> query;//which row,then the height
    bool crossL[n][h+1];
    rep(i,n)rep(j,h)crossL[i][j]=false;
    rep(i,m){
        ll a,b;
        cin >> a >> b;a--;//a is a index
        query.push_back({a,b});
        crossL[a][b]=true;
    }
    ll dpFTop[n][h+1];
    ll dpFBottom[n][h+1];
    vector<ll>curIndex;
    rep(i,n)curIndex.push_back(i);
    rep(i,h+1){
        rep(j,n)if(crossL[j][i])swap(curIndex[j],curIndex[j+1]);
        rep(j,n)dpFTop[j][i]=curIndex[j];
    }
    vector<ll>curN;
    rep(i,n)curN.push_back(score[i]);
    for(ll i = h;i >=0; i--){
        rep(j,n)if(crossL[j][i])swap(curN[j],curN[j+1]);
        rep(j,n)dpFBottom[j][i]=curN[j];
    }
    ll op=0;
    rep(i,k){
        op+=dpFBottom[0][i];
    }
    ll ans = op;
    rep(i,m){
        ll depth = query.back().second;
        ll row = query.back().first;
        query.pop_back();
        ll cash = 0;
        rep(j,n){//row
            if(j==row){
                if(dpFTop[j+1][depth]<k){
                    cash += dpFBottom[j+1][depth];
                }
                continue;
            }
            if(j==row+1){
                if(dpFTop[j-1][depth]<k) {
                    cash += dpFBottom[j-1][depth];
                }
                continue;
            }
            if(dpFTop[j][depth]>=k)continue;
            cash += dpFBottom[j][depth];
        }
        ans = min(ans,cash);
    }
    cout << ans << endl;
}