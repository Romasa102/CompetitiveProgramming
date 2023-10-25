#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}
int main(){
    ll A,B,C;
    cin >> A >> B >> C;
    ll D = gcd(C,gcd(A,B));
    cout << A/D-1+B/D-1+C/D-1 << endl;
}