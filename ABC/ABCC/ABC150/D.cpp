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
ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll LCM(ll a, ll b) {
    ll d = GCD(a, b);
    return a / d * b;
}
int main(){
    ll N,M;
    cin >> N >> M;
    set<ll> s;
    rep(i,N){
        ll val;
        cin >> val;
        s.insert(val);
    }
    vector<ll> a;
    a.assign(s.begin(), s.end());
    ll gcdT = a[0];
    repp(i,1,a.size())gcdT = GCD(gcdT,a[i]);
    ll lcmT = a[0]/gcdT;
    repp(i,1,a.size()-1)lcmT = LCM(lcmT,a[i]/gcdT);
    double lcmTD = lcmT;
    //rep(i,a.size())cout << a[i] << " ";
    //cout << endl;
    M/=a[a.size()-1];
    //cout << M << " " << lcmTD << endl;
    if(M<lcmTD){
        cout << 0 << endl;
        return 0;
    }
    cout << (ll)ceil(((double)M)/(lcmTD)) << endl;
    //cout << M <<  " " << gcdT << " " << lcmTD << endl;
}