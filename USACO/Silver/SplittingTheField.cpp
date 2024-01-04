#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
bool compareS(P a,P b){
    return a.second<b.second;
}
int main(){
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    ll N;cin >> N;
    vector<P> xy(N);rep(i,N)cin >> xy[i].first >> xy[i].second;
    ll maxX = 0,minX = 1LL<<60,minY = 1LL<<60,maxY = 0;
    rep(i,N){
        maxX = max(maxX,xy[i].first);
        minX = min(minX,xy[i].first);
        minY = min(minY,xy[i].second);
        maxY = max(maxY,xy[i].second);
    }
    ll initialS = (maxX-minX)*(maxY-minY);
    sort(xy.begin(),xy.end());
    vector<ll> TotalMY(N+1,0);
    vector<ll> TotalmY(N+1,1LL<<60);
    vector<ll> RTotalMY(N+1,0);
    vector<ll> RTotalmY(N+1,1LL<<60);
    repp(i,1,N){
        TotalMY[i]=max(TotalMY[i-1],xy[i-1].second);
        TotalmY[i]=min(TotalmY[i-1],xy[i-1].second);
    }
    for(ll i = N-1; i>=0; i--){
        RTotalMY[i] = max(RTotalMY[i+1],xy[i].second);
        RTotalmY[i] = min(RTotalmY[i+1],xy[i].second);
    }
    ll ans = initialS;
    repp(i,1,N){
        if(xy[i-1].first==xy[i].first&&TotalMY[i]>=RTotalmY[i]){
            continue;
        }
        ans = min(ans,(TotalMY[i]-TotalmY[i])*(xy[i-1].first-xy[0].first) + (RTotalMY[i]-RTotalmY[i])*(xy[N-1].first-xy[i].first));
    }
    sort(xy.begin(),xy.end(),compareS);
    vector<ll> TotalMX(N+1,0);
    vector<ll> TotalmX(N+1,1LL<<60);
    vector<ll> RTotalMX(N+1,0);
    vector<ll> RTotalmX(N+1,1LL<<60);
    repp(i,1,N){
        TotalMX[i]=max(TotalMX[i-1],xy[i-1].first);
        TotalmX[i]=min(TotalmX[i-1],xy[i-1].first);
    }
    for(ll i = N-1; i>=0; i--){
        RTotalMX[i] = max(RTotalMX[i+1],xy[i].first);
        RTotalmX[i] = min(RTotalmX[i+1],xy[i].first);
    }
    repp(i,1,N){
        if(xy[i-1].second==xy[i].second&&TotalMX[i]>=RTotalmX[i]){
            continue;
        }
        ans = min(ans,(TotalMX[i]-TotalmX[i])*(xy[i-1].second-xy[0].second) + (RTotalMX[i]-RTotalmX[i])*(xy[N-1].second-xy[i].second));
    }
    cout << initialS - ans << endl;
}