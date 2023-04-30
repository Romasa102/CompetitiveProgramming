#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,K,X;
    cin >> N >> K >> X;
    ll A[N];
    ll sum = 0;
    ll ans = 0;
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    sort(A,A + N,greater<int>());
    ll C = 0;
    rep(i,N){
        C += A[i]/X;
        A[i]%=X;
    }
    ll surplus = 0;
    ll Z = 0;
    if(C >= K){
        ans = max(sum - (K*X),Z);
        cout << ans << endl;
    }else {
        sort(A,A+N,greater<int>());
        ll loop = min(N,K-C);
        rep(i,loop){
            surplus += A[i];
        }
        ans = max(sum - (C * X) -surplus,Z);
        cout << ans << endl;
    }
}