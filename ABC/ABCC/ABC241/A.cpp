#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll a[10];
    rep(i,10){
        cin >> a[i];
    }
    ll now = 0;
    rep(i,3){
        a[now] = now;
    }
    cout << now << endl;
}