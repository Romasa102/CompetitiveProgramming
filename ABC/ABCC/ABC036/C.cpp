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
    vector<ll> arf(N);
    rep(i,N)arf[i]=a[i];
    sort(arf.begin(),arf.end());
    arf.resize(unique(arf.begin(),arf.end())-arf.begin());
    map<ll,ll> ind;
    rep(i,arf.size()){
        ind[arf[i]]=i;
    }
    rep(i,N)cout << ind[a[i]] << endl;
}