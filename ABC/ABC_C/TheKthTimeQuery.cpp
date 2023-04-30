#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    ll a[N];
    rep(i,N){
        cin >> a[i];
    }
    P b[Q];
    rep(i,Q){
        cin >> b[i].first >> b[i].second;
    }
    map<ll, vector<int>> mp;
    ll maxN = 1;
    rep(i,N){
        mp[a[i]].push_back(i);
    }
    rep(i,Q){
        if(mp[b[i].first].size() >= b[i].second){
            cout << mp[b[i].first][b[i].second - 1] + 1 << endl;
        }else{
            cout << -1 << endl;
        }
    }
}