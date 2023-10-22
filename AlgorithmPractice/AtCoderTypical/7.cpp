#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N)cin >> A[i];
    sort(A,A+N);
    ll Q;
    cin >> Q;
    ll B[Q];
    rep(i,Q){
        cin >>  B[i];
        ll a = *upper_bound(A,A+N,B[i]);
        ll b = *(upper_bound(A,A+N,B[i])-1);
        if(a==A[0]){
            b=1LL<<32;
        }
        cout << min(abs(a-B[i]),abs(b-B[i])) << endl;
    }
}