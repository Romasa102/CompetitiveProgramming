#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);
    ll N;
    cin >> N;
    ll M=0;
    ll x[N],y[N];
    deque<P> pq;
    rep(i,N){
        cin >> x[i] >> y[i];
        M+=x[i];
        pq.push_back({y[i],x[i]});
    }
    sort(pq.begin(),pq.end());
    ll ans =0;
    while(!pq.empty()){
        P F = pq.front();P B = pq.back();
        if(F==B){
            ans = max(ans,F.first*2);
            pq.pop_front();
            continue;
        }
        ans = max(ans,F.first+B.first);
        if(F.second==B.second){
            pq.pop_back();
            pq.pop_front();
        }else if(F.second>B.second){
            pq.front().second-=B.second;
            pq.pop_back();
        }else{
            pq.back().second-=F.second;
            pq.pop_front();
        }
    }
    cout << ans << endl;
}