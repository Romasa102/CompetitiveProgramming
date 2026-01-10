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
int main(){
    ll N;
    cin >> N;
    ll a[N];
    rep(i,N)cin >> a[i];
    sort(a,a+N,greater<ll>());
    ll ans = 0;
    rep(i,N/2+1){
        if(i*2==N)continue;
        if((i*2+1)<N){
            ans+=a[i*2]-a[i*2+1];
        }else{
            ans+=a[i*2];
        }
    }
    cout << ans << endl;
}
