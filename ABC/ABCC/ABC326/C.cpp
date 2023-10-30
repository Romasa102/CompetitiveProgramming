#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    vector<ll> A;
    cin >> N >> M;
    rep(i,N){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    ll ans = 0;
    rep(i,N){
        if(M >= *(upper_bound(A.begin(), A.end(),A[i]+M)-1)-A[i]){
            ll cash = (lower_bound(A.begin(), A.end(),A[i]+M))- (lower_bound(A.begin(),A.end(),A[i]));
            ans = max(ans,cash);
            //cout << A[i] << "    "  << (lower_bound(A.begin(),A.end(),A[i]+M)-A.begin())  << "     "<< ans << endl;
        }
    }
    cout << ans << endl;
}