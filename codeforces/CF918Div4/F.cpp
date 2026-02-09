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
    ll t;cin >> t;

    while(t--){
        ll n;
        cin >> n;
        P ab[n];
        rep(i,n)cin >> ab[i].first >> ab[i].second;
        vector<ll> st;
        sort(ab,ab+n);
        sort(st.begin(),st.end());
        st.push_back(ab[0].second);
        ll ans = 0;
        repp(i,1,n){
            ans+=(st.end()-lower_bound(st.begin(),st.end(),ab[i].second));
            st.push_back(ab[i].second);
            sort(st.begin(),st.end());
        }
        cout << ans << endl;
    }
}