#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    ll N,K;cin >> N >> K;
    vector<ll> a(N);rep(i,N)cin >> a[i];
    sort(a.begin(),a.end());
    ll ans = 0;
    ll MN[N];
    for(auto i = a.begin(); i != a.end(); i++){
        MN[i-a.begin()] = max(ans,(ll)(upper_bound(a.begin(),a.end(),*i+K)-i));
    }
    vector<ll> prev(N+1,0);
    prev[N]=0;
    for(ll i = N-1;i>=0;i--){
        prev[i]=max(prev[i+1],MN[i]);
    }
    rep(i,N){
        if(i+MN[i]>N)continue;
        ans = max(ans,MN[i]+prev[i+MN[i]]);
    }
    cout << ans << endl;
}