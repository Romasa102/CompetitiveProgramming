#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
bool solve(ll a, ll b, ll c, ll &x, ll &y) {
    ll g = extended_gcd(abs(a), abs(b), x, y);
    if (c % g != 0) {
        return false;
    }
    a /= g;
    b /= g;
    c /= g;
    extended_gcd(a, b, x, y);
    x *= c;
    y *= c;
    if (x > 0 && x < g && y > 0 && y < g) {
        return true;
    }
    return false;
}
int main(){
    ll X,Y;cin >> X >> Y;
    ll a,b;
    if(solve(X,Y,X*Y+2,a,b)){
        cout << a << " " << b << endl;
    }else{
        cout << -1 << endl;
    }
}