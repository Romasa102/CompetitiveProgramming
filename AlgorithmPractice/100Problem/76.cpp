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
    rep(i,N){
        cin >> A[i];
    }
    ll Csum[N+1];
    Csum[0] = 0;
    Csum[1] = A[0];
    repp(i,2,N+1){
        Csum[i] = Csum[i-1] + A[i-1];
    }
    repp(i,1,N+1){
        ll currentMax = 0;
        rep(j,N-i+1){
            currentMax = max(currentMax,Csum[i+j]-Csum[j]);
        }
        cout << currentMax << endl;
    }
}