#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll quick_pow10(int n)
{
    static ll pow10[19] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 
        1000000000, //10
        10000000000, 
        100000000000, 
        1000000000000,
        10000000000000,
        100000000000000,
        1000000000000000,
        10000000000000000,
        100000000000000000,
        1000000000000000000,
    };

    return pow10[n]; 
}
int main(){
    ll t;
    cin >> t;
    rep(_,t){
        ll a,n;
        cin >> a >> n;
        ll d[2];
        cin >> d[0] >> d[1];
        ll len = (a == 0) ? 1 : (ll)to_string(a).size();
        ll digitsOp1 = max(1LL, len - 1);
        ll digitsOp2 = min(18LL, len + 1);

        ll ans = 1LL<<60;
        for(ll digits = digitsOp1; digits <= digitsOp2; digits++){
            for(ll s = 0; s < (1LL << digits); s++){
                ll sum = 0;
                for(ll i = 0; i < digits; i++){
                    if((s >> i) & 1){
                        sum += d[0] * quick_pow10(i);
                    }else{
                        sum += d[1] * quick_pow10(i);
                    }
                }
                ans = min(ans,llabs(a-sum));
            }
        }
        cout << ans <<endl;
    }
}