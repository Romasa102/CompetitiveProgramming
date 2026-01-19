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
struct BIT {
    private:
    vector<ll> bit;
    ll N;

    public:
    BIT(ll size) {
        N = size;
        bit.resize(N + 1);
    }
    void add(ll a, ll w) {
        for (ll x = a; x <= N; x += x & -x) bit[x] += w;
    }
    ll sum(ll a) {
        ll ret = 0;
        for (ll x = a; x > 0; x -= x & -x) ret += bit[x];
        return ret;
    }
};
int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll AbigB[N+1];
    AbigB[0]=0;
    ll minV = 0;
    BIT bit(N+10);
    rep(i,N){
        if(S[i] == 'A')AbigB[i+1]=AbigB[i]+1;
        if(S[i] == 'B')AbigB[i+1]=AbigB[i]-1;
        if(S[i] == 'C')AbigB[i+1]=AbigB[i];
        minV = min(AbigB[i+1],minV);
    }
    rep(i,N+1)AbigB[i]-=(minV-1);
    ll ans = 0;
    rep(i,N+1){
        ans += bit.sum(AbigB[i]-1);
        bit.add(AbigB[i],1);
    }
    cout << ans << endl;
}