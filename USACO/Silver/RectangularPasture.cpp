#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
bool compare(P a,P b){
    return a.second<b.second;
}
int main(){
    ll N;
    cin >> N;
    P xy[N];
    vector<P> XAxis;
    vector<P> YAxis;
    rep(i,N){
        cin >> xy[i].first >> xy[i].second;
        XAxis.push_back({xy[i].first,i});
        YAxis.push_back({xy[i].second,i});
    }
    sort(XAxis.begin(),XAxis.end());
    sort(YAxis.begin(),YAxis.end());
    vector<P> Sxy(N,{0,0});
    rep(i,N){
        XAxis[i].first=i;
        YAxis[i].first=i;
    }
    sort(XAxis.begin(),XAxis.end(), compare);
    sort(YAxis.begin(),YAxis.end(), compare);
    rep(i,N)Sxy[i]={XAxis[i].first,YAxis[i].first};
    ll pSum[N+1][N+1];
    rep(i,N+1)rep(j,N+1)pSum[i][j]=0;
    rep(i,N){
        pSum[Sxy[i].first+1][Sxy[i].second+1]=1;
    }
    repp(i,1,N+1){
        repp(j,1,N+1){
            pSum[i][j]+=pSum[i-1][j]+pSum[i][j-1]-pSum[i-1][j-1];
        }
    }
    ll ans = 0;
    rep(i,N-1){
        repp(j,i+1,N){
            ll maxX = max(Sxy[i].first,Sxy[j].first)+1;
            ll minX = min(Sxy[i].first,Sxy[j].first)+1;
            ll maxY = max(Sxy[i].second,Sxy[j].second)+1;
            ll minY = min(Sxy[i].second,Sxy[j].second)+1;
            ll curS = pSum[maxX][N]+pSum[minX-1][maxY-1]-pSum[maxX][maxY-1]-pSum[minX-1][N];
            ll curS2 = pSum[maxX][minY]+pSum[minX-1][0]-pSum[minX][minY-1]-pSum[maxX][0];
            ans += curS * curS2;
        }
    }
    cout << ans + N + 1<< endl;
}