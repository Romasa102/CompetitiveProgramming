#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll N,T;
vector<ll> A(N);
int main(){
    cin >> N >> T;
    ll minN = 1LL<<50;
    A.resize(N);
    rep(i,N){
        cin >> A[i];
        minN = min(minN,A[i]);
    }
    rep(i,N){
        A[i] = (A[i]-minN)%T;
    }
    unique(A.begin(), A.end());

    sort(A.begin(),A.end());
    ll ans = A[A.size()-1];
    repp(i,1,A.size()){
        ans = min(ans, A[i-1]-(A[i]-T));
    }
    cout << (ans+1)/2 << endl;
}
