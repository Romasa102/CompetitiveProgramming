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
    vector<vector<ll>> cnt(N,vector<ll>());
    rep(i,N){
        ll k;
        cin >> k;
        ll a[k];
        rep(j,k){
            cin >> a[j];
            cnt[a[j]-1].push_back(i+1);
        }
    }
    rep(i,N){
        cout << cnt[i].size();
        rep(j,cnt[i].size()){
            cout << " " << cnt[i][j];
        }
        cout << endl;
    }
}