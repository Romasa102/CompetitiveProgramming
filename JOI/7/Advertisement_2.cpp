#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    P XE[N];
    rep(i,N)cin>>XE[i].first>>XE[i].second;
    sort(XE,XE+N);
    P cumS[N+1];
    cumS[0].first=0;cumS[0].second=0;
    rep(i,N){
        cumS[i+1].first=cumS[i].first+XE[i].first;
        cumS[i+1].second=cumS[i].second+XE[i].second;
    }
    
}