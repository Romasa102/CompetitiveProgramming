#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

const ll MOD = 1000000007;

ll mod_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

ll mod_inverse(ll num) {
    return mod_pow(num, MOD - 2);
}

int main(){
    ll X, Y;
    cin >> X >> Y;

    if ((2 * X - Y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    ll A = (2 * X - Y) / 3;
    ll B = X - 2 * A;

    ll up = 1;
    ll down = 1;

    for (ll i = 1; i <= A; ++i) {
        up = (up * (A + B - i + 1)) % MOD;
        down = (down * i) % MOD;
    }

    ll combination = (up * mod_inverse(down)) % MOD;
    cout << combination << endl;

    return 0;
}