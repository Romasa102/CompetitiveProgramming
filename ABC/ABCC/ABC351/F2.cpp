//F.cpp but upgraded to fenwick tree usng Gemini
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

// WARNING: 1LL<<28 is approx 268 million. This requires ~4GB RAM. 
// If specific values of A[i] are small, reduce this to MAX_A + 1.
ll segTS = 1LL<<28; 

// Fenwick Tree (BIT) vector
vector<P> bit(segTS + 1, {0,0}); 

// Internal helper: Get prefix sum from index 0 to idx
P query(ll idx) {
    idx++; // Convert 0-based input to 1-based BIT index
    P res = {0, 0};
    while(idx > 0) {
        res.first += bit[idx].first;
        res.second += bit[idx].second;
        idx -= idx & -idx;
    }
    return res;
}

// Update function
void update(ll pos){
    ll val = pos;
    pos++; // Convert 0-based input to 1-based BIT index
    while(pos <= segTS){
        bit[pos].first += val;
        bit[pos].second++;
        pos += pos & -pos;
    }
}

// Range Sum function (Prefix(r) - Prefix(l-1))
// Removed recursive arguments (st, en, node) as they are not needed for BIT
P getSum(ll l, ll r){
    if(l > r) return {0, 0};
    P rightS = query(r);
    P leftS = query(l - 1);
    return {rightS.first - leftS.first, rightS.second - leftS.second};
}

int main(){
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    cin >> N;
    // Using vector instead of VLA for safety with large N, though original used array
    vector<ll> A(N); 
    rep(i,N) cin >> A[i];
    
    update(A[N-1]);
    ll ans = 0;
    for(ll i = N-2;i>=0;i--){
        // Logic remains exactly the same
        P cur = getSum(A[i],segTS-1);
        ans+=cur.first-cur.second*A[i];
        update(A[i]);
    }
    cout << ans << endl;
}