#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin >> N;
    vector<ll> Q(N);rep(i,N)cin >> Q[i];
    ll A[N],B[N];rep(i,N)cin >> A[i];rep(i,N)cin >> B[i];
    ll ans = 0;
    rep(i,1001000){
        vector<ll> O = Q;
        bool work = true;
        rep(j,N){
            if(O[j] < A[j] * i){
                work = false;
                break;
            }
            O[j]-=A[j]*i;
        }
        if(!work)continue;
        ll maxB = 1LL<<60;
        rep(j,N){
            if(B[j]==0)continue;
            maxB = min(maxB,O[j]/B[j]);
        }
        ans = max(ans, i + maxB);
    }
    cout << ans << endl;
}