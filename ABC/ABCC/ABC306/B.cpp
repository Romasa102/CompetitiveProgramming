#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll A[64];
    rep(i,64){
        cin >> A[i];
    }
    ll ans = 0;
    rep(i,64){
        if(A[i] == 1){
            ans += pow(2,i);
        }
    }
    cout << ans << endl;
}