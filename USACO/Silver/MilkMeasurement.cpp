#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    ll N,G;cin>>N>>G;
    pair<ll,P> a[N];//day, id, change
    rep(i,N){
        cin>>a[i].first>>a[i].second.first>>a[i].second.second;
    }
    sort(a,a+N);
    map<ll,ll> cow;//index,production
    map<ll,ll> milk;//production,number of cow
    rep(i,N)cow[a[i].second.first]=G;
    milk[G]=cow.size()+1000;
    ll ans = 0;
    rep(i,N){
        ll initialN = cow[a[i].second.first];//initial value of the cow's production
        ll oldTcount = milk.rbegin()->second;
        bool wasTop = milk.rbegin()->first == initialN;
        ll changes = a[i].second.second;//change that'll occur
        cow[a[i].second.first]=initialN+changes;
        milk[initialN]--;
        if(milk[initialN]==0){
            milk.erase(initialN);
        }
        milk[initialN+changes]++;
        bool isTop = milk.rbegin()->first==(initialN+changes);
        if(wasTop){
            if(isTop && oldTcount==milk.rbegin()->second)continue;
            ans++;
        }else if(isTop){
            ans++;
        }
    }
    cout << ans << endl;
}