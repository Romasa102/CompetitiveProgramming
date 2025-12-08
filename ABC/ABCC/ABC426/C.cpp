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
    deque<P> temp;
    ll cur = 1;
    rep(i,Q){
        cin >> X[i] >> Y[i];
        ll ans = 0;
        if(cur <= X[i]){
            ans+=(X[i]-cur+1);
            cur = X[i]+1;
        }
        while(!temp.empty() &&temp.front().first <= X[i]){
            ans+=temp.front().second;
            temp.pop_front();
        }
        temp.push_back({Y[i],ans});
        sort(temp.begin(),temp.end());
        cout << ans << endl;
    }
}
