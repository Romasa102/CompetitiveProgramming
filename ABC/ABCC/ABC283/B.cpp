#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N){
        cin >> A[i];
    }
    ll Q;
    cin >> Q;
    rep(i,Q){
        ll P,k;
        cin >> P >> k;
        if(P == 1){
            ll x;
            cin >> x;
            A[k-1] == x;
        }else if(P == 2){
            cout << A[k-1] << endl;
        }
    }
}