#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define revrep(i,n) for(ll i = n-1; i >= (0); --i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    vector<P> XA(M);
    rep(i,M)cin >> XA[i].first;//pos
    rep(i,M)cin >> XA[i].second;//amount
    ll ans = 0;ll end = N;
    sort(XA.begin(),XA.end());
    revrep(i,M){
        if(XA[i].second>(end-XA[i].first+1)){
            cout<<-1<<endl;
            return 0;
        }
        ans += (end - XA[i].first)*XA[i].second - (XA[i].second*(XA[i].second-1))/2;//((end - XA[i].first)+max(0LL,(end - XA[i].second)-XA[i].first) * (end-XA[i].first+1) /2);
        end-=XA[i].second;
    }
    if(end!=1){
        cout<<-1<<endl;
        return 0;
    }
    cout << ans << endl;
}