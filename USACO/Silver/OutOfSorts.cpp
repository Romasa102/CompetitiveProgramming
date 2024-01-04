#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    ll N;cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    vector<ll> B = A;
    sort(B.begin(),B.end());
    map<ll,ll> pos;
    rep(i,N){
        pos[B[i]]=i;
    }
    ll ans = 0;
    rep(i,N){
        ans = max(ans,i-pos[A[i]]+1);
    }
    cout << ans << endl;
}