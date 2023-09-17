#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll a,b;
    cin >> a >> b;
    cout.setf(ios::fixed);
    cout << setprecision(0) << pow(a,b) + pow(b,a) << endl;
}