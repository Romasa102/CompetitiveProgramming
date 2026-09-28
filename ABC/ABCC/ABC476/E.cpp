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
struct SegTree {
    int n, N;
    vector<P> mn, mx; //min Vec; max Vec

    SegTree(int n) : n(n) {
        N = 1;
        while(N < n) {
            N *= 2;
        }

        mn.assign(2 * N, {1LL<<40, 0});
        mx.assign(2 * N, {0, 0});
    }

    void build(vector<ll>& a, int v, int l, int r) {
        if (l == r) {
            if (l < n) {
                mn[v] = mx[v] = {a[l], l};
            }
            return;
        }

        int m = (l + r) / 2;
        build(a, v * 2, l, m);
        build(a, v * 2 + 1, m + 1, r);

        if (mn[v * 2].first < mn[v * 2 + 1].first) {
            mn[v] = mn[v * 2];
        } else {
            mn[v] = mn[v * 2 + 1];
        }

        if (mx[v * 2].first > mx[v * 2 + 1].first) {
            mx[v] = mx[v * 2];
        } else {
            mx[v] = mx[v * 2 + 1];
        }
    }

    void build(vector<ll>& a) {
        build(a, 1, 0, N - 1);
    }

    void update(int pos, ll val, int v, int l, int r) {
        if (l == r) {
            mn[v] = mx[v] = {val, l};
            return;
        }

        int m = (l + r) / 2;

        if (pos <= m) {
            update(pos, val, v * 2, l, m);
        } else {
            update(pos, val, v * 2 + 1, m + 1, r);
        }

        if (mn[v * 2].first < mn[v * 2 + 1].first) {
            mn[v] = mn[v * 2];
        } else {
            mn[v] = mn[v * 2 + 1];
        }

        if (mx[v * 2].first > mx[v * 2 + 1].first) {
            mx[v] = mx[v * 2];
        } else {
            mx[v] = mx[v * 2 + 1];
        }
    }

    void update(int pos, ll val) {
        update(pos, val, 1, 0, N - 1);
    }

    pair<P,P> query(int ql, int qr, int v, int l, int r) {
        if (qr < l || r < ql) {
            return {{1LL<<40, 0}, {0, 0}};
        }

        if (ql <= l && r <= qr) {
            return {mn[v], mx[v]};
        }

        int m = (l + r) / 2;

        auto left = query(ql, qr, v * 2, l, m);
        auto right = query(ql, qr, v * 2 + 1, m + 1, r);

        P minV;
        P maxV;

        if (left.first.first > right.first.first) {
            minV = right.first;
        } else {
            minV = left.first;
        }

        if (left.second.first > right.second.first) {
            maxV = left.second;
        } else {
            maxV = right.second;
        }

        return {minV, maxV};
    }

    pair<P,P> query(int l, int r) {
        return query(l, r, 1, 0, N - 1);
    }
};

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> P(N);rep(i,N)cin >> P[i];
    ll L[M],R[M];
    SegTree s = SegTree(N);
    s.build(P);

    rep(i,N){
        cout << s.mn[s.N+i].first << " ";
    }cout << endl;
    rep(i,M){
        cin >> L[i] >> R[i];
        auto val = s.query(L[i]-1,R[i]-1); //minV, ind, maxV , ind
        ll minV = val.first.first;
        s.update(val.first.second,val.second.first);
        s.update(val.second.second,val.first.first);
    }

    rep(i,N){
        cout << s.mn[s.N+i].first << " ";
    }cout << endl;
}