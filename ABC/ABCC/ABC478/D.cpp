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


int N, Q;
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main(){
    map<ll,vector<P>> rngs;
    ll N,Q;
    cin >> N >> Q;
    ll L[Q],R[Q],X[Q];
    rep(i,Q){
        cin >> L[i] >> R[i] >> X[i];
        rngs[X[i]].push_back({L[i],R[i]});
    }
    vector<P> finRag;
    for(auto i : rngs){
        vector<P> rng = i.second;
        sort(rng.begin(),rng.end());
        ll curB = rng[0].first, maxE = rng[0].second;
        repp(j,1,rng.size()){
            if(rng[j].first > maxE){
                finRag.push_back({curB,maxE});
                curB = rng[j].first;
                maxE = rng[j].second;
            } else {
                maxE = max(maxE, rng[j].second);
            }
        }
        finRag.push_back({curB,maxE});
    }
    LazySegmentTree lazSeg(vector<ll>(N,0));
    rep(i,finRag.size()){
        lazSeg.add(finRag[i].first-1,finRag[i].second,1);
    }
    rep(i,N){
        cout << lazSeg.getsum(i,i+1) << " ";
    }cout << endl;

}