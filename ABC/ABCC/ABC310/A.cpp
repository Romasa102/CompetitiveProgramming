#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,P,Q;
    cin >> N >> P >> Q;
    ll minim = 1000000;
    rep(i,N){
        ll a;
        cin >> a;
        minim = min(minim,a);
    }
    cout << min(minim+Q,P) << endl;
}