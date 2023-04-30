#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    set<ll> A;
    rep(i,N){
        ll k;
        cin >> k;
        A.insert(k);
    }
    cout << A.size() << endl;
}