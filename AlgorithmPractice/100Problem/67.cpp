#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
using PairP = pair<P,P>;
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
    vector<pair<ll,PairP>> connection;
    rep(i,N-1){
        ll minCX = min(abs(xAxis[i].first - xAxis[i+1].first),abs(city[xAxis[i].second].second-city[xAxis[i+1].second].second));
        connection.push_back({minCX, {{xAxis[i + 1].first, city[xAxis[i + 1].second].second}, {xAxis[i].first, city[xAxis[i].second].second}}});
        ll minCY = min(abs(yAxis[i].first - yAxis[i+1].first),abs(city[yAxis[i].second].first-city[yAxis[i+1].second].first));
        connection.push_back({minCY, {{city[yAxis[i + 1].second].first,yAxis[i + 1].first}, {city[yAxis[i].second].first,yAxis[i].first}}});
    }
    sort(connection.begin(),connection.end());
    ll ans = 0;
    rep(i,connection.size()){
        if(find(connection[i].second.first) != find(connection[i].second.second)){
            Union(connection[i].second.first,connection[i].second.second);
            ans += connection[i].first;
        }
    }cout << ans << endl;
}