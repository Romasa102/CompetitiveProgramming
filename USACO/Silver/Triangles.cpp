#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);
    ll N;cin>>N;
    vector<P>xy(N);rep(i,N){
        cin >> xy[i].first >> xy[i].second;
    }
    map<ll,vector<ll>> X;
    map<ll,vector<ll>> Y;
    rep(i,N){
        X[xy[i].first].push_back(xy[i].second);
        Y[xy[i].second].push_back(xy[i].first);
    }
    ll ans = 0;
    map<P,P> xys;
    repp(i,-10100,10100){
        if(X.find(i)==X.end())continue;
        sort(X[i].begin(),X[i].end());
        ll cur = 0;
        for(ll j:X[i]){
            cur += j-X[i][0];
        }
        xys[{i,X[i][0]}].first=cur;
        ll change = -(X[i].size()-2);
        repp(j,1,X[i].size()){
            cur += change * (X[i][j]-X[i][j-1]);
            change++;change++;
            xys[{i,X[i][j]}].first=cur;
        }
    }

    repp(i,-10100,10100){
        if(Y.find(i)==Y.end())continue;
        sort(Y[i].begin(),Y[i].end());
        ll cur = 0;
        for(ll j:Y[i]){
            cur += j-Y[i][0];
        }
        xys[{Y[i][0],i}].second=cur;
        ll change = -(Y[i].size()-2);
        repp(j,1,Y[i].size()){
            cur += change * (Y[i][j]-Y[i][j-1]);
            change++;change++;
            xys[{Y[i][j],i}].second=cur;
        }
    }
    rep(i,N){
        ans += xys[xy[i]].first*xys[xy[i]].second;
        ans %= 1000000007;
    }
    cout << ans << endl;
}