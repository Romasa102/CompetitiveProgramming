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
    ll N,L,R;
    cin >> N >> L >> R;
    string S;
    cin >> S;
    vector<vector<ll>> chars(26,vector<ll>());
    rep(i,N){
        chars[S[i]-'a'].push_back(i);
    }
    ll ans = 0;
    rep(i,26){
        rep(j,chars[i].size()){
            ans += (upper_bound(chars[i].begin(),chars[i].end(),chars[i][j]+R) - lower_bound(chars[i].begin(),chars[i].end(),chars[i][j]+L));
        }
    }
    cout << ans << endl;
}