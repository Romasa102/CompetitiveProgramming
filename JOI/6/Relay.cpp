#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
bool compare(P a, P b) {
    return a.second < b.second;
}
int main(){
    ll N;
    cin >> N;
    vector<P> AB(N);
    vector<P> TOTALB(N);
    rep(i,N){
        cin >> AB[i].first >> AB[i].second;
        TOTALB[i].first = AB[i].second;
        TOTALB[i].second = AB[i].first + AB[i].second;
    }
    sort(AB.begin(),AB.end(),compare);
    sort(TOTALB.begin(),TOTALB.end());
    vector<ll> minA(N,1LL<<50);
    vector<ll> minS(N,1LL<<50);
    repp(i,1,N){
        minA[i]=min(minA[i-1],AB[i-1].first);
    }
    for(ll i = N-2;i>=0;i--){
        minS[i]=min(minS[i+1],TOTALB[i+1].second);
    }
    ll ans =1LL<<50;
    repp(i,1,N-1){
        ans = min(ans,AB[i].first+AB[i].second+minA[i]+minS[i]);
    }
    cout << ans << endl;
}