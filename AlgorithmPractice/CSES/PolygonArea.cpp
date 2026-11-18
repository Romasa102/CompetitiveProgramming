#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n;
    cin >> n;
    vector<ll> x(n),y(n);
    rep(i,n)cin >> x[i] >> y[i];
    x.push_back(x[0]);
    y.push_back(y[0]);
    ll area = 0;
    rep(i,n){
        area += x[i] * y[i+1] - y[i] * x[i+1];
    }
    cout << abs(area) << endl;
}