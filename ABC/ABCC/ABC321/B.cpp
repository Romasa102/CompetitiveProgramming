#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,X;
    cin >> N >> X;
    ll A[N];
    ll sum = 0;
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    sort(A,A+N);
    if(sum - A[N-1] - A[0] >= X){
        cout << 0 << endl;
        return 0;
    }
    ll ans = X - (sum - A[N-1] - A[0]);
    if(ans <= A[0]){
        cout << 0 << endl;
        return  0;
    }
    if(ans <= A[N-1]){
        cout << ans << endl;
        return 0;
    }
    cout << -1  << endl;
    return 0;
}