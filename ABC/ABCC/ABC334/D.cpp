#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    ll R[N];
    rep(i,N)cin >> R[i];
    sort(R,R+N);
    vector<ll> total(N+1);
    total[0]=0;
    rep(i,N){
        total[i+1]=total[i]+R[i];
    }
    rep(i,Q){
        ll que = 0;
        cin >> que;
        cout << (upper_bound(total.begin(),total.end(),que)-total.begin())-1 << endl;
    }
}