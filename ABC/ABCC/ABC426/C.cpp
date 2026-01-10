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
    ll N,Q;
    cin >> N >> Q;
    ll X[Q],Y[Q];
    ll ver[N];
    rep(i,N)ver[i]=1;
    ll cur = 0;
    rep(i,Q){
        cin >> X[i] >> Y[i];
        ll ans = 0;
        if(cur > X[i]-1){
            cout << 0 << endl;
            continue;
        }
        while(cur <= X[i]-1){
            ans+=ver[cur];
            cur++;
        }
        //sort(temp.begin(),temp.end());
        cout << ans << endl;
        ver[Y[i]-1]+=ans;
    }
}
