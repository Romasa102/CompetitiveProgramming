#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<P,P> parent;
P find(P child){
    if(parent[child] == child)return child;
    return parent[child] = find(parent[child]);
}
void Union(P a,P b){
    parent[find(a)] = find(b);
}
int main(){
    ll N;
    cin >> N;
    P city[N];
    vector<P> xAxis(N);
    vector<P> yAxis(N);
    rep(i,N){
        cin >> city[i].first >> city[i].second;
        parent[city[i]] = city[i];
        xAxis[i].first = city[i].first;
        xAxis[i].second = i;
        yAxis[i].first = city[i].second;
        yAxis[i].second = i;
    }
    sort(xAxis.begin(),xAxis.end());
    sort(yAxis.begin(),yAxis.end());
    map<ll,vector<P>> connection;
    rep(i,N-1){
        connection[xAxis[i].second].push_back({xAxis[i+1].second,min(abs(xAxis[i].first - xAxis[i+1].first),abs(city[xAxis[i].second].first-city[xAxis[i+1].second].first))});
        connection[xAxis[i+1].second].push_back({xAxis[i].second,min(abs(xAxis[i].first - xAxis[i+1].first),abs(city[xAxis[i].second].first-city[xAxis[i+1].second].first))});
        connection[yAxis[i].second].push_back({yAxis[i+1].second,min(abs(yAxis[i].first - yAxis[i+1].first),abs(city[yAxis[i].second].second-city[yAxis[i+1].second].second))});
        connection[yAxis[i+1].second].push_back({yAxis[i].second,min(abs(yAxis[i].first - yAxis[i+1].first),abs(city[yAxis[i].second].second-city[yAxis[i+1].second].second))});
    }
    
}