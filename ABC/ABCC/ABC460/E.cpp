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
const ll MOD = 998244353;
int main(){
    ll T;
    cin >> T;
    rep(_,T){
        ll N,M;cin >> N >> M;
        vector<ll> ch;
        ll cur = 1;
        ll ans = 0;
        rep(i,19){
            if(N<cur)break;
            ll numV = (cur*10%MOD) - (cur%MOD);
            if(cur <= N && cur > N/10){
                numV = N-cur+1;
            }
            numV%=MOD;
            if(((cur%M)*10-1)%M==0){
                ans+=(N%MOD)*(numV%MOD);
                ans%=MOD;
            }else{
                ll gd = M/gcd(cur%M*10-1,M);
                ans+=((N/gd)%MOD)*(numV%MOD);
                ans%=MOD;
            }
            cur *= 10;
        }
        cout << ans << endl;
    }
}