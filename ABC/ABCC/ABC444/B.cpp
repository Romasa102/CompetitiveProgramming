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
ll getKetawa(ll x){
    ll ans = 0;
    ll k = x;
    while(k>0){
        ans+=k%10;
        k/=10;
    }
    return ans;
}
int main(){
    ll N,K;cin >> N >> K;

    ll ans = 0;
    repp(i,1,N+1){
        if(getKetawa(i)==K){
            ans++;
        }
    }
    cout << ans << endl;
}