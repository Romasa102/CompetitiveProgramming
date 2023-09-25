#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,P;
    cin >> N >> M >> P;
    vector<ll> A(N);
    vector<ll> B(M);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,M){
        cin >> B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector<ll> AcumS(N+1);
    vector<ll> BcumS(M+1);
    AcumS[0] = 0;
    repp(i,1,A.size()+1){
        AcumS[i] = AcumS[i-1] + A[i-1];
    }
    BcumS[0] = 0;
    repp(i,1,B.size()+1){
        BcumS[i] = BcumS[i-1] + B[i-1];
    }
    ll ans = 0;
    rep(i,A.size()){
        ll findV = P-A[i];
        auto it = upper_bound(B.begin(),B.end(),findV);
        ll ind = it-B.begin();
        ans += (B.size()-ind) * P;
        ans += AcumS[ind];
    }
    cout << ans << endl;
}