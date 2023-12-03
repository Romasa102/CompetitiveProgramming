#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,L;
    cin >> N >> M >> L;
    ll a[N],b[M];
    rep(i,N)cin >> a[i];
    rep(i,M)cin >> b[i];
    vector<P> sortA;
    vector<P> sortB;
    rep(i,N)sortA.push_back({a[i],i});
    rep(i,M)sortB.push_back({b[i],i});
    sort(sortA.begin(),sortA.end(),greater<P>());
    sort(sortB.begin(),sortB.end(),greater<P>());
    map<P,bool> badP;
    rep(i,L){
        ll c,d;
        cin >> c >> d;
        badP[{c-1,d-1}]=true;
    }
    ll ans = 0;
    rep(i,N){
        rep(j,M){
            if(badP.find({sortA[i].second,sortB[j].second})==badP.end()){
                ans = max(ans,(sortA[i].first+sortB[j].first));
                break;
            }
        }
    }
    cout << ans << endl;
}