#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll A,B;
    cin >> A >> B;
    ll ans = 1;
    rep(i,B){
        ans*=A;
    }
    cout << ans << endl;
}